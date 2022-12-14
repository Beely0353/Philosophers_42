/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:01:10 by baroun            #+#    #+#             */
/*   Updated: 2022/11/09 18:14:19 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_start(t_table *table)
{
	int	i;

	i = -1;
	philo_init(table);
	table->t_start = actual_time();
	while (++i < table->nb_of_philo)
	{
		pthread_create(&table->philo[i].thread, NULL, \
		philo_routine, &table->philo[i]);
		pthread_create(&table->philo[i].mort, NULL, \
		philo_faucheuse, &table->philo[i]);
	}
	pthread_mutex_init(&table->printing, NULL);
	while (!table->end)
		usleep(10);
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
		pthread_detach(table->philo[i].mort);
	}
	pthread_mutex_destroy(&table->printing);
	free(table);
	free(table->philo);
}
