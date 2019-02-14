#include "asm.h"

int		ft_live(t_asm *env, int i)
{
	int k;
	int j;

	k = env->cur_x + g_op[i].size;
	k += skip_whitespace(env->line + k, env, UPDATE_X);
	ft_printf("line %c -- k = %d", env->line[k], k);
	if (env->line[k] == '%')
	{
		env->code[env->index] = 0x01;
		ft_printf("code = %c\n", env->code[0]);
	}
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
