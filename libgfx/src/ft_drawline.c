/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:30:49 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 20:21:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>
#define BREAK(a) if(1){if(a){break;};}

void		drawline(t_env *env, t_ixy src0, t_ixy src1)
{
	t_ixy	d;
	t_ixy	inc;
	int		err[2];

	d.x = abs(src1.x - src0.x);
	d.y = -abs(src1.y - src0.y);
	inc.x = (src0.x < src1.x) ? 1 : -1;
	inc.y = (src0.y < src1.y) ? 1 : -1;
	err[0] = d.x + d.y;
	while (1)
	{
		ft_putpixel(env, src0.x, src0.y);
		BREAK(src0.x == src1.x && src0.y == src1.y);
		err[1] = 2 * err[0];
		if (err[1] >= d.y)
		{
			err[0] += d.y;
			src0.x += inc.x;
		}
		if (err[1] <= d.x)
		{
			err[0] += d.x;
			src0.y += inc.y;
		}
	}
}

void		ft_3d_draw(t_env *env, t_vec3f p0, t_vec3f p1)
{
	drawline(env, (t_ixy){p0.x, p0.y}, (t_ixy){p1.x, p1.y});
}
