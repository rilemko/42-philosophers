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

static void	*ft_thread_eat(void *arg);
static void	*ft_thread_die(void *arg);

void	ft_thread(t_app *app)
{
	pthread_t	threads[2];

	if (pthread_create(&threads[0], NULL, ft_thread_eat, app) != 0
		|| pthread_create(&threads[1], NULL, ft_thread_die, app) != 0)
		return (ft_exit_failure(app, "Failed to create thread.", 1));
	usleep(500);
	ft_sem_wait(app->sem_end, 1);
	pthread_detach(threads[0]);
	pthread_detach(threads[1]);
}

static void	*ft_thread_eat(void *arg)
{
	t_app	*app;

	app = (t_app *) arg;
	ft_sem_wait(app->sem_end, 1);
	usleep(500);
	if (app->must_eat > 0)
	{
		ft_sem_wait(app->sem_eat, app->must_eat * app->count);
		ft_sem_post(app->sem_end, 1);
	}
	return (0);
}

static void	*ft_thread_die(void *arg)
{
	t_app	*app;

	app = (t_app *) arg;
	ft_sem_wait(app->sem_end, 1);
	usleep(500);
	ft_sem_wait(app->sem_run, 1);
	ft_sem_post(app->sem_end, 1);
	return (0);
}
