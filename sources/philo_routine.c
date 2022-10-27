/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:04:00 by baroun            #+#    #+#             */
/*   Updated: 2022/10/27 18:37:15 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (!philo->table->end)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_sleep(philo);
	}
	return(arg);
}

void	philo_eat(t_philo *philo)
{	
	if (actual_time() - philo->last_eat > philo->table->t_eat)
	{
		philo->table->end = 1;
		philo_print(philo, "IS DEAD");
		pthread_mutex_unlock(&philo->table->exit);
		return;
	}
	philo->last_eat = actual_time();
	pthread_mutex_lock(&philo->table->philo[philo->l_fork].fork);
	pthread_mutex_lock(&philo->table->philo[philo->r_fork].fork);
	philo_print(philo, "IS EATING");
	time_usleep(philo->table->t_eat);
	if (philo->eated >= philo->table->eat_end)
	{
		philo->table->end = 1;
		philo_print(philo, "IS NO LONGER HUNGRY");
		pthread_mutex_unlock(&philo->table->exit);
	}
	pthread_mutex_unlock(&philo->table->philo[philo->l_fork].fork);
	pthread_mutex_unlock(&philo->table->philo[philo->r_fork].fork);
	philo->eated++;
	
}

void	philo_sleep(t_philo *philo)
{
	if (philo->table->end)
		return;
	philo_print(philo, "IS SLEEPING");
	time_usleep(philo->table->t_sleep);
}

void	philo_think(t_philo *philo)
{
	if (philo->table->end)
		return;
	philo_print(philo, "IS THINKING");
}
