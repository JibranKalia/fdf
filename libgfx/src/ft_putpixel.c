/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:58:21 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/12 20:05:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

#define XCHECK(x) ((x) < 0 || (x) >= env->win_w)
#define YCHECK(y) ((y) < 0 || (y) >= env->win_h)

void		ft_putpixel(t_env *env, int x, int y, t_rgb color)
{
	if (XCHECK(x) || YCHECK(y))
		return ;
	env->img_data[(x + y * env->win_w)] = COLOR1;
}

