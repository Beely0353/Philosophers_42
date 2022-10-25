/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:53:17 by baroun            #+#    #+#             */
/*   Updated: 2022/10/25 15:59:36 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_init(t_table *table)
{
	int i;

	i = 0;
	while(i < table->nb_of_philo)
	{
		pthread_mutex_init(&table->philo[i].fork, NULL);
		table->philo[i].id = i + 1;
		table->philo[i].eated = 0;
		table->philo[i].eating = 0;
		table->philo[i].sleeping = 0;
		table->philo[i].last_eat = actual_time();
		table->philo[i].l_fork = i;
		table->philo[i].r_fork = i + 1;
		if (!i)
			table->philo[i].r_fork = table->nb_of_philo;
		if (i ==table->nb_of_philo)
			table->philo[i].r_fork = 0;
		i++;
	}	
}

