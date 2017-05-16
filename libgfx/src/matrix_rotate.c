/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 22:03:01 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/15 20:35:57 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

static void		mat_rotx(float src[4][4], float ax)
{
	mat_bzero(src);
	src[0][0] = 1;
	src[1][1] = cos(ax);
	src[1][2] = sin(ax);
	src[2][1] = -sin(ax);
	src[2][2] = cos(ax);
	src[3][3] = 1;
}

static void		mat_roty(float src[4][4], float ay)
{
	mat_bzero(src);
	src[0][0] = cos(ay);
	src[0][2] = -sin(ay);
	src[1][1] = 1;
	src[2][0] = sin(ay);
	src[2][2] = cos(ay);
	src[3][3] = 1;
}

static void		mat_rotz(float src[4][4], float az)
{
	mat_bzero(src);
	src[0][0] = cos(az);
	src[0][1] = sin(az);
	src[1][0] = -sin(az);
	src[1][1] = cos(az);
	src[2][2] = 1;
	src[3][3] = 1;
}

void			mat_rotate(float src[4][4], float ax, float ay, float az)
{
	float matx[4][4];
	float maty[4][4];
	float matz[4][4];
	float mat1[4][4];
	float mat2[4][4];

	mat_rotx(matx, ax);
	mat_roty(maty, ay);
	mat_rotz(matz, az);
	mat_mult(src, matx, mat1);
	mat_mult(mat1, matx, mat2);
	mat_mult(mat2, matz, src);
}

void			vec_mat_mult(t_vec3f *src1, float src[4][4], t_vec3f *dst)
{
	dst->x = src1->x * src[0][0]
		+ src1->y * src[1][0]
		+ src1->z * src[2][0] + src[3][0];
	dst->y = src1->x * src[0][1]
		+ src1->y * src[1][1]
		+ src1->z * src[2][1] + src[3][1];
	dst->z = src1->x * src[0][2]
		+ src1->y * src[1][2]
		+ src1->z * src[2][2] + src[3][2];
}
