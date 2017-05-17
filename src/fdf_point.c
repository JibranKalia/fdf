/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:57 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 01:20:04 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		scale(t_env *env)
{
	if (env->scale == 0)
		return ;
	printf("Before Scale:\n");
	mat_debug(env->mat);
	mat_scale(env->mat, env->scale, env->scale, env->scale);
	DEBUG("After Scale:");
	mat_debug(env->mat);
}


void		rotate(t_env *env)
{
//	printf("Before Rotate:\n");
//	mat_debug(env->mat);
	if (env->ax == 0 && env->ay == 0 && env->az == 0)
		return ;
	mat_rotate(env->mat, env->ax, env->ay, env->az);
	DEBUG("After Rotate:");
	mat_debug(env->mat);
}

void		translate(t_env *env)
{
//	printf("Before Translate:\n");
//	mat_debug(env->mat);
	if (env->xtrans == 0 && env->ytrans == 0)
		return ;
	mat_translate(env->mat, env->xtrans, env->ytrans, 0);
	DEBUG("After Translate:");
	mat_debug(env->mat);
}

/**
 * i = Wx + y
 * y = i/W
 * x = i - Wy
**/

void		applyalligned(t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->alligned, env->mat, env->points[i]->alligned);
	}
	DEBUG("APPLYALLIGNED");

}

void		applypoint(t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->local, env->mat, env->points[i]->alligned);
	}
	DEBUG("APPLYLOCAL");
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
	}
	//DEBUG("PUT TO IMG SEG");
}
