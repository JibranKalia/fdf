/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 20:27:49 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/15 20:37:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		key_press(int keycode, t_env *env)
{
//	if (keycode == KEY_W)
//	{
//		draw(env);
//	}
	(void)env;
	DEBUG("Key Press: Keycode %d", keycode);
	return (0);
}

int		key_release(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	DEBUG("Key Release: Keycode %d", keycode);
	return (0);
}

int		key_exit(t_env *env)
{
	(void)env;
	DEBUG("Exit");
	exit(0);
}
