/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:33:50 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_app_creation(t_app *app, int argc, char **argv);
static void	ft_app_precheck(t_app *app, int argc, char **argv);

void	ft_app_clear(t_app *app)
{
	int	index;

	index = -1;
	while (++index < app->created)
		ft_phl_clear(app->phl[index]);
	ft_free((void *) app->phl);
	if (app->time_to_die != 0)
		pthread_mutex_destroy(&app->mutex);
}

void	ft_app_initialize(t_app *app, int argc, char **argv)
{
	app->count = 0;
	app->created = 0;
	app->exit = 0;
	app->must_eat = -1;
	app->name = argv[0];
	app->phl = NULL;
	app->time = 0;
	app->time_to_die = 0;
	app->time_to_eat = 0;
	app->time_to_slp = 0;
	app->time_to_thk = 0;
	app->run = 1;
	ft_app_precheck(app, argc, argv);
	if (app->exit)
		return ;
	ft_app_creation(app, argc, argv);
}

static void	ft_app_creation(t_app *app, int argc, char **argv)
{
	app->count = ft_atoi(argv[1]);
	if (pthread_mutex_init(&app->mutex, NULL) != 0)
		return (ft_exit_failure(app, "Failed to create mutex.", 1));
	if (argc == 6)
		app->must_eat = ft_atoi(argv[5]);
	app->phl = malloc(app->count * sizeof(t_phl *));
	app->time_to_die = ft_atoi(argv[2]);
	app->time_to_eat = ft_atoi(argv[3]);
	app->time_to_slp = ft_atoi(argv[4]);
	app->time_to_thk = ft_intdiff(app->time_to_eat, app->time_to_slp) - 1;
}

static void	ft_app_precheck(t_app *app, int argc, char **argv)
{
	int	index;

	if (argc < app->cfg.min_argc || argc > app->cfg.max_argc)
		return (ft_exit_failure(app, "Usage: ./philosophers [number_philo] \
[time_die] [time_eat] [time_sleep] {number_each_philo_must_eat}", 1));
	while (--argc > 0)
	{
		index = -1;
		while (argv[argc][++index])
		{
			if (argv[argc][index] < '0' || argv[argc][index] > '9'
				|| ft_atoi(argv[argc]) <= 0)
				return (ft_exit_failure(app,
						"Wrong arguments type. Arguments must be positive INT.",
						1));
		}
	}
}
