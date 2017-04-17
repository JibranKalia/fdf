/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 12:46:05 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/17 13:08:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define XCHECK(x) ((x) < 0 || (x) >= WIN_WIDTH)
#define YCHECK(y) ((y) < 0 || (y) >= WIN_HEIGHT)

void		set_pixel(t_env *env, int x, int y)
{
	if (XCHECK(x) || YCHECK(y))
		return ;
	env->img_data[x + y * env->ln] = COLOR1;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void		drawline(int x0, int y0, int x1, int y1, t_env *env)
{
	int		deltax;
	int		deltay;
	int		deltaerr;
	int		y;
	int		x;

	if (XCHECK(x0) || YCHECK(y0) || XCHECK(x1) || YCHECK(y1))
		return ;

	deltax = x1 - x0;
	deltay = y1 - y0;
	deltaerr = 2 * deltay - deltax;
	y = y0;
	x = x0;

	while (x < x1)
	{
		set_pixel(env, x, y);
		if (deltaerr > 0)
		{
			++y;
			deltaerr = deltaerr - 2 * deltax;
		}
		else
			deltaerr = deltaerr + 2 * deltay;
	}
}
