/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:07:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/15 11:51:51 by jkalia           ###   ########.fr       */
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

int		main(int ac, char	**av)
{
	t_env	*env;
	int		fd;

	CHK1(ac != 2, ft_printf("%{red}Usage : %s <filename> [ case_size z_size ]%{eoc}", av[0]), -1);
	CHK((fd = open(av[1], O_RDONLY)) == -1, ft_perror("Open Failed"));

	/**
	env = ft_memalloc(sizeof(t_env) * 1);
	env->mlx = mlx_init();
	env->win->id = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "FDF");
	env->img->id = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);

	mlx_key_hook(env->win->id , key_hooks, &env);
	mlx_loop(env->mlx);
	**/
	return (0);
}
