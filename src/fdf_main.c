/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:07:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/18 22:55:39 by jkalia           ###   ########.fr       */
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

void	draw(t_env *env)
{
	set_pixel(10, 10, env);
	set_pixel(400, 400, env);
	set_pixel(790, 790, env);
	set_pixel(790, 10, env);
	set_pixel(10, 790, env);
	drawline(790, 10, 10, 790, env);

}

static int	init_env(t_env *env)
{
	CHK1(!(env->mlx = mlx_init()), ft_perror("ERROR: mlx_init"), -1);
	CHK1(!(env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "42")), ft_perror("ERROR: mlx_new_window"), -1);
	CHK1(!(env->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT)), ft_perror("ERROR: mlx_new_image"), -1);
	env->img_data = (int *)mlx_get_data_addr(env->img, &(env->bpp), &(env->ln), &(env->ed));
	printf("BPP = %d\n", env->bpp);
	printf("Ln = %d\n", env->ln);
	printf("Endian = %d\n", env->ed);
	CHK1(env->img == 0, ft_perror("ERROR: img"), -1);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;
	int		fd;

	CHK1(ac != 2, ft_printf("Usage : %s <filename>\n", av[0]), -1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_perror("Open Failed");
	env = ft_memalloc(sizeof(t_env) * 1);
	fdf_reader(env, fd);
	CHK1(init_env(env) == -1, ft_perror("ERROR: init_env"), -1);
	draw(env);
	mlx_key_hook(env->win, key_hooks, &env);
	mlx_loop(env->mlx);
	return (0);
}
