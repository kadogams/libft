/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:24:17 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:49:38 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to sort the stack A, based on divide and conquer algorithms.
*/

static unsigned int	divide_n_conquer_a2(t_data **data, unsigned int *n)
{
	unsigned int	u;
	unsigned int	count;

	u = *n;
	count = 0;
	while (u--)
	{
		if (deal_with_it(data))
			*n -= 1;
		else if ((*data)->a && (*data)->a->content <= *(*data)->med)
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

static unsigned int	rdivide_n_conquer_a2(t_data **data, unsigned int *n)
{
	unsigned int	u;
	unsigned int	count;

	u = *n;
	count = 0;
	while (u--)
	{
		rra(data);
		if (deal_with_it(data))
			*n -= 1;
		if ((*data)->a && (*data)->a->content <= *(*data)->med
				&& (*data)->a->content < *(*data)->max)
		{
			pb(data);
			count++;
			*n -= 1;
		}
	}
	return (count);
}

void				sort_a2(t_data **data, unsigned int n, int median, int way)
{
	unsigned int	count;
	int				*tmp;

	(*data)->med += median;
	tmp = (*data)->med;
	if (n)
	{
		if (n < 6)
			init_backtrack_a(data, n, way);
		else
		{
			if (way == 1)
				count = divide_n_conquer_a2(data, &n);
			else
				count = rdivide_n_conquer_a2(data, &n);
			if (n)
				(n > 1) ? sort_a2(data, n, n / 2, -way)
						: sort_a2(data, n, 1, -way);
			(*data)->med = tmp;
			if (count)
				(count > 1) ? sort_b(data, count, -(int)(count / 2), 1)
						: sort_b(data, count, -(int)count, 1);
			(*data)->med = tmp;
		}
	}
}
