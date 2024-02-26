/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:33:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/26 18:00:13 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_signal_received;

/**
 * @brief Check if the arguments are valid
 * @param argc Number of arguments
 * @param argv Arguments
 */
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

/**
 * @brief Send a binary message to the server
 * @brief charac Character to be sent
 * @brief pid Server's PID
 * @brief kill Send a signal to a process
 * @brief SIGUSR1 User-defined signal 1
 * @brief SIGUSR2 User-defined signal 2
 * @return void
*/
void	send_binary(char charac, pid_t pid)
{
	int	bit_idx;

	bit_idx = 0;
	while (bit_idx < 8)
	{
		g_signal_received = 0;
		if ((charac & (0b1 << bit_idx)) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit_idx++;
		while (!g_signal_received)
			;
	}
}

/**
 * @brief Handle the signals received by the client
 * @brief sig Signal received
 * @brief SIGUSR1 User-defined signal 1
 * @brief SIGUSR2 User-defined signal 2
 * @return void
*/
void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr ("Character received!\n");
	else if (sig == SIGUSR2)
		g_signal_received = 1;
}

/**
 * @brief Configure the signals for the client
 * @brief sigaction Structure that specifies the action to be associated with a specific signal
 * @brief sa_flags Special flags
 * @brief sa_handler Signal handler
 * @brief SIGUSR1 User-defined signal 1
 * @brief SIGUSR2 User-defined signal 2
 * @return void
*/
void	signal_config_client(void)
{
	struct sigaction	sa_newsignal;

	sa_newsignal.sa_flags = 0;
	sa_newsignal.sa_handler = &client_handler;
	if (sigaction(SIGUSR1, &sa_newsignal, NULL) == -1
		|| sigaction(SIGUSR2, &sa_newsignal, NULL) == -1)
	{
		ft_putendl_fd("Error setting signal handlers!\n", STDERR_FILENO);
		exit(1);
	}
}

/**
 * @brief Main function
 * @brief argc Number of arguments
 * @brief argv Arguments
 * @brief pid Server's PID
 * @return 0
*/
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
	send_binary('\n', pid);
	return (0);
}
