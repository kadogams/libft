/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:37:55 by skadogam          #+#    #+#             */
/*   Updated: 2018/10/17 17:55:06 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	tmp->previous = (*head)->previous;
	(*head)->previous->next = tmp;
	(*head)->previous = tmp;
	(*head)->next = tmp->next;
	tmp->next->previous = *head;
	tmp->next = *head;
	*head = tmp;
}

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = ((*src) == (*src)->next) ? NULL : (*src)->next;
	if (tmp)
	{
		(*src)->previous->next = tmp;
		tmp->previous = (*src)->previous;
	}
	if (*dst)
	{
		(*src)->previous = (*dst)->previous;
		(*src)->next = *dst;
		(*dst)->previous->next = *src;
		(*dst)->previous = *src;
	}
	else
	{
		(*src)->previous = *src;
		(*src)->next = *src;
	}
	*dst = *src;
	*src = tmp;
}

void	rotate(t_stack **head)
{
	if (!*head)
		return ;
	(*head) = (*head)->next;
}

void	rrotate(t_stack **head)
{
	if (!*head)
		return ;
	*head = (*head)->previous;
}
