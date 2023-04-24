/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:04:00 by baroun            #+#    #+#             */
/*   Updated: 2023/04/24 14:04:06 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(15);
	while (!philo->table->end)
	{
		philo_eat(philo);
		philo_sleep_think(philo);
	}
	return (arg);
}

void	philo_eat(t_philo *philo)
{
	if (philo->table->end)
		return ;
	pthread_mutex_lock(&philo->table->philo[philo->l_fork].fork);
	philo_print(philo, "IS TAKEN A FORK");
	if (philo->table->nb_of_philo == 1)
		time_usleep(philo->table->t_die * 2 + 10);
	pthread_mutex_lock(&philo->table->philo[philo->r_fork].fork);
	philo_print(philo, "IS TAKEN A FORK");
	pthread_mutex_lock(&philo->mod_eat);
	philo->last_eat = actual_time();
	pthread_mutex_unlock(&philo->mod_eat);
	time_usleep(philo->table->t_eat);
	philo_print(philo, "IS EATING");
	pthread_mutex_unlock(&philo->table->philo[philo->l_fork].fork);
	pthread_mutex_unlock(&philo->table->philo[philo->r_fork].fork);
	philo->eated++;
	if (philo->eated >= philo->table->eat_end)
		philo->table->nb_of_full++;
}

void	philo_sleep_think(t_philo *philo)
{
	if (philo->table->end)
		return ;
	philo_print(philo, "IS SLEEPING");
	time_usleep(philo->table->t_sleep);
	if (philo->table->end)
		return ;
	philo_print(philo, "IS THINKING");
	if (philo->table->nb_of_philo == 2)
		time_usleep(30);
}
