/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 00:27:55 by skadogam          #+#    #+#             */
/*   Updated: 2019/03/06 10:50:41 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "struct.h"

void	introduction(t_champi **champi)
{
	int	i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (champi[++i])
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				i + 1, champi[i]->weight, champi[i]->name, champi[i]->cmt);
}
