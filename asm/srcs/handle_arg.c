/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 09:03:47 by dazheng           #+#    #+#             */
/*   Updated: 2019/02/16 16:11:10 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		atoi_v2(const char *str, int *nb, t_asm *env)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	if (str[i] == '-')
	{
		i++;
		env->cur_x += 1;
		neg = -1;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		*nb = *nb * 10 + str[i] - '0';
		env->cur_x +=1;
		i++;
	}
	if (str[i] == '\0' || str[i] == ',')
		return (OK);
	return (KO);
}

int		get_label()
{
	ft_printf("get_label\n");
	return (1);
}

int		get_reg(t_asm *env, t_arg *arg, char *line)
{
	ft_printf("Get_reg\n");
	if (arg->nb_arg == 3)
		return (KO);
	arg->type[arg->nb_arg] = REG_CODE;
	if (!atoi_v2(line, &arg->value[arg->nb_arg], env))
		return (KO);
	arg->nb_arg++;
	return (OK);
}

int		get_dir(t_asm *env, t_arg *arg, char *line)
{
	ft_printf("get dir\n");
	if (arg->nb_arg == 3)
		return (KO);
	arg->type[arg->nb_arg] = DIR_CODE;
	if (line[0] == LABEL_CHAR)
		get_label();
	else
		if (!atoi_v2(line, &arg->value[arg->nb_arg], env))
			return (KO);
	arg->nb_arg++;
	return (OK);
}

int		get_ind(t_asm *env, t_arg *arg, char *line)
{
	ft_printf("get ind\n");
	if (arg->nb_arg == 3)
		return (KO);
	arg->type[arg->nb_arg] = IND_CODE;
	if (line[0] == LABEL_CHAR)
		get_label();
	else
		if (!atoi_v2(line, &arg->value[arg->nb_arg], env))
			return (KO);
	arg->nb_arg++;
	return (OK);
}

int		handle_arg(t_asm *env, t_arg *arg, int a, char *line)
{
	int	ret;
	int	i;

	i = 0;
	while (line[i])
	{
		if ((ret = skip_whitespace(line + i, env, UPDATE_X)) == -1)
			return (KO);
		i += ret;
		if (line[i] == DIRECT_CHAR)
			ret = get_dir(env, arg, line + i + 1);
		else if (line[i] == LABEL_CHAR || ft_isdigit(line[i]) || line[i] == '-')
			ret = get_ind(env, arg, line + i);
		else if (line[i] == 'r')
			ret = get_reg(env, arg, line + i + 1);
		else
			return (KO);
		if (ret == KO)
			return (KO);
		while (line[i] && line[i] != SEPARATOR_CHAR)
			i++;
		if (line[i] == SEPARATOR_CHAR)
			i++;
	}
	return (OK);
}
