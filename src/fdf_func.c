/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:44:38 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 20:22:29 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		scale(t_env *env)
{
	if (env->scale == 0)
		return ;
	mat_scale(env->mat, env->scale, env->scale, env->scale);
}

void		rotate(t_env *env)
{
	if (env->ax == 0 && env->ay == 0 && env->az == 0)
		return ;
	mat_rotate(env->mat, env->ax, env->ay, env->az);
}

void		translate(t_env *env)
{
	if (env->xtrans == 0 && env->ytrans == 0)
		return ;
	mat_translate(env->mat, env->xtrans, env->ytrans, 0);
}
