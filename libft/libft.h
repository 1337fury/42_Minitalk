/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:59:20 by abdeel-o          #+#    #+#             */
/*   Updated: 2022/12/10 01:32:58 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_data {
	int		sent;
	int		recieved;
	int		client_pid;
}	t_data;
//printf
int	ft_printf(const char *format, ...);
int	ft_pformat(va_list arg, const char c);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int counter);
int	ft_putunsigned(unsigned int n, int counter);
int	ft_put_hexa(unsigned int number, char *base, int counter);
int	ft_putsign(void);
int	ft_putptr(void *ptr, char *base, int counter);
//libft
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

#endif
