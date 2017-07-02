/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 20:27:49 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/02 09:27:35 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	linesaver(int keycode, t_env *env)
{
	if (keycode == KEY_N)
		env->scale += .01;
	if (keycode == KEY_M)
		env->scale -= .01;
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
	{
		free(env->color);
		env->color1 = random_color();
		env->color2 = random_color();
		create_color_table(env);
	}
	if (keycode == KEY_SPACE)
	{
		init_mat(env);
		free(env->color);
		create_color_table(env);
		draw(env);
	}
	redraw(env);
	return (0);
}

static void	exit_cleanup(t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->max_point)
	{
		free(env->points[i]->local);
		free(env->points[i]->alligned);
		free(env->points[i]->world);
		free(env->points[i]);
	}
	free(env->points);
	free(env->color);
	ft_bzero(env, sizeof(env));
	free(env);
}

int			key_release(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit_cleanup(env);
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
