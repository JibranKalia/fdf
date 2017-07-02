/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:58:21 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/02 10:17:03 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

#define XCHECK(x) ((x) < 0 || (x) >= env->win_w)
#define YCHECK(y) ((y) < 0 || (y) >= env->win_h)

void		create_color_table(t_env *env)
{
	int		i;
	float	red[3];
	float	green[3];
	float	blue[3];

	env->color = (int *)malloc(sizeof(int) * 50);
	red[0] = (float)(env->color1 >> 16 & 0xFF);
	red[1] = (float)(env->color2 >> 16 & 0xFF);
	green[0] = (float)(env->color1 >> 8 & 0xFF);
	green[1] = (float)(env->color2 >> 8 & 0xFF);
	blue[0] = (float)(env->color1 & 0xFF);
	blue[1] = (float)(env->color2 & 0xFF);
	i = -1;
	while (++i < 50)
	{
		red[2] = (float)(red[0] * i) / 50 + (float)(red[1] * (50 - i)) / 50;
		green[2] = (float)(green[0] * i) / 50
			+ (float)(green[1] * (50 - i)) / 50;
		blue[2] = (float)(blue[0] * i) / 50 + (float)(blue[1] * (50 - i)) / 50;
		env->color[i] = (int)red[2] << 16 | (int)green[2] << 8 | (int)blue[2];
	}
}

void		ft_putpixel(t_env *env, int x, int y, float z)
{
	float	layer;
	int		color;

	layer = ((z - env->zmin)
			/ (env->zmax - env->zmin)) * 50;
	color = env->color[abs((int)layer - 1)];
	if (XCHECK(x) || YCHECK(y))
		return ;
	env->img_data[(x + y * env->win_w)] = color;
}
