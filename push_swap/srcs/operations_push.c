/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:38:02 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 22:00:37 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_data **data)
{
	push(&(*data)->a, &(*data)->b);
	stacknew(&(*data)->log, PA);
	(*data)->n++;
	return (-1);
}

int	pb(t_data **data)
{
	push(&(*data)->b, &(*data)->a);
	stacknew(&(*data)->log, PB);
	(*data)->n++;
	return (1);
}
