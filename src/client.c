/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:33:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/19 14:39:05 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void send_binary(char charac, int pid)
{
	int bit_idx;

	bit_idx = 0;
	while (bit_idx < 8)
	{
		if ((charac & (0b1 << bit_idx)) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit_idx++;
		usleep(300);
	}
}

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
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putendl_fd("A valid message is required.\n",
		STDERR_FILENO);
		exit(1);
	}
}

int main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		idx;

	idx = 0;
	str = argv[2];

	printf("%s %s\n", argv[1], argv[2]);
	check_args(argc, argv);
	pid = ft_atoi(argv[1]);

	while (str[idx])
	{
		send_binary(str[idx], pid);
		idx++;
	}
	return 0;
}
