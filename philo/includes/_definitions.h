/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _definitions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:04:01 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:43:46 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_constants.h"

typedef int			t_fd;
typedef int			t_pid;
typedef int			t_rt;

typedef struct s_cfg
{
	int	max_argc;
	int	min_argc;
}	t_cfg;

typedef struct s_phl
{
	void			*app;
	int				count;
	long int		die_at;
	pthread_mutex_t	fork;
	int				id;
	int				is_alive;
	int				must_eat;
	void			*phl_next;
	pthread_t		thread;
}	t_phl;

typedef struct s_app
{
	t_cfg			cfg;
	int				count;
	int				created;
	int				exit;
	int				must_eat;
	pthread_mutex_t	mutex;
	char			*name;
	t_phl			**phl;
	int				run;
	long int		time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_slp;
	int				time_to_thk;
}	t_app;
