/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:35:47 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/02 06:59:22 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		set_color(t_env *env)
{
	int color_num;

	color_num = rand() % 10;
	if (color_num == 0)
		env->color = 0x800080;
	else if (color_num == 1)
		env->color = 0xC0C0C0;
	else if (color_num == 2)
		env->color = 0xFF0000;
	else if (color_num == 3)
		env->color = 0x800000;
	else if (color_num == 4)
		env->color = 0xFFFF00;
	else if (color_num == 5)
		env->color = 0x008000;
	else if (color_num == 6)
		env->color = 0x00FFFF;
	else if (color_num == 7)
		env->color = 0x008080;
	else if (color_num == 8)
		env->color = 0xFF00FF;
	else if (color_num == 9)
		env->color = 0x008080;
	return (0);
}

void	print_controls(void)
{
	ft_putstr("w/s      : rotate by x axis\n");
	ft_putstr("a/d      : rotate by y axis\n");
	ft_putstr("q/e      : rotate by z axis\n");
	ft_putstr("c        : switch colors\n");
	ft_putstr("ijkl     : move around\n");
	ft_putstr("n/m      : size change\n");
	ft_putstr("Esc      : quit\n");
	ft_putstr("Space    : reset\n");
}
