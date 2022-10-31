/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:04:00 by baroun            #+#    #+#             */
/*   Updated: 2022/10/31 19:22:54 by baroun           ###   ########.fr       */
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
		philo_think(philo);
	}
	return(arg);
}

void	philo_eat(t_philo *philo)
{
	if (philo->table->end)
		return;
	/*if ((actual_time() - philo->last_eat) > philo->table->t_die)
	{
		philo->table->end = 1;
		pthread_mutex_lock(&philo->table->printing);
		printf("\n (%zu - %zu) > %zu \n",actual_time(),philo->last_eat,philo->table->t_die);
		printf("       %zu \n",actual_time() - philo->last_eat);
		printf("%ld	%d IS DEAD\n", actual_time() - philo->table->t_start, philo->id);
		pthread_mutex_unlock(&philo->table->exit);
		return;
	}*/
	philo->last_eat = actual_time();
	pthread_mutex_lock(&philo->table->philo[philo->l_fork].fork);
	pthread_mutex_lock(&philo->table->philo[philo->r_fork].fork);
	philo_print(philo, "IS TAKING FORKS");
	time_usleep(philo->table->t_eat);
	if (philo->eated >= philo->table->eat_end)
	{
		philo->table->end = 1;
		philo_print(philo, "IS NO LONGER HUNGRY");
		pthread_mutex_unlock(&philo->table->exit);
	}
	philo_print(philo, "IS EATING");
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

void	*philo_faucheuse(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;

	while(!philo->table->end)
	{
		if ((actual_time() - philo->last_eat) > philo->table->t_die)
		{
			philo->table->end = 1;
			pthread_mutex_lock(&philo->table->printing);
			printf("\n (%zu - %zu) > %zu \n",actual_time(),philo->last_eat,philo->table->t_die);
			printf("       %zu \n",actual_time() - philo->last_eat);
			printf("%ld	%d IS DEAD\n", actual_time() - philo->table->t_start, philo->id);
			pthread_mutex_unlock(&philo->table->exit);
			return (0);
		}
	}
	return (0);
}
