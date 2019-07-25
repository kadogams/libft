/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadogam <skadogam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:37:48 by skadogam          #+#    #+#             */
/*   Updated: 2019/07/25 10:18:59 by skadogam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Functions to init structures.
*/

void	stacknew(t_stack **head, int content)
{
	t_stack	*new;

	if (!(new = (t_stack*)malloc(sizeof(*new))))
		return ;
	new->content = content;
	if (*head)
	{
		new->next = *head;
		new->previous = (*head)->previous;
		(*head)->previous->next = new;
		(*head)->previous = new;
	}
	else
	{
		new->previous = new;
		new->next = new;
	}
	*head = new;
}

void	stackdelone(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	else if ((*stack) == (*stack)->next)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		tmp = (*stack)->next;
		(*stack)->previous->next = (*stack)->next;
		(*stack)->next->previous = (*stack)->previous;
		free(*stack);
		*stack = NULL;
		*stack = tmp;
	}
}

void	stackdel(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	(*stack)->previous->next = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = tmp;
	}
}

t_data	*init_data(void)
{
	t_data	*new;

	if (!(new = (t_data*)malloc(sizeof(*new))))
		return (NULL);
	new->a = NULL;
	new->b = NULL;
	new->log = NULL;
	new->res = NULL;
	new->med = NULL;
	new->min = NULL;
	new->max = NULL;
	new->size = 0;
	new->n = 0;
	new->t = 1;
	init_op(new->op, new->rop);
	init_check_op(new->check_op);
	new->options = 0;
	return (new);
}

void	delete_data(t_data **data)
{
	if (!*data)
		return ;
	stackdel(&(*data)->a);
	stackdel(&(*data)->b);
	stackdel(&(*data)->log);
	free((*data)->res);
	(*data)->res = NULL;
	(*data)->med = NULL;
	(*data)->min = NULL;
	(*data)->max = NULL;
	free(*data);
	*data = NULL;
}
