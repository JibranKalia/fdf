/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:57 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/12 20:11:36 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		scale(t_env *env)
{
	t_point		**tmp;
	int				i;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while (i < env->map->end)
	{
		tmp[i]->x *= ((env->win_h / env->map_h) / 2);
		tmp[i]->y *= ((env->win_h / env->map_h) / 2);
		tmp[i]->z *= ((env->win_w / env->map_w) / 2);
		++i;
	}
}

void		centerfind(t_env *env)
{
	t_point		**tmp;
	int			i;
	int			sumx;
	int			sumy;
	int			sumz;

	i = 0;
	sumx = 0;
	sumy = 0;
	sumz = 0;
	tmp = (t_point **)env->map->contents;
	while(i < env->map->end)
	{
		sumx += tmp[i]->x;
		sumy += tmp[i]->y;
		sumz += tmp[i]->z;
		++i;
	}
	env->center.x = sumx / i;
	env->center.y = sumy / i;
	env->center.z = sumz / i;
}

void		xrotation(t_env *env, float rad)
{
	int				i;
	t_rotation		r_points;
	t_point			**tmp;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while (i < env->map->end)
	{
		r_points.y = tmp[i]->y - env->center.y;
		r_points.z = tmp[i]->z - env->center.z;
		r_points.d = hypot(r_points.y, r_points.z);
		r_points.theta = atan2(r_points.y, r_points.z) + rad;
		tmp[i]->z = r_points.d * cos(r_points.theta) + env->center.z;
		tmp[i]->y = r_points.d * sin(r_points.theta) + env->center.y;
		++i;
	}
}

/**
 * i = Wx + y
 * y = i/W
 * x = i - Wy
**/

void		puttoimg(t_env *env)
{
	int				x;
	int				y;
	t_point			**tmp;

	x = 0;
	y = 0;
	tmp = (t_point **)env->map->contents;
	while (y < env->map_h)
	{
		if (x < env->map_w - 1)
			ft_3d_draw(env, *tmp[INDEX(x, y)], *tmp[INDEX(x + 1, y)]);
		if (y < env->map_h - 1)
			ft_3d_draw(env, *tmp[INDEX(x, y)], *tmp[INDEX(x, y + 1)]);
		if (x == env->map_w - 1)
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
}

void		pad(t_env *env)
{

	int				i;
	t_point			**tmp;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while (i < env->map->end)
	{
		tmp[i]->x += (env->win_w) / 4;
		tmp[i]->y += (env->win_h) / 4;
		++i;
	}
}
