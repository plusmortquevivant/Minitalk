#include "cl_serv.h"
#include <stdio.h>

void	ft_sig_analysis(int n)
{
	static char num;
	static int i;
	
	/*if (n == SIGUSR2)
		num = num & ~(1 << i);
	else if (n == SIGUSR1)
		num = num | (1 << i);*/
	if (n == SIGUSR1)
		num = num | (0 << (7 - i));
	if (n == SIGUSR2)
		num = num | (1 << (7 - i));
	//printf("%d%d%d%d%d%d%d%d\n", num & (1 << 7), num & (1 << 6), num & (1 << 5), num & (1 << 4), num & (1 << 3), num & (1 << 2), num & (1 << 1), num & 1);
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

int		main(int argc, char **argv)
{
	pid_t PID;
	//char *pid;

	(void)argv;
	signal(SIGUSR1, ft_sig_analysis);
	signal(SIGUSR2, ft_sig_analysis);
	PID = getpid();
	if (argc != 1)
		write(1, RED "WRONG INPUT\n" RESET, 22);

	ft_putstr_fd(GREEN, "PID: ", 1);
//	printf("111\n");
	ft_putnbr_fd(PID, 1);
	printf("111\n");
	while (1)
		pause();
	return (0);
}