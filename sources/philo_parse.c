/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:42:34 by baroun            #+#    #+#             */
/*   Updated: 2022/11/07 16:59:39 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*philo_parse(int ac, char **av)
{
	t_table	*table;

	if (philo_error(ac, av))
		return (NULL);
	table = malloc(sizeof(t_table));
	table->nb_of_philo = ft_atoi(av[1]);
	table->philo = malloc(sizeof(t_philo) * table->nb_of_philo);
	table->t_die = ft_atoi(av[2]);
	table->t_eat = ft_atoi(av[3]);
	table->t_sleep = ft_atoi(av[4]);
	table->end = 0;
	pthread_mutex_init(&table->printing, NULL);
	if (ac == 6)
		table->eat_end = ft_atoi(av[5]);
	if (ac == 5)
		table->eat_end = -42;
	return (table);
}
