/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:14:45 by abdeel-o          #+#    #+#             */
/*   Updated: 2022/12/09 16:53:51 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hexa(unsigned int number, char *base, int counter)
{
	if (number >= 16)
	{
		counter += ft_put_hexa(number / 16, base, counter);
		counter += ft_put_hexa(number % 16, base, counter);
	}
	else
		counter = ft_putchar(base[number]);
	return (counter);
}
