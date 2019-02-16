/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:03:49 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/16 10:51:09 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	init_env(t_asm *env)
{
	env->line = NULL;
	env->cur_x = 0;
	env->cur_y = 0;
	ft_bzero(env->code, CHAMP_MAX_SIZE);
	env->index = 0;
	env->label = NULL;
	env->zjump = NULL; 
	return (1);
}

void	init_arg(t_arg *arg)
{
	int	i;

	i = -1;
	arg->nb_arg = 0;
	while (++i < 3)
	{
		arg->value[i] = 0;
		arg->type[i] = 0;
	}
}
