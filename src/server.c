/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:52:53 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/19 09:40:19 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../lib/printf/includes/ft_printf.h"

void	handler(int signal)
{
	static char	c;
	static int	bit;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			exit(0);
		}
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}

}

int main(void)
{
	printf("Welcome to Minitalk!\n");
	printf("The PID number is: %d\n", getpid());
	while (1)
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
