/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:01:10 by baroun            #+#    #+#             */
/*   Updated: 2023/04/24 17:12:04 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_faucheuse(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (!table->end)
	{
		philo = &table->philo[++i];
		pthread_mutex_lock(&philo->mod_eat);
		if ((actual_time() - philo->last_eat) > philo->table->t_die)
		{
			pthread_mutex_lock(&philo->table->printing);
			printf("%ld   %d DIED\n", actual_time() - table->t_start, philo->id);
			philo->table->end = 1;
		}
		pthread_mutex_unlock(&philo->mod_eat);
		if (table->nb_of_full == table->nb_of_philo && table->eat_end != -42)
		{
			pthread_mutex_lock(&philo->table->printing);
			printf("NO ONE HAS HUNGRY\n");
			table->end = 1;
		}
		if (i < table->nb_of_philo)
			i = -1;
	}
}

void	philo_start(t_table *table)

{
	int	i;

	i = -1;
	philo_init(table);
	table->t_start = actual_time();
	while (++i < table->nb_of_philo)
		pthread_create(&table->philo[i].thread, NULL, \
		philo_routine, &table->philo[i]);
	pthread_mutex_init(&table->printing, NULL);
	philo_faucheuse(table);
}

void	philo_end(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_of_philo)
	{
		time_usleep(50);
		pthread_mutex_destroy(&table->philo[i].fork);
		pthread_mutex_destroy(&table->philo[i].mod_eat);
		pthread_detach(table->philo[i].thread);
	}
	pthread_mutex_destroy(&table->printing);
	free(table);
	free(table->philo);
}
