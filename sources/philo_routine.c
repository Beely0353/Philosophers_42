/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:04:00 by baroun            #+#    #+#             */
/*   Updated: 2022/11/09 18:19:13 by baroun           ###   ########.fr       */
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

void	*philo_faucheuse(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		pthread_mutex_lock(&philo->mod_eat);
		if ((actual_time() - philo->last_eat) > philo->table->t_die)
		{
			pthread_mutex_lock(&philo->table->printing);
			printf("%ld   %d DIED\n", \
			actual_time() - philo->table->t_start, philo->id);
			philo->table->end = 1;
		}
		pthread_mutex_unlock(&philo->mod_eat);
		if (philo->table->nb_of_full == philo->table->nb_of_philo \
		&& philo->table->eat_end != -42)
		{
			pthread_mutex_lock(&philo->table->printing);
			printf("NO ONE HAS HUNGRY\n");
			philo->table->end = 1;
		}
	}
	return (0);
}
