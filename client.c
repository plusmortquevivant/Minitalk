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

void ft_bit_parser(pid_t PID, char *str)
{
    int bits;
	int i;
	int bit;

	i = 0;
	while (*(str + i))
	{
		bits = 8;
    	while (bits >= 0)
    	{
        	bit = (unsigned int)(*(str + i) >> bits) & 1;
        	//KILL(PID, SIGUSR1);
			bits--;
    	}
		i++;
	}
}

// static int ft_1bit(char c, int i)
// {
// 	int	res;

// 	if ((c & (1 << i)) == 0)
// 			res = 0;
// 		else
// 			res = 1;
// 	printf("%d\t", res);
// 	return (res);
// }

// int	ft_char2bit(char *str)
// {
// 	int i;
// 	int	res;
// 	int	temp;
// 	int	aux = 8;

// 	res = 0;
// 	i = 0;
// 	while (i < 8)
// 	{	
// 		temp = ft_1bit(str[i], i);
// 		// res = res & 1 + (temp << --aux);
// 		//aux--;
// 		i++;
// 	}
// 	printf("\n");
// 	printf("%d\t", res);
// 	return (res);
// }

int		main(int argc, char **argv)
{
	int		cnt;
	pid_t PID;

	cnt = 0;
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
			//ft_char2bit(argv[2]);
			//printf("llaaaaaa\n");
		}
	}
	return (0);
}


