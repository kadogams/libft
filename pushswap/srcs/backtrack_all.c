/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:29:25 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:54:01 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Cancel out the previous operation and deletes it from the log.
*/

void	reverse_op(t_data **data, int i, unsigned int *nb)
{
	*nb += (*data)->rop[i](data);
	stackdelone(&(*data)->log);
	stackdelone(&(*data)->log);
	(*data)->n -= 2;
}

/*
** Check if every elements are sorted in the A stack.
*/

int		sorted_or_what(t_data **data, unsigned int size)
{
	t_stack			*tmp;

	if (!(*data)->a)
		return (0);
	tmp = (*data)->a->next;
	while (--size)
	{
		if (tmp->previous->content >= tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
** Check if the current operation is worth executing: if the current operation
** is not cancelling out the previous one, etc.
*/

int		to_do_or_not_to_do(t_data **data, int i)
{
	if (i == PA && !(*data)->a)
		return (1);
	else if (((*data)->log && (*data)->op[i] ==
			(*data)->rop[(*data)->log->content]) || !(*data)->check_op[i](data))
		return (0);
	return (1);
}

/*
** Backtracking function on both stacks until sorted.
*/

int		omae_wa_mou_shindeiru(t_data **data, unsigned int nb)
{
	int		i;

	if (!(*data)->b && sorted_or_what(data, (*data)->size))
		return (1);
	i = 0;
	while (i <= MAX_OP && (*data)->n + nb < (*data)->t)
	{
		while (i <= MAX_OP && !to_do_or_not_to_do(data, i))
			i++;
		if (i > MAX_OP)
			break ;
		nb += (*data)->op[i](data);
		if (omae_wa_mou_shindeiru(data, nb))
			return (1);
		reverse_op(data, i, &nb);
		i++;
	}
	return (0);
}
