/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  key_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:19:08 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/12 21:26:24 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

static void		key_wasd_state(int keycode, t_env *env, int state)
{
	if (keycode == KEY_W)
		env->pressed.w = state;
	if (keycode == KEY_S)
		env->pressed.s = state;
	if (keycode == KEY_A)
		env->pressed.a = state;
	if (keycode == KEY_D)
		env->pressed.d = state;
}

static void		key_ijklc_state(int keycode, t_env *env, int state)
{
	if (keycode == KEY_I)
		env->pressed.i = state;
	if (keycode == KEY_J)
		env->pressed.j = state;
	if (keycode == KEY_K)
		env->pressed.k = state;
	if (keycode == KEY_L)
		env->pressed.l = state;
	if (keycode == KEY_C)
		env->pressed.c = state;
}

void			key_state(int keycode, t_env *env, int state)
{
	key_wasd_state(keycode, env, state);
	key_ijklc_state(keycode, env, state);
	if (keycode == KEY_X)
		env->pressed.x = state;
	if (keycode == KEY_Y)
		env->pressed.y = state;
	if (keycode == KEY_Z)
		env->pressed.z = state;
	if (keycode == KEY_Q)
		env->pressed.q = state;
	if (keycode == KEY_E)
		env->pressed.e = state;
	if (keycode == KEY_O)
		env->pressed.o = state;
	if (keycode == KEY_P)
		env->pressed.p = state;
	if (keycode == KEY_PLUS)
		env->pressed.plus = state;
	if (keycode == KEY_MINUS)
		env->pressed.minus = state;
}
