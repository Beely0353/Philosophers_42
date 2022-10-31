/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:38:51 by baroun            #+#    #+#             */
/*   Updated: 2022/10/31 17:26:54 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	actual_time(void)
{
	struct timeval	tm;
	long long		current;

	gettimeofday(&tm, NULL);
	current = tm.tv_sec * 1000 + tm.tv_usec / 1000;
	return(current);
}

void	time_usleep(size_t ms)
{
	size_t	time;

	time = actual_time();
	while ((actual_time() - time) < ms)
		usleep(500);
}
