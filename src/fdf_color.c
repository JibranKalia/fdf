/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:35:47 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/02 09:28:00 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>


int		random_color(void)
{
	int color_num;
	int	color;

	color = 0;
	color_num = rand() % 10;
	if (color_num == 0)
		 color = 0x800080;
	else if (color_num == 1)
		color = 0xC0C0C0;
	else if (color_num == 2)
		color = 0xFF0000;
	else if (color_num == 3)
		color = 0x800000;
	else if (color_num == 4)
		color = 0xFFFF00;
	else if (color_num == 5)
		color = 0x008000;
	else if (color_num == 6)
		color = 0x00FFFF;
	else if (color_num == 7)
		color = 0x008080;
	else if (color_num == 8)
		color = 0xFF00FF;
	else if (color_num == 9)
		color = 0x008080;
	return (color);
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
