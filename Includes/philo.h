/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:33:20 by baroun            #+#    #+#             */
/*   Updated: 2022/10/25 16:02:11 by baroun           ###   ########.fr       */
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
	int last_eat;
	int	eated;
	int	l_fork;
	int r_fork;

	pthread_mutex_t	fork;

	struct s_table	*table;
} t_philo;

typedef struct s_table{
	size_t	nb_of_philo;
	size_t	t_die;
	size_t	t_eat;
	size_t	t_sleep;
	int	eat_end;
	int dead;

	pthread_mutex_t	printing;

	t_philo *philo;
} t_table;

t_table	*philo_parse(int ac, char **av);
int philo_error(int ac, char **av);
void	philo_init(t_table *table);

int	ft_isdigit(int c);
long int	actual_time(void);

#endif
