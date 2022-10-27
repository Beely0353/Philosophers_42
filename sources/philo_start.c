/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:01:10 by baroun            #+#    #+#             */
/*   Updated: 2022/10/27 18:32:40 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_start(t_table *table)
{
	int	i;

	i = -1;

	philo_init(table);
	while (++i < table->nb_of_philo)
		pthread_create(&table->philo[i].thread, NULL, philo_routine, table->philo + i);
	pthread_mutex_lock(&table->exit);
	pthread_mutex_init(&table->printing, NULL);
	pthread_mutex_lock(&table->exit);
	pthread_mutex_unlock(&table->exit);
}

void	philo_end(t_table *table)
{
	int	i;

	time_usleep(100);
	i = -1;
	while (++i < table->nb_of_philo)
		pthread_mutex_destroy(&table->philo[i].fork);
	pthread_mutex_destroy(&table->printing);
	free(table);
}
