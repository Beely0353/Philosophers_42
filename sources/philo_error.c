/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:13:01 by baroun            #+#    #+#             */
/*   Updated: 2022/11/09 16:37:30 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_error_arg_msg(void)
{
	printf("Error:\nPlease tape \"./philo [nb of philo]");
	printf(" [time to die] [time to eat] [time to sleep]");
	printf("\x1b[32m(OPTIONAL ---> [nb of each time philo must eat])\x1b[0m\".\n");
	printf("				      {in ms}	    {in ms}	   {in ms}\n");
	return (1);
}

int	philo_error_int(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '+')
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		if (ft_atoi(av) <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	philo_error(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		philo_error_arg_msg();
		return (1);
	}
	while (av[i])
	{
		if (philo_error_int(av[i]))
			return (printf("Error:\narguments must be a non-zero positive number."));
		i++;
	}
	if (ft_atoi(av[1]) <= 0)
	{
		printf("Error:\nmust have at least one philosopher");
		return (1);
	}
	return (0);
}
