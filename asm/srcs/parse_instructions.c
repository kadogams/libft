/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:35:09 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/16 13:33:03 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	search_for_instr(t_asm *env, int i)
{
	int	start;
	int j;
	int	k;

	start = i;
	j = 0;
	k = 0;
	while (j < INSTR_SIZE)
	{
		while (env->line[i] == g_op[j].opcode[k])
		{
			if (g_op[j].size - 1 == k)
				return ((*g_op[j].ptr_fct)(env, j));
			i++;
			k++;
		}
		i = start;
		k = 0;
		j++;
	}
	return (KO);
}


int	parse_instructions(t_asm *env)
{
	int		i;
	int	ret;

	ft_printf("\n---------parse_instructions---------\n");
	while ((ret = skip_blank_lines(env)) > 0)
	{
		if ((i = skip_whitespace(env->line, env, UPDATE_X)) == -1)
		{
			ft_printf("KO");
			return(KO);
		}
			ft_printf("i ======== %d\n", i);
	ret = search_for_instr(env, i);
	if (ret == KO)
		return (KO);
	env->cur_x = 0;
	}
	if (ret == 0)
		return (OK);
	return (KO);
}
