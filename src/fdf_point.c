/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:57 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/02 06:46:23 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** i = Wx + y
** y = i/W
** x = i - Wy
*/

void	local_to_world(t_env *env)
{
	float	global[4][4];
	int		i;

	mat_id(global);
	mat_translate(global, -(env->map_w / 2), -(env->map_h / 2), 0);
	mat_scale(global, env->scale, env->scale, env->scale);

	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->local, global,
				env->points[i]->world);
	}
}

void	world_to_aligned(t_env *env)
{
	float	global[4][4];
	int		i;

	mat_id(global);
	mat_rotate(global, env->ax, env->ay, env->az);
//	mat_scale(global, env->scale / env->map_w,
//						env->scale / env->map_h, env->scale);
	mat_scale(global, (env->win_w * env->scale) / env->map_w,
						(env->win_h * env->scale) / env->map_h, env->scale);
	mat_translate(global, env->xtrans, env->ytrans, env->ztrans);
	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->world, global,
				env->points[i]->alligned);
	}
}

void		draw_wireframe(t_env *env)
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
			ft_3d_draw(env, *tmp[INDEX(x, y)]->alligned,
					*tmp[INDEX(x + 1, y)]->alligned);
		if (y < env->map_h - 1)
			ft_3d_draw(env, *tmp[INDEX(x, y)]->alligned,
					*tmp[INDEX(x, y + 1)]->alligned);
		if (x == env->map_w - 1)
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
}
