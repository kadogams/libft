/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:38:30 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/24 22:01:42 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_data **data)
{
	swap(&(*data)->a);
	stacknew(&(*data)->log, SA);
	(*data)->n++;
	return (0);
}

int	sb(t_data **data)
{
	swap(&(*data)->b);
	stacknew(&(*data)->log, SB);
	(*data)->n++;
	return (0);
}

int	ss(t_data **data)
{
	swap(&(*data)->a);
	swap(&(*data)->b);
	stacknew(&(*data)->log, SS);
	(*data)->n++;
	return (0);
}
