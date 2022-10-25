/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:01:10 by baroun            #+#    #+#             */
/*   Updated: 2022/10/25 16:11:48 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

void philo_start(t_table *table)
{
	int	i;

	i = -1;

	while (++i < table->nb_of_philo)
		pthread_create(&table->philo[i].thread, NULL, philo_routine, table->philo + i);
	philo_init();
	pthread_mutex_init(&table->printing, NULL);
}
