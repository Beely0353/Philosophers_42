/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:04:00 by baroun            #+#    #+#             */
/*   Updated: 2022/10/25 16:11:49 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

void	*philo_routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;

	while (!philo->table->dead)
	{
		philo_eat(philo);
		philo_sleep(philo);
		Philo_philo(philo);
	}

}

void	philo_eat(t_philo *philo)
{
	
}
