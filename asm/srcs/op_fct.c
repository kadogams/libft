#include "asm.h"

int		get_codage(t_arg arg)
{
	int	res;

	ft_printf("\n\nargtype[0] = %d\n", arg.type[0]);
	ft_printf("value = %d\n", arg.value[0]);
	res = (arg.type[0] & 0b11111111) << 6;
	res += (arg.type[1] & 0b11111111) << 4;
	res += (arg.type[2] & 0b11111111) << 2;
	return (res);
}

void	fill_code(t_asm *env, int type, int value, int octet)
{
	int	bits;

	if (type == 1)
		env->code[env->index++] = value;
	else if (type == 3)
	{
		env->code[env->index++] = (value >> 8) & 0b11111111;
		env->code[env->index++] = value & 0b11111111;
	}
	else if (type == 2)
	{
		bits = octet == 2 ? 8 : 24;
		while (bits >= 0)
		{
			env->code[env->index++] = (value >> bits) & 0b11111111;
			bits -= 8;
		}
	}
	else
		return ;
}

int		ft_live(t_asm *env, int i, char *line)
{
	int		k;

	ft_printf("LIVE\n");
	t_arg	arg;
	init_arg(&arg, 4, 0);
	line = line + g_op[i].size;
	env->cur_x += g_op[i].size;
	if (!handle_arg(env, &arg, 0, line) || arg.type[0] != DIR_CODE
			|| arg.nb_arg != 1)
		return (KO);
	env->code[env->index++] = 0x01;
	fill_code(env, arg.type[0], arg.value[0], 4);
	return (OK);
}

int		ft_ld(t_asm *env, int i, char *line)
{
	int	k;
	t_arg arg;

	ft_printf("LD\n");
	init_arg(&arg, 4, 1);
	line = line + g_op[i].size;
	env->cur_x += g_op[i].size;
	if (!handle_arg(env, &arg, 0, line) || arg.nb_arg != 2 ||
	(arg.type[0] != IND_CODE && arg.type[0] != DIR_CODE) ||
	arg.type[1] != REG_CODE)
		return (KO);
	k = -1;
	env->code[env->index++] = 0x02;
	env->code[env->index++] = get_codage(arg);
	while (++k < arg.nb_arg)
		fill_code(env, arg.type[k], arg.value[k], 4);
	return (OK);
}

int		ft_st(t_asm *env, int i, char *line)
{
	int	k;
	t_arg arg;

	ft_printf("ST\n");
	init_arg(&arg, 4, 1);
	line = line + g_op[i].size;
	env->cur_x += g_op[i].size;
	if (!handle_arg(env, &arg, 0, line) || arg.nb_arg != 2 ||
	(arg.type[1] != REG_CODE && arg.type[1] != IND_CODE) || arg.type[0] !=
	REG_CODE)
		return (KO);
	k = -1;
	env->code[env->index++] = 0x03;
	env->code[env->index++] = get_codage(arg);
	while (++k < arg.nb_arg)
		fill_code(env, arg.type[k], arg.value[k], 4);
	return (OK);
}

int		ft_add(t_asm *env, int i, char *line)
{
	int	k;
	t_arg arg;

	ft_printf("ADD\n");
	init_arg(&arg, 0, 1);
	line = line + g_op[i].size;
	env->cur_x += g_op[i].size;
	if (!handle_arg(env, &arg, 0, line) || arg.nb_arg != 3 ||
	arg.type[0] != REG_CODE || arg.type[1] != REG_CODE || arg.type[2] !=
	REG_CODE)
		return (KO);
	k = -1;
	env->code[env->index++] = 0x04;
	env->code[env->index++] = get_codage(arg);
	while (++k < arg.nb_arg)
		fill_code(env, arg.type[k], arg.value[k], 0);
	return (OK);
}

int		ft_sub(t_asm *env, int i, char *line)
{
	int	k;
	t_arg arg;

	ft_printf("SUB\n");
	init_arg(&arg, 0, 1);
	line = line + g_op[i].size;
	env->cur_x += g_op[i].size;
	if (!handle_arg(env, &arg, 0, line) || arg.nb_arg != 3 ||
	arg.type[0] != REG_CODE || arg.type[1] != REG_CODE || arg.type[2] !=
	REG_CODE)
		return (KO);
	k = -1;
	env->code[env->index++] = 0x05;
	env->code[env->index++] = get_codage(arg);
	while (++k < arg.nb_arg)
		fill_code(env, arg.type[k], arg.value[k], 0);
	return (OK);
}
