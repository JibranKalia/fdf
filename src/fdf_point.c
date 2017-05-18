/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:57 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 19:48:52 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** i = Wx + y
** y = i/W
** x = i - Wy
*/

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
