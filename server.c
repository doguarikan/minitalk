/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darikan <darikan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:01:57 by darikan           #+#    #+#             */
/*   Updated: 2024/04/28 19:01:57 by darikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_action(int signal)
{
	static char	c;
	static int	i;

	c <<= 1;
	if (signal == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	pid_t	id;

	id = getpid();
	ft_printf("%d\n", id);
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	while (1)
		continue ;
}
