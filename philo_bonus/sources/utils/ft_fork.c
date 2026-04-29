/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:18:02 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_fork_thread(void *arg);

void	ft_fork(t_phl *phl)
{
	t_app		*app;
	pthread_t	thread;

	app = (t_app *) phl->app;
	if (app->must_eat > 0)
		ft_sem_wait(app->sem_eat, app->must_eat);
	ft_sem_wait(app->sem_run, 1);
	ft_sem_wait(app->sem_die, 1);
	if (pthread_create(&thread, NULL, ft_fork_thread, app))
		return (ft_exit_failure(app, "Failed to create thread.", 1));
	app->run = 1;
	while (ft_time(0, 0) < app->time)
		usleep(200);
	phl->die_at = ft_time(app->time_to_die, 0);
	while (ft_fork_run(app, phl))
	{
		ft_philo_think(app, phl);
		if (app->count > 1)
		{
			ft_philo_eat(app, phl);
			ft_philo_sleep(app, phl);
		}
	}
	exit(1);
}

int	ft_fork_run(t_app *app, t_phl *phl)
{
	if (!ft_philo_is_alive(phl))
	{
		ft_philo_die(app, phl);
		return (0);
	}
	return (1);
}

static void	*ft_fork_thread(void *arg)
{
	t_app	*app;

	app = (t_app *) arg;
	if (app->count > 1)
	{
		usleep(500);
		ft_sem_wait(app->sem_die, 1);
		ft_sem_post(app->sem_die, 2);
		ft_sem_post(app->sem_run, 1);
		exit(1);
	}
	return (0);
}
