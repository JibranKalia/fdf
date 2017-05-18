/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:07:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 19:39:13 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		init_mat(t_env *env)
{
	mat_id(env->mat);
	env->ax = 0.4;
	env->ay = 0.1;
	env->az = 0.1;
	env->xtrans = 0;
	env->ytrans = 0;
	env->scale = (env->win_h / env->map_h) / 2;
	env->xtrans = 5;
	env->ytrans = 5;
	env->color = 0x800080;
}

static int	init_env(t_env *env)
{
	env->win_w = WIN_WIDTH;
	env->win_h = WIN_HEIGHT;
	env->mlx = mlx_init();
	CHECK(!env->mlx, RETURN(-1), "Error: mlx_init");
	env->win = mlx_new_window(env->mlx, env->win_w, env->win_h, "42");
	CHECK(!env->win, RETURN(-1), "Error: mlx_new_window");
	init_mat(env);
	return (0);
}

int			reset_mat(t_env *env)
{
	mat_id(env->mat);
	env->ax = 0;
	env->ay = 0;
	env->az = 0;
	env->xtrans = 0;
	env->ytrans = 0;
	env->scale = 0;
	env->xtrans = 0;
	env->ytrans = 0;
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*env;
	int		fd;

	CHK1(ac != 2, ft_printf("Usage : %s <filename>\n", av[0]), -1);
	fd = open(av[1], O_RDONLY);
	CHECK(fd == -1, RETURN(-1), "Open Failed");
	env = ft_memalloc(sizeof(t_env));
	fdf_reader(env, fd);
	CHECK(init_env(env) == -1, RETURN(-1), "ERROR: init_env");
	MEMCHECK(env);
	init_draw(env);
	print_controls();
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 3, 0, key_release, env);
	mlx_hook(env->win, 17, 0, key_exit, env);
	mlx_loop(env->mlx);
	return (0);
}
