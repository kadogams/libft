/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:58:56 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/18 17:06:20 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label(t_asm *env, int j, int i)
{
	t_label	*new;

	if (!(new = (t_label*)malloc(sizeof(t_label))))
		return (KO);
	new->name = ft_strsub(env->line, j, i);
	new->index = env->index;
	new->next = NULL;
	if (new->name == NULL)
		return (KO);
	add_label(new, env);
	return (i + 1);
}
