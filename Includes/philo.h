/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:33:20 by baroun            #+#    #+#             */
/*   Updated: 2022/10/27 17:04:30 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>

typedef struct s_philo{
	pthread_t	thread;
	int	id;
	int eating;
	int sleeping;
	size_t last_eat;
	int	eated;
	int	l_fork;
	int r_fork;

	pthread_mutex_t	fork;

	struct s_table	*table;
} t_philo;

typedef struct s_table{
	int	nb_of_philo;
	size_t	t_die;
	size_t	t_eat;
	size_t	t_sleep;
	long int t_start;
	int	eat_end;
	
	int end;

	pthread_mutex_t	printing;
	pthread_mutex_t	exit;
	t_philo *philo;
} t_table;

/* ************************** PARSE/ERROR *************************** */
int	philo_error_arg_msg(void);
int	philo_error_int(char *av);
int philo_error(int ac, char **av);
t_table	*philo_parse(int ac, char **av);

/* ************************** PHILO *************************** */
void philo_start(t_table *table);
void	philo_init(t_table *table);
void	*philo_routine(void *arg);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_end(t_table *table);

/* ************************** UTILS *************************** */
int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_atoi(const char *str);
void	philo_print(t_philo *philo, char *msg);

size_t	actual_time(void);
void	time_usleep(size_t ms);

#endif
