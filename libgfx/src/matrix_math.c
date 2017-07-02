/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 21:47:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/02 09:18:43 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

void	mat_bzero(float src[4][4])
{
	ft_bzero(src[0], sizeof(float) * 4);
	ft_bzero(src[1], sizeof(float) * 4);
	ft_bzero(src[2], sizeof(float) * 4);
	ft_bzero(src[3], sizeof(float) * 4);
}

void	mat_id(float src[4][4])
{
	mat_bzero(src);
	src[0][0] = 1;
	src[1][1] = 1;
	src[2][2] = 1;
	src[3][3] = 1;
}

void	mat_mult(float src1[4][4], float src2[4][4], float dst[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst[i][j] = src1[i][0] * src2[0][j] + src1[i][1] * src2[1][j]
				+ src1[i][2] * src2[2][j] + src1[i][3] * src2[3][j];
			++j;
		}
		++i;
	}
}

void	mat_translate(float dst[4][4], float x, float y, float z)
{
	float	tmp[4][4];

	mat_id(tmp);
	tmp[3][0] = x;
	tmp[3][1] = y;
	tmp[3][2] = z;
	mat_mult(dst, tmp, dst);
}

void	mat_scale(float dst[4][4], float x, float y, float z)
{
	float	tmp[4][4];

	mat_bzero(tmp);
	tmp[0][0] = x;
	tmp[1][1] = y;
	tmp[2][2] = z;
	tmp[3][3] = 1;
	mat_mult(dst, tmp, dst);
}
