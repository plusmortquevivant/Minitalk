#ifndef CL_SERV_H
# define CL_SERV_H
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>

int	ft_atoi(const char *str);

#endif