#include "asm.h"

int		ft_live(t_asm *env, int i)
{
	int k;
	int j;
	int	nb;

	k = env->cur_x + g_op[i].size;
	k += skip_whitespace(env->line + k, env, UPDATE_X);
	ft_printf("line %c -- k = %d\n", env->line[k], k);
	if (env->line[k++] == '%')
		env->code[env->index++] = 0x01;
	ft_printf("code = %c\n", env->code[0]);
	j = skip_whitespace(env->line + k, env, UPDATE_X) + k;
	ft_printf("j = %d\n", j);
	nb = ft_atoi(env->line + j);
	env->code[env->index++] = (nb >> 24) & 0b11111111;
	env->code[env->index++] = (nb >> 16) & 0b11111111;
	env->code[env->index++] = (nb >> 8) & 0b11111111;
	env->code[env->index++] = nb & 0b11111111;
	return (OK);
}

int		ft_ld(t_asm *env, int i)
{
	ft_printf("ld\n");
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
