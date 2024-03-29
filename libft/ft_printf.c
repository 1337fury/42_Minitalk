/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:35:11 by abdeel-o          #+#    #+#             */
/*   Updated: 2022/12/09 16:53:37 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		counter;

	counter = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			counter += ft_pformat(arg, *(++format));
		else
			counter += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (counter);
}
