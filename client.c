/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:33:25 by leobarbo          #+#    #+#             */
/*   Updated: 2024/02/12 14:34:38 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

int	main()
{
	int value_returned;

	value_returned = system("ls -l /");
	return value_returned;
}
