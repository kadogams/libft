/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:25:03 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/18 15:04:02 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_label_arg(t_label_arg *new, t_asm *env)
{
	t_label_arg	*begin;

	if (env->label_arg == NULL)
	{
		env->label_arg = new;
		return ;
	}
	begin = env->label_arg;
	new->next = begin;
	env->label_arg = new;
}

void	add_label(t_label *new, t_asm *env)
{
	t_label	*begin;

	if (env->label == NULL)
	{
		env->label = new;
		return ;
	}
	begin = env->label;
	new->next = begin;
	env->label = new;
}
