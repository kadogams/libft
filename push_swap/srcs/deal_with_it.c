/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_it.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:22:16 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:39:55 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to check if the top the stack A is already sorted, or can be
** sorted easily.
*/

static int	deal_with_it2(t_data **data)
{
	t_stack	*tmp;

	tmp = (*data)->a;
	while (tmp)
	{
		if (tmp->content == *(*data)->max
				&& (tmp->next->content == *((*data)->max + 1)
				|| tmp->next == (*data)->a))
		{
			(*data)->max -= 1;
			return (1);
		}
		tmp = tmp->next;
		if (tmp->content == *((*data)->max + 1) || tmp == (*data)->a)
			break ;
	}
	return (0);
}

int			deal_with_it(t_data **data)
{
	if (!(*data)->a)
		return (0);
	else if ((*data)->a->content == *(*data)->max)
	{
		if ((*data)->a->next->content == *((*data)->max + 1)
				|| (*data)->a == (*data)->a->next)
		{
			(*data)->max -= 1;
			return (1);
		}
		else if ((*data)->a->next->next->content == *((*data)->max + 1)
				|| (*data)->a == (*data)->a->next->next)
		{
			sa(data);
			return (deal_with_it(data));
		}
	}
	else
		return (deal_with_it2(data));
	return (0);
}
