/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:38:21 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 22:01:16 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_data **data)
{
	rrotate(&(*data)->a);
	stacknew(&(*data)->log, RRA);
	(*data)->n++;
	return (0);
}

int	rrb(t_data **data)
{
	rrotate(&(*data)->b);
	stacknew(&(*data)->log, RRB);
	(*data)->n++;
	return (0);
}

int	rrr(t_data **data)
{
	rrotate(&(*data)->a);
	rrotate(&(*data)->b);
	stacknew(&(*data)->log, RRR);
	(*data)->n++;
	return (0);
}
