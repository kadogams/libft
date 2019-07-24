/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:29:47 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 20:51:32 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to check if an operation is worth executing.
*/

int	check_a(t_data **data)
{
	if (!(*data)->a)
		return (0);
	return (1);
}

int	check_a2(t_data **data)
{
	if (!(*data)->a || (*data)->a == (*data)->a->next)
		return (0);
	return (1);
}

int	check_b(t_data **data)
{
	if (!(*data)->b)
		return (0);
	return (1);
}

int	check_b2(t_data **data)
{
	if (!(*data)->b || (*data)->b == (*data)->b->next)
		return (0);
	return (1);
}

int	check_ab(t_data **data)
{
	if (!check_a2(data) || !check_b2(data))
		return (0);
	return (1);
}
