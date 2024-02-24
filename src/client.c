/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:33:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/24 16:46:39 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	check_args(int argc, char **argv)
{
	int	idx;

	if (argc != 3)
	{
		ft_putendl_fd("Usage error.\nExpected:<client.c> <pid> <message>",
			STDERR_FILENO);
		exit(1);
	}
	idx = 0;
	while (argv[1][idx])
	{
		if (!ft_isdigit(argv[1][idx]))
		{
			ft_putendl_fd("A valid PID is required.\n",
				STDERR_FILENO);
			exit(1);
		}
		idx++;
	}
}

void	send_binary(char charac, pid_t pid)
{
	int	bit_idx;

	bit_idx = 0;
	while (bit_idx < 8)
	{
		if ((charac & (0b1 << bit_idx)) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit_idx++;
		usleep(342);
	}
}

void	client_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr ("Character received!\n");
	}
}

void	signal_config_client(void)
{
	struct sigaction	sa_newsignal;

	sa_newsignal.sa_flags = 0;
	sa_newsignal.sa_handler = &client_handler;
	if (sigaction(SIGUSR1, &sa_newsignal, NULL) == -1
		|| sigaction(SIGUSR2, &sa_newsignal, NULL) == -1)
	{
		ft_putendl_fd("Error!", STDERR_FILENO);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		idx;

	idx = 0;
	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	signal_config_client();
	while (argv[2][idx])
		send_binary(argv[2][idx++], pid);
	return (0);
}
