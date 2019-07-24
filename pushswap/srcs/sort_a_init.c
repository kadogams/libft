/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:24:17 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:48:52 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to 'pre-'sort and partition the initial stack A, based on
** divide and conquer algorithms.
*/

void				init_backtrack_a(t_data **data, unsigned int n, int way)
{
	int	*tmp;

	tmp = (*data)->min;
	(*data)->min = (*data)->max - n + 1;
	(*data)->size = n;
	if (way == 1)
	{
		(*data)->t = (*data)->n + 1;
		while (!backtrack_a(data, 0, 0, 0))
			(*data)->t += 1;
	}
	else
	{
		while ((*data)->log->content == 5)
		{
			reverse_op(data, 5, &n);
			n--;
		}
		(*data)->t = (*data)->n + n;
		while (!backtrack_a(data, 0, n, 0))
			(*data)->t += 1;
	}
	(*data)->min = tmp;
	while ((*data)->size-- && (*data)->max != (*data)->min)
		(*data)->max -= 1;
}

static int			is_there_smaller(t_data **data, unsigned int u)
{
	t_stack *tmp;

	tmp = (*data)->a;
	while (u--)
	{
		if (tmp && tmp->content <= *(*data)->med)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static unsigned int	divide_n_conquer_a(t_data **data, unsigned int *n)
{
	unsigned int	u;
	unsigned int	count;

	u = *n;
	count = 0;
	while (is_there_smaller(data, u) && u--)
	{
		if ((*data)->a && (*data)->a->content <= *(*data)->med)
		{
			pb(data);
			count++;
			*n -= 1;
		}
		else
			ra(data);
	}
	return (count);
}

void				sort_a(t_data **data, unsigned int n, int median)
{
	unsigned int	count;
	int				*tmp;

	(*data)->med += median;
	tmp = (*data)->med;
	if (n > 6)
	{
		count = divide_n_conquer_a(data, &n);
		if (n)
			(n == 1) ? sort_a(data, n, 1) : sort_a(data, n, n / 2);
		(*data)->med = tmp;
		if (count)
			(count > 1) ? sort_b(data, count, -(int)(count / 2), 1)
					: sort_b(data, count, -(int)count, 1);
		(*data)->med = tmp;
	}
	else
		init_backtrack_a(data, n, 1);
}
