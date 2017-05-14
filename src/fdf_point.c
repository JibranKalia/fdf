/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vec3f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:57 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/13 22:54:50 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	check_point(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->map->end)
	{
		printf("local x = %.0f alligned x = %.0f\n", env->points[i]->local->x, env->points[i]->alligned->x);
		printf("y = %.0f y = %.0f\n", env->points[i]->local->y, env->points[i]->alligned->y);
		printf("z = %.0f z = %.0f\n", env->points[i]->local->z, env->points[i]->alligned->z);
		printf("i = %d\n", i);
		++i;
	}
	return (0);
}

void		scale(t_env *env)
{
	int		i;
	float		mat[4][4];

	env->scale_x =  (env->win_h / env->map_h) / 1.5;
	env->scale_y =  (env->win_h / env->map_h) / 1.5;
	env->scale_z = 	(env->win_h / env->map_h) / 1.5;
	mat_id(mat);
	mat_debug(mat);
	mat_rotate(mat, 0.1, 0, 0);
	printf("After\n");
	mat_debug(mat);
	mat_scale(mat, env->scale_x, env->scale_y, env->scale_z);
	mat_translate(mat, +5, +5, 0);
	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->local, mat, env->points[i]->alligned);
	}
}

void		centerfind(t_env *env)
{
	t_vec3f		**tmp;
	int			i;
	int			sumx;
	int			sumy;
	int			sumz;

	i = 0;
	sumx = 0;
	sumy = 0;
	sumz = 0;
	tmp = (t_vec3f **)env->map->contents;
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

void		xrot(t_env *env)
{
	int		i;
	float		mat[4][4];

	mat_id(mat);
	i = -1;
	while (++i < env->max_point)
	{
		vec_mat_mult(env->points[i]->alligned, mat, env->points[i]->alligned);
	}
}

void		xrotation(t_env *env, float rad)
{
	int				i;
	t_rotation		r_vec3fs;
	t_vec3f			**tmp;

	i = 0;
	tmp = (t_vec3f **)env->map->contents;
	while (i < env->map->end)
	{
		r_vec3fs.y = tmp[i]->y - env->center.y;
		r_vec3fs.z = tmp[i]->z - env->center.z;
		r_vec3fs.d = hypot(r_vec3fs.y, r_vec3fs.z);
		r_vec3fs.theta = atan2(r_vec3fs.y, r_vec3fs.z) + rad;
		tmp[i]->z = r_vec3fs.d * cos(r_vec3fs.theta) + env->center.z;
		tmp[i]->y = r_vec3fs.d * sin(r_vec3fs.theta) + env->center.y;
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
	t_vertex			**tmp;

	x = 0;
	y = 0;
	tmp = env->points;
	//vec_mat_mult(env->points[i]->local, mat, env->points[i]->alligned);
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
}

void		pad(t_env *env)
{

	int				i;
	t_vec3f			**tmp;

	i = 0;
	tmp = (t_vec3f **)env->map->contents;
	while (i < env->map->end)
	{
		tmp[i]->x += (env->win_w) / 4;
		tmp[i]->y += (env->win_h) / 4;
		++i;
	}
}
