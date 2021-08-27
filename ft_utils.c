#include "cl_serv.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	r;

	r = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
	}
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (r > LONG_MAX && (sign == 1))
			return (-1);
		if (r > LONG_MAX && (sign == -1))
			return (0);
		r = r * 10 + *str - '0';
		str++;
	}
	return (sign * (int)r);
}

void	ft_putstr_fd(char *color, char *s, int fd)
{
	if (!s)
		return ;
	write(1, color, 5);
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
	write(1, RESET, 5);
}

void	ft_putchar_fd(char *color, char c, int fd)
{
	write(1, color, 5);
	write(fd, &c, 1);
	write(1, RESET, 5);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd(GREEN, '-', fd);
		ft_putchar_fd(GREEN, '2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd(GREEN, '-', fd);
		ft_putnbr_fd(n * (-1), fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(GREEN, n + '0', fd);
	}
}