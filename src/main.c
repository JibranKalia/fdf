/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:07:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/12 12:19:17 by jkalia           ###   ########.fr       */
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

int		key_hooks(int keycode, t_env *env)
{
	if (keycode == ESC)
		exit(0);
	(void)env;
	return (0);
}

int		main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, W_WIDTH, W_HEIGHT, "FDF");
	env.img = mlx_new_image(env.mlx, W_WIDTH, W_HEIGHT);
	mlx_key_hook(env.win, key_hooks, &env);
	mlx_loop(env.mlx);
	return (0);
}
