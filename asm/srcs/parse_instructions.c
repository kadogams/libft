/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:35:09 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/13 15:49:32 by dazheng          ###   ########.fr       */
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
			{
				(*g_op[j].ptr_fct)(env, j);
				return (OK);
			}
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

	i = 0;
	ft_printf("\nparse_instructions\n              ");
	if (!skip_blank_lines(env) && (i = skip_whitespace(env->line, env, UPDATE_X))
	== -1)
		{
			ft_printf("KO");
			return(KO);
		}
	i = skip_whitespace(env->line, env, UPDATE_X);
	search_for_instr(env, i);
	return (OK);
}
