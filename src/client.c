/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:33:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/19 09:34:26 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void send_binary(char *str, int pid)
{
    int idx;
    int bit_idx;

    idx = 0;
    while(str[idx])
    {
        bit_idx = 7;
        while (bit_idx >= 0)
        {
            if ((str[idx] >> bit_idx) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(100);
            bit_idx--;
        }
        idx++;
    }
}

void    check_args(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("A valid PID is required.\n");
        exit(1);
    }
    while (*argv[1])
    {
        if (!ft_isdigit(*argv[1]))
        {
            ft_printf("A valid PID is required.\n");
            exit(1);
        }
        argv[1]++;
    }
    if (ft_strlen(argv[2]) == 0)
    {
        ft_printf("A valid message is required.\n");
        exit(1);
    }
}

int main(int argc, char **argv)
{
    char    *str;
    int     pid;

    str = argv[2];
    check_args(argc, argv);
    pid = ft_atoi(argv[1]);
    send_binary(str, pid);
    while (1)
        pause();
    return 0;
}
