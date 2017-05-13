/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:30:49 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/12 20:42:59 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

void		ft_3d_draw(t_env *env, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		incx;
	int		incy;
	int		err;
	int		e2;

	dx = fabs(p1.x - p0.x);
	dy = -fabs(p1.y - p0.y);
	err = dx + dy;
	incx = (p0.x < p1.x) ? 1 : -1;
	incy = (p0.y < p1.y) ? 1 : -1;
	while (1)
	{
		ft_putpixel(env, p0.x, p0.y);
		if (p0.x == p1.x && p0.y == p1.y)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			p0.x += incx;
		}
		if (e2 <= dx)
		{
			err += dx;
			p0.y += incy;
		}
	}
}
