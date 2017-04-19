/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:46:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/18 22:53:36 by jkalia           ###   ########.fr       */
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

void		swapcorrdinates(int *x0, int *y0, int *x1, int *y1)
{
	if (labs(*y1 - *y0) > labs(*x1 - *x0))
	{
		swapi(x0, y0);
		swapi(x1, y1);
	}
	if (*x0 > *x1)
	{
		swapi(x0, x1);
		swapi(y0, y1);
	}
}

void		drawline(int x0, int y0, int x1, int y1, t_env *env)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;

//	swapcorrdinates(&x0, &y0, &x1, &y1);
	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	err= dx + dy;
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;

	printf("dx = %d\n", dx);
	printf("dy = %d\n", dy);
	printf("sx = %d\n", sx);
	printf("sy = %d\n", sy);

	while (1)
	{
		set_pixel(x0, y0, env);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
			printf("err = %d\n", err);
			printf("x0 = %d\n", x0);
		} /* e_xy+e_x > 0 */
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
			printf("err = %d\n", err);
			printf("y0 = %d\n", y0);
		} /* e_xy+e_y < 0 */
	}
}
