/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:30:38 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:52 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_process(t_app *app);

int	main(int argc, char **argv)
{
	t_app	app;

	ft_cfg_initialize(&app);
	ft_app_initialize(&app, argc, argv);
	ft_phl_initialize(&app);
	ft_process(&app);
	ft_exit_success(&app, "", 0);
}

static void	ft_process(t_app *app)
{
	int			index;

	ft_sem_wait(app->sem_run, app->count);
	index = -1;
	app->time = ft_time(1000, 0);
	while (++index < app->count)
	{
		app->process_id[index] = fork();
		if (app->process_id[index] == 0)
		{
			ft_fork(app->phl[index]);
			ft_exit_success(app, "", 0);
		}
	}
	ft_sem_post(app->sem_run, app->count);
	usleep(500);
	ft_thread(app);
	index = -1;
	while (++index < app->count)
		kill(app->process_id[index], SIGKILL);
}
