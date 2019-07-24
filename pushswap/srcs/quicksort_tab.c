/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:38:51 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:44:42 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to sort an int array and check if there are no duplicates.
*/

static void	swap_tab(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

static int	partition_tab(int *res, int l, int h)
{
	int pivot;
	int	i;
	int	j;

	pivot = res[h];
	i = l - 1;
	j = l;
	while (j < h)
	{
		if (res[j] < pivot)
			swap_tab(&res[++i], &res[j]);
		j++;
	}
	swap_tab(&res[++i], &res[h]);
	return (i);
}

void		quicksort_tab(int *res, int l, int h)
{
	int	p;

	if (l < h)
	{
		p = partition_tab(res, l, h);
		quicksort_tab(res, l, p - 1);
		quicksort_tab(res, p + 1, h);
	}
}

void		check_tab(t_data **data, unsigned int n)
{
	int	*tmp;

	tmp = (*data)->res;
	while (--n)
	{
		if (*tmp >= *(tmp + 1))
			quit(data);
		tmp += 1;
	}
}
