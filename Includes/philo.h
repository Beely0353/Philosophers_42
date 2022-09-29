/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:33:20 by baroun            #+#    #+#             */
/*   Updated: 2022/09/29 16:08:47 by baroun           ###   ########.fr       */
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

typedef struct s_table{
	size_t	nb_of_philo;
	size_t	t_die;
	size_t	t_eat;
	size_t	t_sleep;
	int	eat_end;
	int tombe;
} t_table;

typedef struct s_philo{
	pthread_t	thread;
	int	id;
	int	eated;
	
	
} t_philo;


t_table	*philo_parse(int ac, char **av);
int philo_error(int ac, char **av);

int	ft_isdigit(int c)

#endif
