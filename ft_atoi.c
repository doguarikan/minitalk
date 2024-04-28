/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:00:19 by darikan           #+#    #+#             */
/*   Updated: 2024/04/28 19:00:19 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	atoi_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		num = (num * 10) + (str[i++] - '0');
	if ((num > 2147483648 && sign == -1)
		|| (num > 2147483647 && sign == 1))
		atoi_error();
	if ((str[i] && str[i] != 10)
		|| (str[i] == '-' && !str[1]))
		atoi_error();
	return ((int)(sign * num));
}
