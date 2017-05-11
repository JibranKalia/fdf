/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:57 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/11 14:24:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		scale(t_env *env)
{
	t_point		**tmp;
	int			i;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while(i < env->map->end)
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
	double		sumx;
	double		sumy;
	double		sumz;

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
	env->center.x = sumx / (double)i;
	env->center.y = sumy / (double)i;
	env->center.z = sumz / (double)i;
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

void	addpixels(t_env *env)
{
	int				i;
	t_point			**tmp;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while (i < env->map->end - 1)
	{
		drawline(tmp[i]->x, tmp[i]->y, tmp[i + 1]->x, tmp[i + 1]->y, env);
		//ft_3d_draw(*tmp[i], *tmp[i + 1], env);
		++i;
	}
}
