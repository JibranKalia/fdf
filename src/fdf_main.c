/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:07:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/09 16:19:06 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

#define ESC		53
#define W		13
#define S		1
#define A		0
#define D		2
#define UP		126
#define DOWN		125
#define RIGHT		124
#define LEFT		123
#define PAGE_UP		116
#define PAGE_DOWN	121

void	ft_perror(const char *s)
{
	ft_printf("%{red}%s%{eoc}\n", s);
	exit(EXIT_FAILURE);
}

static int	key_hooks(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		//mlx_destroy_window(env->mlx, env->win);
		//mlx_destroy_image(env->mlx, env->img);
		exit(EXIT_SUCCESS);
	}
	(void)env;
	return (0);
}

void		scale(t_env *env)
{
	t_point		**tmp;
	int			i;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while(i < env->map->end)
	{
		tmp[i]->x *= ((env->win_h / env->map_h) / 2);
		tmp[i]->y *= ((env->win_h / env->map_h) / 2);
		tmp[i]->z *= ((env->win_w / env->map_w) / 2);
		++i;
	}
}

void		centerfind(t_env *env)
{
	t_point		**tmp;
	int			i;
	double		sumx;
	double		sumy;
	double		sumz;

	i = 0;
	sumx = 0;
	sumy = 0;
	sumz = 0;
	tmp = (t_point **)env->map->contents;
	while(i < env->map->end)
	{
		sumx += tmp[i]->x;
		sumy += tmp[i]->y;
		sumz += tmp[i]->z;
		++i;
	}
	env->center.x = sumx / (double)i;
	env->center.y = sumy / (double)i;
	env->center.z = sumz / (double)i;
	DEBUG("CENTER X = %f\n", env->center.x);
	DEBUG("CENTER Y = %f\n", env->center.y);
	DEBUG("CENTER Z = %f\n", env->center.z);
}

void		xrotation(t_env *env, float rad)
{
	int				i;
	t_rotation		r_points;
	t_point			**tmp;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while (i < env->map->end)
	{
		r_points.y = tmp[i]->y - env->center.y;
		r_points.z = tmp[i]->z - env->center.z;
		r_points.d = hypot(r_points.y, r_points.z);
		r_points.theta = atan2(r_points.y, r_points.z) + rad;
		tmp[i]->z = r_points.d * cos(r_points.theta) + env->center.z;
		tmp[i]->y = r_points.d * sin(r_points.theta) + env->center.y;
		++i;
	}
}

void	addpixels(t_env *env)
{
	int				i;
	t_point			**tmp;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while (i < env->map->end - 1)
	{
		drawline(tmp[i]->x, tmp[i]->y, tmp[i + 1]->x, tmp[i + 1]->y, env);
		//ft_3d_draw(*tmp[i], *tmp[i + 1], env);
		++i;
	}
}


void	draw(t_env *env)
{
	t_point		p0;
	t_point		p1;

	p0.x = 10;
	p0.y = 10;
	p1.x = 790;
	p1.y = 790;
//	set_pixel(10, 10, env);
	//drawline(10, 10, 790, 790, env);
	ft_3d_draw(p0, p1, env);
//	drawline(400, 10, 400, 790, env);
//	drawline(10, 400, 790, 400, env);
//	set_pixel(400, 400, env);
//	set_pixel(790, 790, env);
//	set_pixel(790, 10, env);
//	set_pixel(10, 790, env);
//	drawline(790, 10, 10, 790, env);

}

static int	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->win_w = WIN_WIDTH;
	env->win_h = WIN_HEIGHT;
	CHECK(!env->mlx, RETURN(-1), "Error: mlx_init");
	env->win = mlx_new_window(env->mlx, env->win_w, env->win_h, "42");
	CHECK(!env->win, RETURN(-1), "Error: mlx_new_window");
	env->img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	CHECK(!env->img, RETURN(-1), "ERROR: mlx_new_image");
	env->img_data = (int *)mlx_get_data_addr(env->img, &(env->bpp), &(env->ln), &(env->ed));
	CHECK(env->img == 0, RETURN(-1), "ERROR: img");
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;
	int		fd;

	CHK1(ac != 2, ft_printf("Usage : %s <filename>\n", av[0]), -1);
	fd = open(av[1], O_RDONLY);
	CHECK(fd == -1, RETURN(-1), "Open Failed");
	env = ft_memalloc(sizeof(t_env));
	MEMCHECK(env);
	CHECK(env == NULL, RETURN(-1), "Out of Memory");
	fdf_reader(env, fd);
	CHECK(init_env(env) == -1, RETURN(-1), "ERROR: init_env");
	scale(env);
	xrotation(env, -.2);
	addpixels(env);
	mlx_key_hook(env->win, key_hooks, &env);
	mlx_loop(env->mlx);
	return (0);
}
