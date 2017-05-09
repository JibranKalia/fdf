/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:46:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/09 14:06:34 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define XCHECK(x) ((x) < 0 || (x) >= WIN_WIDTH)
#define YCHECK(y) ((y) < 0 || (y) >= WIN_HEIGHT)


void	swapi(int *x, int *y)
{
	int		tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

void		set_pixel(int x, int y, t_env *env)
{
	if (XCHECK(x) || YCHECK(y))
		return ;
	env->img_data[(x + y * WIN_WIDTH)] = COLOR1;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void		drawline(int x0, int y0, int x1, int y1, t_env *env)
{
	int		dx;
	int		dy;
	int		incx;
	int		incy;
	int		err;
	int		e2;

	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	err= dx + dy;
	incx = (x0 < x1) ? 1 : -1;
	incy = (y0 < y1) ? 1 : -1;
	while (1)
	{
		set_pixel(x0, y0, env);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += incx;
		} /* e_xy+e_x > 0 */
		if (e2 <= dx)
		{
			err += dx;
			y0 += incy;
		} /* e_xy+e_y < 0 */
	}
}
