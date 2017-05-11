/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:07:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/11 14:21:42 by jkalia           ###   ########.fr       */
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
