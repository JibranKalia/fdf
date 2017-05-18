/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 20:27:49 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 19:38:40 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	linesaver(int keycode, t_env *env)
{
	if (keycode == KEY_P)
		env->scale += 1.1;
	if (keycode == KEY_O)
		env->scale += 0.9;
	if (keycode == KEY_I)
		env->ytrans += -3;
	if (keycode == KEY_K)
		env->ytrans += 3;
	if (keycode == KEY_J)
		env->xtrans += -3;
	if (keycode == KEY_L)
		env->xtrans += 3;
	if (keycode == KEY_W)
		env->ax += 0.05;
}

int			key_press(int keycode, t_env *env)
{
	linesaver(keycode, env);
	if (keycode == KEY_S)
		env->ax -= 0.05;
	if (keycode == KEY_A)
		env->ay -= 0.05;
	if (keycode == KEY_D)
		env->ay += 0.05;
	if (keycode == KEY_Q)
		env->az += 0.05;
	if (keycode == KEY_E)
		env->az -= 0.05;
	if (keycode == KEY_C)
		set_color(env);
	if (keycode == KEY_SPACE)
	{
		init_mat(env);
		init_draw(env);
	}
	redraw(env);
	return (0);
}

int			key_release(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (0);
}

int			key_exit(t_env *env)
{
	(void)env;
	DEBUG("Exit");
	exit(0);
	return (0);
}
