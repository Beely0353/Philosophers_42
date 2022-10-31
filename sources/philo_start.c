/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:01:10 by baroun            #+#    #+#             */
/*   Updated: 2022/10/31 19:23:13 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_start(t_table *table)
{
	int	i;

	i = 0;

	philo_init(table);
	table->t_start = actual_time();
	while (++i < table->nb_of_philo)
	{
		pthread_create(&table->philo[i].thread, NULL, philo_routine, &table->philo[i]);
		pthread_create(&table->philo[i].mort, NULL, philo_faucheuse, &table->philo[i]);

	}
	pthread_mutex_lock(&table->exit);
	pthread_mutex_init(&table->printing, NULL);
	pthread_mutex_lock(&table->exit);
}

void	philo_end(t_table *table)
{
	int	i;

	time_usleep(100);
	i = -1;
	while (++i < table->nb_of_philo)
		pthread_mutex_destroy(&table->philo[i].fork);
	pthread_mutex_destroy(&table->printing);
	pthread_mutex_destroy(&table->exit);
	free(table->philo);
	free(table);
}
