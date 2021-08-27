#include "cl_serv.h"

void	ft_sig_analysis(int n)
{
	static char num;
	static int i;
	
	if (n == SIGUSR1)
		num = num & ~(1 << i);
	else if (n == SIGUSR2)
		num = num | (1 << i);
	i++;
	if (i == 8)
		i = 0;
	if (num == 0)
		write(1, "\n", 1);
	else
		write(1, &num, 1);
}

int		main(int argc, char **argv)
{
	pid_t PID;
	//char *pid;

	(void)argv;
	PID = getpid();
	if (argc != 1)
		write(1, RED "WRONG INPUT\n" RESET, 22);
	signal(SIGUSR1, ft_sig_analysis);
	signal(SIGUSR2, ft_sig_analysis);
	ft_putstr_fd(GREEN, "PID: ", 1);
	ft_putnbr_fd(PID, 1);
	while (1)
		pause();
	return (0);
}