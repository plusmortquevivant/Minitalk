/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliserv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:11:08 by arichie           #+#    #+#             */
/*   Updated: 2021/09/02 16:11:11 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLISERV_BONUS_H
# define CLISERV_BONUS_H
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	ft_putstr_fd(char *color, char *s, int fd);
void	ft_putchar_fd(char *color, char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);

#endif
