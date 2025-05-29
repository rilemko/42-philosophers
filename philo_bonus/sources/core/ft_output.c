/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:40:40 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_output(const char *message, int fd)
{
	if (!message || !fd)
		return ;
	write(fd, message, ft_strlen(message));
}

void	ft_output_failure(const char *message, int colored)
{
	if (colored != 0)
		ft_output("\033[0;31m[X] ", STDERR_FILENO);
	ft_output(message, STDERR_FILENO);
	if (colored != 0)
		ft_output("\033[0;0m\n", STDERR_FILENO);
}

void	ft_output_success(const char *message, int colored)
{
	if (colored != 0)
		ft_output("\033[0;32m[✔] ", STDOUT_FILENO);
	ft_output(message, STDOUT_FILENO);
	if (colored != 0)
		ft_output("\033[0;0m\n", STDOUT_FILENO);
}

void	ft_output_warning(const char *message, int colored)
{
	if (colored != 0)
		ft_output("\033[0;33m[!] ", STDOUT_FILENO);
	ft_output(message, STDOUT_FILENO);
	if (colored != 0)
		ft_output("\033[0;0m\n", STDOUT_FILENO);
}
