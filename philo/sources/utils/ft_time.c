/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:00:34 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 14:12:53 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_time(int add_ms, int min_ms)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((((time.tv_sec * 1000) + (time.tv_usec / 1000)) + add_ms) - min_ms);
}

void	ft_wait(t_phl *phl, int time_ms)
{
	time_ms = ft_time(time_ms, 0);
	while (ft_time(0, 0) < time_ms)
	{
		if (ft_thread_run(phl->app, phl) == 0)
			return ;
		usleep(200);
	}
}
