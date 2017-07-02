/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:57 by jkalia            #+#    #+#             */
/*   Updated: 2017/06/04 01:14:28 by jkalia           ###   ########.fr       */
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
	mat_translate(global, -(env->map_w / 2), -(env->map_height / 2), 0);
	mat_scale(global, env->scale, env->scale, env->scale);
	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->local, env->global,
				env->points[i]->world);
	}
}

void	world_to_aligned(t_env *env)
{
	float	global[4][4];
	int		i;

	mat_id(global);
	mat_rotate(global, env->ax, env->ay, env->az);
	mat_scale(global, (*env->scale) / env->map_w,
			(env->win_h * view->scale) / view->map_h, view->scale);
	mat_translate(global, (view->project) ? view->x_shift :
			view->x_shift + WIN_WIDTH / 2,
			(view->project) ? view->y_shift : view->y_shift + WIN_HEIGHT / 2,
			view->z_shift);

	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->world, env->global,
				env->points[i]->alligned);
	}
}

void		applyalligned(t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->alligned, env->mat,
				env->points[i]->alligned);
	}
}

void		applypoint(t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->local, env->mat,
				env->points[i]->alligned);
	}
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
