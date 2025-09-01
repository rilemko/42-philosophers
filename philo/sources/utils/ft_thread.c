/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:18:02 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_thread(void *arg)
{
	t_phl	*phl;
	t_app	*app;

	phl = (t_phl *) arg;
	app = (t_app *) phl->app;
	while (ft_time(0, 0) < app->time)
		usleep(200);
	phl->die_at = ft_time(app->time_to_die, 0);
	while (ft_thread_run(app, phl) > 0)
	{
		ft_philo_think(app, phl);
		if (app->count > 1)
		{
			ft_philo_eat(app, phl, phl->phl_next);
			ft_philo_sleep(app, phl);
		}
	}
	return (0);
}

int	ft_thread_run(t_app *app, t_phl *phl)
{
	int	index;

	pthread_mutex_lock(&app->mutex);
	if (app->run == 0 || ft_philo_is_alive(phl) == 0)
	{
		pthread_mutex_unlock(&app->mutex);
		ft_philo_die(app, phl);
		return (0);
	}
	pthread_mutex_unlock(&app->mutex);
	if (app->must_eat == -1)
		return (1);
	index = -1;
	while (++index < app->count)
		if (app->phl[index]->count < app->must_eat)
			return (1);
	pthread_mutex_lock(&app->mutex);
	app->run = 0;
	pthread_mutex_unlock(&app->mutex);
	return (0);
}
