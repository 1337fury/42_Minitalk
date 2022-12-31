/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:02:11 by abdeel-o          #+#    #+#             */
/*   Updated: 2022/12/31 08:48:49 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	ft_signals(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int ac, char *argv[])
{
	int	server_id;
	int	i;

	if (ac == 3)
	{
		i = 0;
		server_id = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_signals(server_id, argv[2][i]);
			i++;
		}
	}
	return (0);
}
