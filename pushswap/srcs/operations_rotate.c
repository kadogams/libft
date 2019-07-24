/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:38:10 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 22:00:56 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_data **data)
{
	rotate(&(*data)->a);
	stacknew(&(*data)->log, RA);
	(*data)->n++;
	return (0);
}

int	rb(t_data **data)
{
	rotate(&(*data)->b);
	stacknew(&(*data)->log, RB);
	(*data)->n++;
	return (0);
}

int	rr(t_data **data)
{
	rotate(&(*data)->a);
	rotate(&(*data)->b);
	stacknew(&(*data)->log, RR);
	(*data)->n++;
	return (0);
}
