/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cfg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:17:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_cfg_creation(t_app *app);

void	ft_cfg_clear(t_app *app)
{
	(void) app;
}

void	ft_cfg_initialize(t_app *app)
{
	app->cfg.max_argc = 6;
	app->cfg.min_argc = 5;
	ft_cfg_creation(app);
}

static void	ft_cfg_creation(t_app *app)
{
	(void) app;
}
