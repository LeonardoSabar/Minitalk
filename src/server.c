/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:52:53 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/20 16:46:53 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <signal.h>

struct sigaction	sa_newsignal;

static void	handler(int siginfo, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;

	(void)context;
	(void)info;
	if (siginfo == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

static void	signal_config_server(void)
{
	struct sigaction	sa_newsignal;
	sa_newsignal.sa_sigaction = &handler;
	sa_newsignal.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsignal, NULL) == -1)
	{
		ft_putendl_fd("Error!", STDERR_FILENO);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa_newsignal, NULL) == -1)
	{
		ft_putendl_fd("Error!", STDERR_FILENO);
		exit(1);
	}
}

int main(void)
{
	ft_printf("Welcome to Minitalk!\n");
	ft_printf("The PID number is: %d\n", getpid());

	while (1)
		signal_config_server();
	return (0);
}
