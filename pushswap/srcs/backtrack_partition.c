/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_partition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:40:26 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 21:55:26 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check if it is worth to do an operation on stack A
**
** :param data: data structure
** :param i: index of the operation
** :param na: current number of elements of the partition on stack A
** :param rot_a: indicator to know how many elements of the partition are on the
**     top of stack A (positive number) or at the bottom (negative number)
*/

static int	move_a_or_not(t_data **data, int i, unsigned int na, int rot_a)
{
	if (i == SA || i == SS)
	{
		if (na - rot_a < 2 || (*data)->a->content < (*data)->a->next->content)
			return (0);
	}
	else if (i == RA || i == RR)
	{
		if (na - rot_a < 1)
			return (0);
	}
	else if (i == RRA || i == RRR)
	{
		if (rot_a < 1)
			return (0);
	}
	return (1);
}

/*
** Check if it is worth to do an operation on stack B
**
** :param data: data structure
** :param i: index of the operation
** :param nb: current number of elements of the partition on stack B
** :param rot_b: indicator to know how many elements of the partition are on the
**     top of stack B (positive number) or at the bottom (negative number)
*/

static int	move_b_or_not(t_data **data, int i, unsigned int nb, int rot_b)
{
	if (i == SB || i == SS)
	{
		if (nb - rot_b < 2 || (*data)->b->content > (*data)->b->next->content)
			return (0);
	}
	else if (i == PA)
	{
		if (!nb || nb - rot_b < 1
				|| ((*data)->a && (*data)->a->content < (*data)->b->content))
			return (0);
	}
	else if (i == RB || i == RR)
	{
		if (nb - rot_b < 2)
			return (0);
	}
	else if (i == RRB || i == RRR)
	{
		if (rot_b < 1)
			return (0);
	}
	return (1);
}

/*
** Update the rot_a and rot_b params of the functions below according to
** the current operation.
**
** :param i: index of the operation
** :param rot_a: indicator to know how many elements of the partition are on the
**     top of stack A (positive number) or at the bottom (negative number)
** :param reverse: true if updating a reverse operation to cancel the previous one
*/

static void	rotation_log(int i, int *rot_a, int *rot_b, int reverse)
{
	if (i == RA)
		*rot_a += !reverse ? 1 : -1;
	else if (i == RB)
		*rot_b += !reverse ? 1 : -1;
	else if (i == RR)
	{
		*rot_a += !reverse ? 1 : -1;
		*rot_b += !reverse ? 1 : -1;
	}
	else if (i == RRA)
		*rot_a += !reverse ? -1 : 1;
	else if (i == RRB)
		*rot_b += !reverse ? -1 : 1;
	else if (i == RRR)
	{
		*rot_a += !reverse ? -1 : 1;
		*rot_b += !reverse ? -1 : 1;
	}
}

/*
** Selective backtracking to sort a partition on stack B (max. 5 elements).
** :param data: data structure
**
** :param nb: current number of elements of the partition on stack B
** :param rot_a: indicator to know how many elements of the partition are
** on the top of stack A (positive number) or at the bottom (negative number)
** :param rot_b: same as rot_a but on stack B
*/

int			backtrack_b(t_data **data, unsigned int nb, int rot_a, int rot_b)
{
	int	i;

	if (!nb && !rot_a && !rot_b && (*data)->a->content == *(*data)->min
			&& sorted_or_what(data, (*data)->size))
		return (1);
	i = 0;
	while (i <= MAX_OP && (*data)->n + nb + ft_abs(rot_a) + ft_abs(rot_b) < (*data)->t)
	{
		while (i == PB || (i <= MAX_OP && (!to_do_or_not_to_do(data, i)
				|| !move_a_or_not(data, i, (*data)->size - nb, rot_a)
				|| !move_b_or_not(data, i, nb, rot_b))))
			i++;
		if (i > MAX_OP)
			break ;
		nb += (*data)->op[i](data);
		rotation_log(i, &rot_a, &rot_b, 0);
		if (backtrack_b(data, nb, rot_a, rot_b))
			return (1);
		reverse_op(data, i, &nb);
		rotation_log(i, &rot_a, &rot_b, 1);
		i++;
	}
	return (0);
}

/*
** Selective backtracking to sort a partition on stack A (max. 5 elements).
** :param data: data structure
** :param nb: current number of elements of the partition on stack B
** :param rot_a: indicator to know how many elements of the partition are
** on the top of stack A (positive number) or at the bottom (negative number)
** :param rot_b: same as rot_a but on stack B
*/

int			backtrack_a(t_data **data, unsigned int nb, int rot_a, int rot_b)
{
	int	i;

	if (!nb && !rot_a && !rot_b && (*data)->a->content == *(*data)->min
			&& sorted_or_what(data, (*data)->size))
		return (1);
	i = 0;
	while (i <= MAX_OP && (*data)->n + nb + ft_abs(rot_a) + ft_abs(rot_b) < (*data)->t)
	{
		while (i <= MAX_OP && (!to_do_or_not_to_do(data, i)
				|| !move_a_or_not(data, i, (*data)->size - nb, rot_a)
				|| !move_b_or_not(data, i, nb, rot_b)))
			i++;
		if (i > MAX_OP)
			break ;
		nb += (*data)->op[i](data);
		rotation_log(i, &rot_a, &rot_b, 0);
		if (backtrack_b(data, nb, rot_a, rot_b))
			return (1);
		reverse_op(data, i, &nb);
		rotation_log(i, &rot_a, &rot_b, 1);
		i++;
	}
	return (0);
}
