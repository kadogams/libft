/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:09:56 by skadogam          #+#    #+#             */
/*   Updated: 2019/02/07 12:02:07 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		printf("usage a faire\n");
	else if (ac < 6)
		printf("parsing a faire\n");
	else
		write(2, "Too many champions\n", 19);
	return (0);
}
