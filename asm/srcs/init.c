/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:03:49 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/11 15:23:17 by dazheng          ###   ########.fr       */
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
