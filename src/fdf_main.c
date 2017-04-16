/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:07:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/16 15:49:42 by hkalia           ###   ########.fr       */
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

void		set_pixel(t_env *env, int x, int y)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_WIDTH)
		return;
	// Is COLOR1 defined?
	env->img_data[x + y * env->ln] = COLOR1;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

static int	key_hooks(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		exit(EXIT_SUCCESS);
	}
	(void)env;
	return (0);
}

// pretty sure this function is wrong
void		draw(t_env *env)
{
	int	x;
	int	y;
	int	i;

	i = 100;
	x = 100;
	y = 100;
	while (i < 800)
	{
		set_pixel(env, x, y);
		++i;
	}
}
/*
void	draw(t_env *env)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			set_pixel(env, x, y);
			++j;
		}
		++i;
	}
}
*/
static int	init_env(t_env *env)
{
	CHK1(!(env->mlx = mlx_init()), ft_perror("ERROR: mlx_init"), -1);
	CHK1(!(env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "42")), ft_perror("ERROR: mlx_new_window"), -1);
	CHK1(!(env->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT)), ft_perror("ERROR: mlx_new_image"), -1);
	env->img_data = (int *)mlx_get_data_addr(env->img, &env->bpp, &env->ln, &env->bpp);
	env->ln /= 4;
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