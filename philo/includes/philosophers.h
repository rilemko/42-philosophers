/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:26:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:45:08 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_includes.h"
#include "_definitions.h"

void	ft_app_clear(t_app *app);
void	ft_app_initialize(t_app *app, int argc, char **argv);
void	ft_cfg_clear(t_app *app);
void	ft_cfg_initialize(t_app *app);
void	ft_phl_clear(t_phl *phl);
void	ft_phl_initialize(t_app *app);
int		ft_atoi(const char *string);
void	ft_exit(t_app *app, int code);
void	ft_exit_failure(t_app *app, const char *message, int colored);
void	ft_exit_success(t_app *app, const char *message, int colored);
void	ft_free(void *pointer);
void	ft_free_deep(void **pointer);
int		ft_intdiff(int int1, int int2);
void	ft_output(const char *message, int fd);
void	ft_output_failure(const char *message, int colored);
void	ft_output_success(const char *message, int colored);
void	ft_output_warning(const char *message, int colored);
void	ft_philo_die(t_app *app, t_phl *phl);
void	ft_philo_eat(t_app *app, t_phl *phl, t_phl *nxt);
int		ft_philo_is_alive(t_phl *phl);
void	ft_philo_sleep(t_app *app, t_phl *phl);
void	ft_philo_think(t_app *app, t_phl *phl);
int		ft_strlen(const char *string);
void	*ft_thread(void *arg);
int		ft_thread_run(t_app *app, t_phl *phl);
int		ft_time(int add_ms, int min_ms);
void	ft_wait(t_phl *phl, int time_ms);
