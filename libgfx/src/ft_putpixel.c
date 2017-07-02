/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:58:21 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/02 09:03:07 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

#define XCHECK(x) ((x) < 0 || (x) >= env->win_w)
#define YCHECK(y) ((y) < 0 || (y) >= env->win_h)

static int	pick_some_more(int layer, char box)
{
	int	color;

	color = 0;
	if (layer == 4)
	{
		color = box == 'a' ? 3368499 : color;
		color = box == 'b' ? 0x33FF00 : color;
		color = box == 'c' ? 0x00FF00 : color;
	}
	else if (layer == 5)
	{
		color = box == 'a' ? 15195750 : color;
		color = box == 'b' ? 26367 : color;
		color = box == 'c' ? 0xFF0000 : color;
	}
	else if (layer == 6)
	{
		color = box == 'a' ? 26367 : color;
		color = box == 'b' ? 0x9900CC : color;
		color = box == 'c' ? 0xFF0000 : color;
	}
	return (color);
}

int			pick_color(int layer, char box)
{
	int	color;

	color = 0;
	if (layer == 1)
	{
		color = box == 'a' ? 16514043 : color;
		color = box == 'b' ? 0xFF0000 : color;
		color = box == 'c' ? 0x0000FF : color;
	}
	else if (layer == 2)
	{
		color = box == 'a' ? 7500402 : color;
		color = box == 'b' ? 0xE55E31 : color;
		color = box == 'c' ? 0x0000FF : color;
	}
	else if (layer == 3)
	{
		color = box == 'a' ? 6697728 : color;
		color = box == 'b' ? 0xFFFF00 : color;
		color = box == 'c' ? 0x00FF00 : color;
	}
	else if (layer > 3)
		color = pick_some_more(layer, box);
	return (color);
}

void		ft_putpixel(t_env *env, int x, int y, int z)
{
//	int		layer;
//	int		color;

	(void)z;

	/**
	layer = (env->zmax - env->zmin) / z;
	DEBUG("%d", layer);
	color = pick_color((int)layer, 'a');
	**/
	if (XCHECK(x) || YCHECK(y))
		return ;
	env->img_data[(x + y * env->win_w)] = env->color;
}
