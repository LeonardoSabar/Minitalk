/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:33:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/14 16:34:20 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void printBinary(char c, int i)
{
    if (i < 0)
    {
        printf("\n");
        return;
    }
    printf("%d", (c >> i) & 1);
    printBinary(c, i - 1);
}

int main() {
    char c = 'A';
    int i = 7;

    printf("Caractere: %c\n", c);
    printf("Representação binária: ");

    printBinary(c, i);

    return 0;
}
