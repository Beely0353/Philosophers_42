/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:42:34 by baroun            #+#    #+#             */
/*   Updated: 2022/10/25 16:11:49 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_table	*philo_parse(int ac, char **av)
{
	t_table *table;

	if (!philo_error(ac, av))
		return (NULL);
	table->nb_of_philo = ft_atoi(av[1]);
	table->t_die = ft_atoi(av[2]);
	table->t_eat = ft_atoi(av[3]);
	table->t_sleep = ft_atoi(av[4]);
	table->dead = 0;
	if (ac == 6)
		table->eat_end = ft_atoi(av[5]);
	else
		table->eat_end = -1;

}
