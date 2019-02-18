/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fct4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:32:04 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/18 18:14:48 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_aff(t_asm *env, int i, char *line)
{
	int	k;
	t_arg arg;

	ft_printf("AFF\n");
	init_arg(&arg, 0, 1);
	line = line + g_op[i].size;
	env->cur_x += g_op[i].size;
	if (!handle_arg(env, &arg, 0, line) || arg.nb_arg != 1 || arg.type[0] !=
	REG_CODE)
		return (KO);
	k = -1;
	env->code[env->index++] = 0x10;
	env->code[env->index++] = get_codage(arg);
	while (++k < arg.nb_arg)
		fill_code(env, arg.type[k], arg.value[k], 0);
	return (OK);
}
