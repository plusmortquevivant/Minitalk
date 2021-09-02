/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:10:12 by arichie           #+#    #+#             */
/*   Updated: 2021/09/02 16:10:19 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cliserv_bonus.h"

static int	ft_isnum(char *argv)
{
	int	i;

	i = 0;
	while (*(argv + i))
	{
		if ((*(argv + i) < 48) || (*(argv + i) > 57))
			return (-1);
		i++;
	}
	return (1);
}

static void	ft_bit_parser(pid_t PID, char *str)
{
	int		bits;
	size_t	i;
	int		bit;

	i = 0;
	while (i <= ft_strlen(str))
	{
		bits = 7;
		while (bits >= 0)
		{
			bit = (unsigned int)(*(str + i) >> bits) & 1;
			if ((bit & 1) == 0)
				kill(PID, SIGUSR1);
			else if ((bit & 1) == 1)
				kill(PID, SIGUSR2);
			bits--;
			usleep(30);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	PID;

	if (argc != 3)
		write(1, RED "WRONG INPUT\n" RESET, 22);
	else
	{
		if (ft_isnum(argv[1]) <= 0)
		{
			write(1, RED "WRONG PID\n" RESET, 22);
			exit(1);
		}
		else
		{
			PID = ft_atoi(argv[1]);
			ft_bit_parser(PID, argv[2]);
		}
	}
	return (0);
}
