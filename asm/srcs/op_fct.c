#include "asm.h"

int		ft_live(t_asm *env, int i)
{
	int k;
	int j;
	int	nb;

	k = env->cur_x + g_op[i].size;
	env->cur_x += g_op[i].size;
	k += skip_whitespace(env->line + k, env, UPDATE_X);
	if (env->line[k] == DIRECT_CHAR)
		env->code[env->index++] = 0x01;
	j = skip_whitespace(env->line + k, env, UPDATE_X) + k;
	ft_printf("char = %c et j = %d\n", env->line[j], j);
	if (check_space_digit(env->line + j, env))
	{
		nb = ft_atoi(env->line + j);
		ft_printf("NB = %d\n", nb);
		env->code[env->index++] = (nb >> 24) & 0b11111111;
		env->code[env->index++] = (nb >> 16) & 0b11111111;
		env->code[env->index++] = (nb >> 8) & 0b11111111;
		env->code[env->index++] = nb & 0b11111111; =
		ft_printf("SHIFT = %c\n", nb & 0b11111111);
		ft_printf("code = %c\n", env->code[env->index - 1]);
		return (OK);
	}
	ft_printf("Live a fail\n");
	return (KO);
}

int		ft_ld(t_asm *env, int i)
{
	int	k;
	int	j;
	int nb;
	t_instr *prm;


	k = env->cur_x + g_op[i].size;
	env->cur_x += g_op[i].size;
	k += skip_whitespace(env->line + k, env, UPDATE_X);
	if (env->line[k] == DIRECT_CHAR || ft_isdigit(env->line[k]))
	{
		env->code[env->index++] = 0x02;
		handle_params(env, param)
	}
	return (OK);
}

int		ft_st(t_asm *env, int i)
{
	ft_printf("st\n");
	return (OK);
}

int		ft_add(t_asm *env, int i)
{
	ft_printf("add\n");
	return (OK);
}

int		ft_sub(t_asm *env, int i)
{
	ft_printf("sub\n");
	return (OK);
}
