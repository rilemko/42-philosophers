/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:30:40 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_phl_creation(t_app *app);

void	ft_phl_clear(t_phl *phl)
{
	pthread_mutex_destroy(&phl->fork);
	pthread_detach(phl->thread);
	ft_free((void *) phl);
}

void	ft_phl_initialize(t_app *app)
{
	ft_phl_creation(app);
}

static void	ft_phl_creation(t_app *app)
{
	int	index;

	index = -1;
	while (++index < app->count)
	{
		app->phl[index] = malloc(sizeof(t_phl));
		if (!app->phl[index])
			return (ft_exit_failure(app, "Failed to allocate memory.", 1));
		app->created++;
		app->phl[index]->app = app;
		app->phl[index]->count = 0;
		app->phl[index]->die_at = 0;
		if (pthread_mutex_init(&app->phl[index]->fork, NULL) != 0)
			return (ft_exit_failure(app, "Failed to create mutex.", 1));
		app->phl[index]->id = index + 1;
		app->phl[index]->is_alive = 1;
		app->phl[index]->must_eat = index % 2;
	}
	while (--index >= 0)
	{
		if (index < app->count - 1)
			app->phl[index]->phl_next = app->phl[index + 1];
		else
			app->phl[index]->phl_next = app->phl[0];
	}
}
