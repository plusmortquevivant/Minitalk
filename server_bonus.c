/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:10:30 by arichie           #+#    #+#             */
/*   Updated: 2021/09/02 16:10:34 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cliserv.h"

void	ft_sig_analysis(int n)
{
	static char	num;
	static int	i;

	if (n == SIGUSR1)
		num &= ~(0 << (7 - i));
	if (n == SIGUSR2)
		num |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		i = 0;
		if (num == 0)
			write(1, "\n", 1);
		else
			write(1, &num, 1);
		num = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	PID;

	(void)argv;
	signal(SIGUSR1, ft_sig_analysis);
	signal(SIGUSR2, ft_sig_analysis);
	PID = getpid();
	if (argc != 1)
		write(1, RED "WRONG INPUT\n" RESET, 22);
	else
	{
		ft_putstr_fd(GREEN, "PID: ", 1);
		ft_putnbr_fd(PID, 1);
		write(1, "\n", 1);
		while (1)
			pause();
	}
	return (0);
}
