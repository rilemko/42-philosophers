/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:12:13 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(void *pointer)
{
	if (pointer != NULL)
		free(pointer);
}

void	ft_free_deep(void **pointer)
{
	size_t	index;

	if (!pointer)
		return ;
	index = 0;
	while (pointer[index])
		ft_free(pointer[index++]);
	ft_free(pointer);
}
