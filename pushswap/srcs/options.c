/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:38:37 by skadogam          #+#    #+#             */
/*   Updated: 2018/11/08 11:51:05 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print(t_stack *a, t_stack *a_head, t_stack *b, t_stack *b_head)
{
	system("clear");
	ft_printf("------------------------------------------------\n");
	ft_printf("\tstack a:\t|\tstack b:\t\n\t\t\t|\t\t\t\n");
	while (a || b)
	{
		ft_printf("\t");
		a ? ft_printf("%d", a->content) : 0;
		if (!a || (a->content < 10000000 && a->content > -999999))
			ft_printf("\t");
		ft_printf("\t|\t");
		b ? ft_printf("%d", b->content) : 0;
		if (!b || (b->content < 10000000 && b->content > -999999))
			ft_printf("\t");
		ft_printf("\t\n");
		a ? a = a->next : 0;
		b ? b = b->next : 0;
		(a == a_head) ? a = NULL : 0;
		(b == b_head) ? b = NULL : 0;
	}
	ft_printf("------------------------------------------------\n");
}
