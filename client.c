#include "cl_serv.h"
#include <stdio.h>

static int	ft_isnum(char *argv)
{
	int	i;

	i = 0;
	while (*(argv + i))
	{
		if ((*(argv + i) < 48) || (*(argv + i) > 57))
		{
			//write(1, RED "WRONG PID INPUT\n" RESET, 26);
			return (-1);
		}
		i++;
	}
	return (1);
}

static void ft_bit_parser(pid_t PID, char *str)
{
    int bits;
	int i;
	int bit;

	i = 0;
	while (*(str + i))
	{
		bits = 7;
    	while (bits >= 0)
    	{
        	bit = (unsigned int)(*(str + i) >> bits) & 1;
        	if ((bit & 1) == 0)
				{
					 (kill(PID, SIGUSR1));
						// {
						// 	write(1, RED "WffRONG PID INPUT\n" RESET, 26);
						// 	return ;
						 //}
				}
        	else if ((bit & 1) == 1)
				{
					 (kill(PID, SIGUSR2));
				// 		{
				// 			write(1, RED "WRONG PID INPUT\n" RESET, 26);
				// 			return ;
				// 		}
				 }
			printf("%d", bit);
			bits--;
			usleep(30);
    	}
		i++;
	}
}

int		main(int argc, char **argv)
{
	pid_t PID;

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
			printf("%d\n", PID);
			ft_bit_parser(PID, argv[2]);
			//ft_char2bit(argv[2]);
			//printf("llaaaaaa\n");
		}
	}
	return (0);
}


