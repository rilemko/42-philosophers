/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:38:43 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exit(t_app *app, int code)
{
	ft_cfg_clear(app);
	ft_app_clear(app);
	app->exit = code;
}

void	ft_exit_failure(t_app *app, const char *message, int colored)
{
	if (message && ft_strlen(message))
		ft_output_failure(message, colored);
	ft_exit(app, EXIT_FAILURE);
}

void	ft_exit_success(t_app *app, const char *message, int colored)
{
	if (message && ft_strlen(message))
		ft_output_success(message, colored);
	ft_exit(app, EXIT_SUCCESS);
}
