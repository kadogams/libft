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

void	ft_error2(int option, t_asm *env)
{
	if (option == XOR)
		ft_printf("'xor' malformated at line [%d]\nxor: T_REG| T_DIR | "
		"T_IND, T_REG | T_DIR | T_IND, T_REG\n", env->cur_y);
	else if (option == ZJMP)
		ft_printf("'zjmp' malformated at line [%d]"
		"\nzjmp: T_DIR\n", env->cur_y);
	else if (option == LDI)
		ft_printf("'ldi' malformated at line [%d]\nldi: T_REG| T_DIR | "
		"T_IND, T_REG | T_DIR, T_REG\n", env->cur_y);
	else if (option == STI)
		ft_printf("'sti' malformated at line [%d]\nsti: T_REG, "
		"T_REG| T_DIR | T_IND, T_DIR | T_REG\n", env->cur_y);
	else if (option == FORK)
		ft_printf("'fork' malformated at line [%d]\nfork: T_DIR\n", env->cur_y);
	else if (option == LLD)
		ft_printf("'lld' malformated\nlld: T_DIR | T_IND, T_REG\n", env->cur_y);
	else if (option == LLDI)
		ft_printf("'lldi' malformated at line [%d]\nlldi: T_REG| T_DIR | T_IND,"
		"T_REG| T_DIR, T_REG\n", env->cur_y);
	else if (option == LFORK)
		ft_printf("'lfork' malformated at line [%d]\nlfork: T_DIR\n",
		env->cur_y);
	else if (option == AFF)
		ft_printf("'aff' malformated at line [%d]\naff: T_REG\n", env->cur_y);

}

int		ft_error(int option, t_asm *env)
{
	if (option == 1)
		ft_printf("Lexical error TOKEN[%d:%d]\n", env->cur_y, env->cur_x);
	else if (option == LIVE)
		ft_printf("'live' malformated at line [%d]\nlive: T_DIR\n", env->cur_y);
	else if (option == INSTR)
		ft_printf("No label or no instruction\n");
	else if (option == LD)
		ft_printf("'ld' malformated at line [%d]\nld: T_DIR | T_IND, T_REG\n", env->cur_y);
	else if (option == ADD)
		ft_printf("'add' malformated at line [%d]\nadd: T_REG, T_REG, T_REG\n", env->cur_y);
	else if (option == ST)
		ft_printf("'st' malformated at line [%d]\nst: T_REG | T_IND, T_REG\n", env->cur_y);
	else if (option == SUB)
		ft_printf("'sub' malformated at line [%d]\nsub: T_REG, T_REG, T_REG\n", env->cur_y);
	else if (option == AND)
		ft_printf("'and' malformated at line [%d]\nand: T_REG | T_DIR | T_IND,"
		"T_REG | T_DIR | T_IND, T_REG\n", env->cur_y);
	else if (option == OR)
		ft_printf("'or' malformated at line [%d]\nor: T_REG | T_DIR | T_IND,"
		"T_REG| T_DIR | T_IND, T_REG\n", env->cur_y);
	else if (option == CHAMP_MAX_SIZE)
		ft_printf("Champion size is too big!\n");
	else
		ft_error2(option, env);
	return (KO);
}

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
