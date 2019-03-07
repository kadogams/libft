/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:14:10 by adefonta          #+#    #+#             */
/*   Updated: 2019/02/22 02:41:04 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "visu_struct.h"

void	del_param(t_param *param)
{
	int		i;
	t_mlx	*mlx;

	if (param)
	{
		mlx = param->mlx;
		i = 0;
		if (mlx)
		{
			if (param->img)
			{
				mlx_destroy_image(param->mlx->ptr, param->img->ptr);
				free(param->img);
			}
			if (mlx->ptr && mlx->win)
			{
				mlx_clear_window(mlx->ptr, mlx->win);
				mlx_destroy_window(mlx->ptr, mlx->win);
			}
			free(mlx);
		}
		free(param);
	}
	exit(0);
}
