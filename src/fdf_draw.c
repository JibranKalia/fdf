/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:46:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/08 14:27:28 by jkalia           ###   ########.fr       */
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
	int		incx;
	int		incy;
	int		err;
	int		e2;

//	swapcorrdinates(&x0, &y0, &x1, &y1);
	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	err= dx + dy;
	incx = (x0 < x1) ? 1 : -1;
	incy = (y0 < y1) ? 1 : -1;

	printf("dx = %d\n", dx);
	printf("dy = %d\n", dy);
	printf("sx = %d\n", incx);
	printf("sy = %d\n", incy);

	while (1)
	{
		set_pixel(x0, y0, env);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		printf("e2 = %d\n", e2);
		if (e2 >= dy)
		{
			err += dy;
			x0 += incx;
			printf("err = %d\n", err);
			printf("x0 = %d\n", x0);
			printf("dy = %d\n", dy);
		} /* e_xy+e_x > 0 */
		if (e2 <= dx)
		{
			err += dx;
			y0 += incy;
			printf("err = %d\n", err);
			printf("y0 = %d\n", y0);
			printf("dy = %d\n", dx);
		} /* e_xy+e_y < 0 */
	}
}
