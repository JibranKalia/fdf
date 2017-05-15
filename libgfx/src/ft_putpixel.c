/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:58:21 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/15 15:02:14 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

#define XCHECK(x) ((x) < 0 || (x) >= env->win_w)
#define YCHECK(y) ((y) < 0 || (y) >= env->win_h)
# define COLOR1 0x00ff00

void		ft_putpixel(t_env *env, int x, int y)
{
	if (XCHECK(x) || YCHECK(y))
		return ;
	env->img_data[(x + y * env->win_w)] = COLOR1;
//	DEBUG("Pixel Put\tx=%d\ty=%d\n", x, y);
}

