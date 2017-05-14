/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 22:03:01 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/13 22:55:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

static void		mat_rotx(float src2[4][4], float ax)
{
	mat_bzero(mat);
	src2[0][0] = 1;
	src2[1][1] = cos(ax);
	src2[1][2] = sin(ax);
	src2[2][1] = -sin(ax);
	src2[2][2] = cos(ax);
	src2[3][3] = 1;
}

static void		mat_roty(float src2[4][4], float ay)
{
	mat_bzero(mat);
	src2[0][0] = cos(ay);
	src2[0][2] = -sin(ay);
	src2[1][1] = 1;
	src2[2][0] = sin(ay);
	src2[2][2] = cos(ay);
	src2[3][3] = 1;
}

static void		mat_rotz(float src2[4][4], float az)
{
	mat_bzero(mat);
	src2[0][0] = cos(az);
	src2[0][1] = sin(az);
	src2[1][0] = -sin(az);
	src2[1][1] = cos(az);
	src2[2][2] = 1;
	src2[3][3] = 1;
}

void			mat_rotate(float src2[4][4], float ax, float ay, float az)
{
	float matx[4][4];
	float maty[4][4];
	float matz[4][4];
	float mat1[4][4];
	float mat2[4][4];

	mat_rotx(matx, ax);
	mat_roty(maty, ay);
	mat_rotz(matz, az);
	mat_mult(mat, matx, mat1);
	mat_mult(mat1, matx, mat2);
	mat_mult(mat2, matz, mat);
}

void			vec_mat_mult(t_vec3f *src1, float src2[4][4], t_vec3f *dst)
{
	dst->x = src->x * src2[0][0]
		+ src->y * src2[1][0]
		+ src->z * src2[2][0] + src2[3][0];
	dst->y = src->x * src2[0][1]
		+ src->y * src2[1][1]
		+ src->z * src2[2][1] + src2[3][1];
	dst->z = src->x * src2[0][2]
		+ src->y * src2[1][2]
		+ src->z * src2[2][2] + src2[3][2];
}
