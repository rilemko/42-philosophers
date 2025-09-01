/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:30:38 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:46:58 by mconreau         ###   ########.fr       */
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
	if (app.exit)
		return (app.exit);
	ft_process(&app);
	if (app.exit)
		return (app.exit);
	ft_exit_success(&app, "", 0);
	return (app.exit);
}

static void	ft_process(t_app *app)
{
	int	index;

	index = -1;
	app->time = ft_time(1000, 0);
	while (++index < app->count)
		if (pthread_create(&app->phl[index]->thread, NULL,
				ft_thread, app->phl[index]) != 0)
			return (ft_exit_failure(app, "Failed to create thread.", 1));
	index = -1;
	while (++index < app->count)
		pthread_join(app->phl[index]->thread, NULL);
}
