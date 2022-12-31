/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:02:20 by abdeel-o          #+#    #+#             */
/*   Updated: 2022/12/31 08:54:31 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

t_data	g_server;

void	ft_signals(int pid, unsigned char c)
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
	g_server.sent++;
}

void	ft_sighandler(int sig)
{
	if (sig == SIGUSR1)
		g_server.recieved++;
}

int	main(int ac, char *argv[])
{
	int					server_id;
	int					i;
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_handler = ft_sighandler;
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	if (ac == 3)
	{
		i = 0;
		server_id = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_signals(server_id, argv[2][i]);
			if (g_server.sent == g_server.recieved)
				ft_printf("success\n");
			else
				ft_printf("failled\n");
			i++;
		}
	}
	return (0);
}
