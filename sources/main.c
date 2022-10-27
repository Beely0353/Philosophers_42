/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:43:16 by baroun            #+#    #+#             */
/*   Updated: 2022/10/27 17:08:52 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_table *table;

	table = philo_parse(ac, av);
	if (table != NULL)
	{
		philo_start(table);
		philo_end(table);
	}
	return (1);
}
