/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:24:17 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:50:22 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to sort the stack B, based on divide and conquer algorithms.
*/

static unsigned int	divide_n_conquer_b(t_data **data, unsigned int *n)
{
	unsigned int	u;
	unsigned int	count;

	u = *n;
	count = 0;
	while (u--)
	{
		if ((*data)->b && (*data)->b->content >= *(*data)->med)
		{
			pa(data);
			count++;
			*n -= 1;
			while (count && deal_with_it(data))
				count--;
		}
		else
			rb(data);
	}
	return (count);
}

static unsigned int	rdivide_n_conquer_b(t_data **data, unsigned int *n)
{
	unsigned int	u;
	unsigned int	count;

	u = *n;
	count = 0;
	while (u--)
	{
		rrb(data);
		if ((*data)->b && (*data)->b->content >= *(*data)->med)
		{
			pa(data);
			count++;
			*n -= 1;
			while (count && deal_with_it(data))
				count--;
		}
	}
	return (count);
}

static void			init_backtrack_b(t_data **data, unsigned int n, int way)
{
	int	*tmp;

	tmp = (*data)->min;
	(*data)->min = (*data)->max - n + 1;
	(*data)->size = n;
	if (way == 1 || (way == -1 && (*data)->b->content >= *(*data)->min))
	{
		(*data)->t = (*data)->n + n;
		while (!backtrack_b(data, (*data)->size, 0, 0))
			(*data)->t += 1;
	}
	else
	{
		while ((*data)->log->content == 6)
		{
			reverse_op(data, 6, &n);
			n--;
		}
		(*data)->t = (*data)->n + (*data)->size + n;
		while (!backtrack_b(data, (*data)->size, 0, n))
			(*data)->t += 1;
	}
	(*data)->min = tmp;
	while ((*data)->size-- && (*data)->max != (*data)->min)
		(*data)->max -= 1;
}

void				sort_b(t_data **data, unsigned int n, int median, int way)
{
	unsigned int	count;
	int				*tmp;

	(*data)->med += median;
	tmp = (*data)->med;
	if (n)
	{
		if (n < 6)
			init_backtrack_b(data, n, way);
		else
		{
			if (way == 1)
				count = divide_n_conquer_b(data, &n);
			else
				count = rdivide_n_conquer_b(data, &n);
			if (count)
				(count > 1) ? sort_a2(data, count, (int)(count / 2), 1)
						: sort_a2(data, count, (int)(count), 1);
			(*data)->med = tmp;
			if (n)
				(n > 1) ? sort_b(data, n, -(int)(n / 2), -way)
						: sort_b(data, n, -1, -way);
			(*data)->med = tmp;
		}
	}
}
