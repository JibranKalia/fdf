/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 22:03:01 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/13 00:06:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

void	mat_translate(float dst[4][4], float x, float y, float z)
{
	float	tmp[4][4];

	mat_id(tmp);
	tmp[3][0] = x;
	tmp[3][1] = y;
	tmp[3][2] = z;
	mat_mult(dst, dst, tmp);
}

void	mat_scale(float dst[4][4], float x, float y, float z)
{
	float	tmp[4][4];

	ft_bzero(tmp, sizeof(float [4][4]));
	tmp[0][0] = x;
	tmp[1][1] = y;
	tmp[2][2] = z;
	tmp[3][3] = 1;
	mat_mult(dst, dst, tmp);
}

void		mat_rotate(float org[4][4], float ax, float ay, float az)
{
	float xmat[4][4];
	float ymat[4][4];
	float zmat[4][4];
	float tmp1[4][4];
	float tmp2[4][4];

	mat_id(xmat);
	mat_id(ymat);
	mat_id(zmat);
	xmat[1][1] = cos(ax);
	xmat[1][2] = sin(ax);
	xmat[2][1] = -sin(ax);
	xmat[2][2] = cos(ax);
	ymat[0][0] = cos(ay);
	ymat[0][2] = -sin(ay);
	ymat[2][0] = sin(ay);
	ymat[2][2] = cos(ay);
	zmat[0][0] = cos(az);
	zmat[0][1] = sin(az);
	zmat[1][0] = -sin(az);
	zmat[1][1] = cos(az);
	mat_mult(org, ymat, tmp1);
	mat_mult(tmp1, xmat, tmp2);
	mat_mult(tmp2, zmat, org);
}

void			vec_mat_mult(t_vec3f *src1, float src2[4][4], t_vec3f *dst)
{
	dst->x = src1->x * src2[0][0]
			+ src1->y * src2[1][0]
			+ src1->z * src2[2][0] + src2[3][0];
	dst->y = src1->x * src2[0][1]
			+ src1->y * src2[1][1]
			+ src1->z * src2[2][1] + src2[3][1];
	dst->z = src1->x * src2[0][2]
			+ src1->y * src2[1][2]
			+ src1->z * src2[2][2] + src2[3][2];
}
