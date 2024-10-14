/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:26:30 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_philo_die(t_app *app, t_phl *phl)
{
	int	time_ms;

	time_ms = ft_time(0, app->time);
	if (app->run == 1)
	{
		ft_sem_wait(app->semaphore, 1);
		printf("\033[0;31m%08i %i died\033[0;0m\n", time_ms, phl->id);
		ft_sem_post(app->sem_die, 1);
		ft_sem_post(app->sem_run, 1);
		app->run = 0;
		phl->is_alive = 0;
		exit(1);
	}
}

void	ft_philo_eat(t_app *app, t_phl *phl)
{
	if (phl->must_eat == 0)
		return ;
	if (ft_fork_run(app, phl) && ft_sem_wait(app->forks, 1) == 0)
		if (ft_fork_run(app, phl) && ft_sem_wait(app->semaphore, 1) == 0)
			printf("%08i %i has taken a fork\n", ft_time(0, app->time), phl->id);
	ft_sem_post(app->semaphore, 1);
	if (ft_fork_run(app, phl) && ft_sem_wait(app->forks, 1) == 0)
		if (ft_fork_run(app, phl) && ft_sem_wait(app->semaphore, 1) == 0)
			printf("%08i %i has taken a fork\n", ft_time(0, app->time), phl->id);
	ft_sem_post(app->semaphore, 1);
	if (ft_fork_run(app, phl) && ft_sem_wait(app->semaphore, 1) == 0)
		printf("%08i %i is eating\n", ft_time(0, app->time), phl->id);
	ft_sem_post(app->semaphore, 1);
	if (app->must_eat > 0)
		ft_sem_post(app->sem_eat, 1);
	phl->die_at = ft_time(app->time_to_die, 0);
	ft_wait(phl, app->time_to_eat);
	ft_sem_post(app->forks, 2);
	phl->must_eat = 0;
}

int	ft_philo_is_alive(t_phl *phl)
{
	if (phl->is_alive == 1 && (ft_time(0, 0) < phl->die_at))
		return (phl->die_at - ft_time(0, 0));
	return (0);
}

void	ft_philo_sleep(t_app *app, t_phl *phl)
{
	int	time_ms;

	time_ms = ft_time(0, app->time);
	if (ft_fork_run(app, phl))
	{
		ft_sem_wait(app->semaphore, 1);
		printf("%08i %i is sleeping\n", time_ms, phl->id);
		ft_sem_post(app->semaphore, 1);
		ft_wait(phl, app->time_to_slp);
	}
}

void	ft_philo_think(t_app *app, t_phl *phl)
{
	int	time_ms;

	if (phl->must_eat == 1)
		return ;
	time_ms = ft_time(0, app->time);
	if (ft_fork_run(app, phl))
	{
		ft_sem_wait(app->semaphore, 1);
		printf("%08i %i is thinking\n", time_ms, phl->id);
		ft_sem_post(app->semaphore, 1);
		if (app->time_to_thk > 0)
			ft_wait(phl, app->time_to_thk);
		else
			usleep(300);
		phl->must_eat = 1;
	}
}
