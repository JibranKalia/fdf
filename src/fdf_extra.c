/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:25:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/15 14:31:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		check_point(t_env *env)
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
