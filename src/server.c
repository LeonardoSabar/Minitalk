/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:52:53 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/24 11:51:44 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	welcome_display(void)
{
	ft_printf(" _____                                                                              _____\n", "");
	ft_printf("( ___ )----------------------------------------------------------------------------( ___ )\n", "");
	ft_printf(" |   |                                                                              |   |\n", "");
	ft_printf(" |   | ooo        ooooo  o8o               o8o      .             oooo  oooo        |   |\n", "");
	ft_printf(" |   | `88.       .888'  `**               `*'    .o8             `888  `888        |   |\n", "");
	ft_printf(" |   |  888b     d'888  oooo  ooo. .oo.   oooo  .o888oo  .oooo.    888   888  oooo  |   |\n", "");
	ft_printf(" |   |  8  `888'   888   888   888   888   888    888    .oP'888   888   888888.    |   |\n", "");
	ft_printf(" |   |  8    Y     888   888   888   888   888    888 . d8(  888   888   888 `88b.  |   |\n", "");
	ft_printf(" |   | o8o        o888o o888o o888o o888o o888o   '888  `Y888""8o o888o o888o o888o |   |\n", "");
	ft_printf(" |___|                                                                              |___|\n", "");
	ft_printf("(_____)----------------------------------------------------------------------------(_____)\n", "");
	ft_printf("            ----- Welcome to Minitalk! ------ ");
	ft_printf("The PID number is: %d ------\n", getpid());
}

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
	if (sigaction(SIGUSR1, &sa_newsignal, NULL) == -1
		|| sigaction(SIGUSR2, &sa_newsignal, NULL) == -1)
	{
		ft_putendl_fd("Error!", STDERR_FILENO);
		exit(1);
	}
}

int	main(void)
{
	welcome_display();
	while (1)
		signal_config_server();
	return (0);
}
