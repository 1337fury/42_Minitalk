#include "./libft/libft.h"

t_data server;

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, (power - 1)));
}

void	ft_convert_base(int *bits)
{
	int				i;
	int				j;
	int				result;

	i = 0;
	j = 7;
	result = 0;
	while (i < 8)
		result += bits[i++] * ft_recursive_power(2, j--);
	ft_printf("%c", (unsigned char)result);
}

void	ft_checker(int *i, int *bits, siginfo_t *info)
{
	if (server.client_pid == 0)
		server.client_pid = info->si_pid;
	else if (server.client_pid != info->si_pid)
	{	
		*i = 0;
		ft_bzero(bits, 8);
		server.client_pid = info->si_pid;
	}
	return ;
}

void	ft_sighandler(int signal, siginfo_t *info)
{
	static int	i;
	static int	bits[8];
	
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		ft_checker(&i, bits, info);
		if (signal == SIGUSR1)
			bits[i++] = 0;
		else if (signal == SIGUSR2)
			bits[i++] = 1;
		if (i == 8)
		{
			i = 0;
			ft_convert_base(bits);
			ft_bzero(bits, 8);
			kill(info->si_pid, SIGUSR1);
		}
	}
}

int	main()
{
	int	pid;
	struct	sigaction action;

	sigemptyset(&action.sa_mask);
	action.sa_sigaction = (void *)ft_sighandler;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("Process id: %d\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	server.client_pid = 0;
	while (1)
		pause();
}
