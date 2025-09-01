/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:39:11 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:47:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

sem_t	*ft_sem_open(const char *name, int count)
{
	return (sem_open(name, O_CREAT | O_EXCL, 0775, count));
}

int	ft_sem_post(sem_t *semaphore, int repeat)
{
	int	status;
	int	index;

	index = -1;
	while (++index < repeat)
	{
		status = sem_post(semaphore);
		if (status != 0)
		{
			ft_sem_wait(semaphore, index + 1);
			return (-1);
		}
	}
	return (0);
}

void	ft_sem_remove(const char *name, sem_t *semaphore)
{
	sem_close(semaphore);
	sem_unlink(name);
}

int	ft_sem_wait(sem_t *semaphore, int repeat)
{
	int	status;
	int	index;

	index = -1;
	while (++index < repeat)
	{
		status = sem_wait(semaphore);
		if (status != 0)
		{
			ft_sem_post(semaphore, index + 1);
			return (-1);
		}
	}
	return (0);
}
