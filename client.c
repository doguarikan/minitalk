/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:00:22 by darikan           #+#    #+#             */
/*   Updated: 2024/04/28 19:00:22 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_kill(int pid, char *argc)
{
	int	i;
	int	bit;

	i = 0;
	if (!argc || !argc[i])
		return ;
	while (argc[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((argc[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			exit(0);
		}
		ft_kill(pid, argv[2]);
	}
	else
	{
		ft_printf("Error!\n");
		exit(0);
	}
	return (0);
}
