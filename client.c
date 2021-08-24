#include "cl_serv.h"
#include <stdio.h>
#include <limits.h>


static int	ft_isnum(char *argv)
{
	int	i;

	i = 0;
	while (*(argv + i))
	{
		if ((*(argv + i) < 48) || (*(argv + i) > 57))
		{
			printf("f\n");
			return (-1);
		}
		i++;
	}
	return (1);
}

static int	ft_atoi(const char *str)
{
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)(res * sign));
}

// void printCharAsBinaryVer2(char c){
//     int bit_index;
//     for (bit_index = CHAR_BIT; bit_index >= 0; --bit_index)
//     {
//         int bit = ( unsigned int ) (c >> bit_index) & 1;
//         printf("%d", bit);
//     }
// }

static int ft_1bit(char c, int i)
{
	int	res;

	if ((c & (1 << i)) == 0)
			res = 0;
		else
			res = 1;
	printf("%d\t", res);
	return (res);
}

int	ft_char2bit(char *str)
{
	int i;
	int	res;
	int	temp;
	int	aux = 8;

	res = 0;
	i = 0;
	while (i < 8)
	{	
		temp = ft_1bit(str[i], i);
		res = res & 1 + (temp << --aux);
		//aux--;
		i++;
//		printf("%d\t", res);
	}
	printf("\n");
	return (res);
}

int		main(int argc, char **argv)
{
	int		cnt;

	cnt = 0;
	if (argc != 3)
		write(1, RED "WRONG INPUT\n" RESET, 22);
	else
	{
		if (ft_isnum(argv[1]) <= 0)
		{
			write(1, RED "WRONG PID\n" RESET, 22);
		}
		else
		{
			ft_char2bit(argv[2]);
			//ft_word_parser(argv[2]);
			printf("llaaaaaa\n");
		}
	}
//	printCharAsBinaryVer2('D');
	return (0);
}


