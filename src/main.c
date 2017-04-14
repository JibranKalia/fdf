/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:07:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/14 10:34:22 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

#define ESC			53
#define W			13
#define S			1
#define A			0
#define D			2
#define UP			126
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

int		key_hooks(int keycode, t_env *env)
{
	if (keycode == ESC)
		exit(0);
	(void)env;
	return (0);
}

t_env	*start(void)
{
	t_env	*env;
	
	env = (t_env *)ft_memalloc(sizeof(t_env) * 1);
	env->win = (t_win *)ft_memalloc(sizeof(t_win) * 1);
	env->img = (t_img *)ft_memalloc(sizeof(t_img) * 1);
	env->mlx = mlx_init();
	env->win->id = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "FDF");
	env->img->id = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	return (env);
}

int		main(int ac, char	**av)
{
	t_env	*env;

	CHK1(ac != 2, printf("Usage : %s <filename> [ case_size z_size ]", av[0]), -1);

	env = start();

	mlx_key_hook(env->win->id , key_hooks, &env);
	mlx_loop(env->mlx);
	return (0);
}
