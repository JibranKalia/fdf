/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:57 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/15 15:20:26 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		scale(t_env *env)
{
	env->scale_x = (env->win_h / env->map_h) / 1.5;
	env->scale_y = (env->win_h / env->map_h) / 1.5;
	env->scale_z = (env->win_h / env->map_h) / 1.5;
	printf("Before Scale:\n");
	mat_debug(env->mat);
	mat_scale(env->mat, env->scale_x, env->scale_y, env->scale_z);
	printf("After Scale:\n");
	mat_debug(env->mat);
}


void		rotate(t_env *env)
{
	printf("Before Rotate:\n");
	mat_debug(env->mat);
	mat_rotate(env->mat, 0.2, .1, .1);
	printf("After Rotate:\n");
	mat_debug(env->mat);
	DEBUG("ROTATE SEG");
}

void		translate(t_env *env)
{
	printf("Before Translate:\n");
	mat_debug(env->mat);
	mat_translate(env->mat, 5, 5, 0);

	printf("After Translate:\n");
	mat_debug(env->mat);
}

/**
 * i = Wx + y
 * y = i/W
 * x = i - Wy
**/

void		applypoint(t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->local, env->mat, env->points[i]->alligned);
	}
	DEBUG("APPLY TO POINT SEG");
}

void		puttoimg(t_env *env)
{
	int					x;
	int					y;
	t_vertex			**tmp;

	x = 0;
	y = 0;
	tmp = env->points;
	while (y < env->map_h)
	{
		if (x < env->map_w - 1)
			ft_3d_draw(env, *tmp[INDEX(x, y)]->alligned, *tmp[INDEX(x + 1, y)]->alligned);
		if (y < env->map_h - 1)
			ft_3d_draw(env, *tmp[INDEX(x, y)]->alligned, *tmp[INDEX(x, y + 1)]->alligned);
		if (x == env->map_w - 1)
		{
			y++;
			x = 0;
		}
		else
			x++;
		//DEBUG("X = %d\n", x);
		//DEBUG("Y = %d\n", y);
	}
	DEBUG("PUT TO IMG SEG");
}
