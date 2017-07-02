/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:34:37 by jkalia            #+#    #+#             */
/*   Updated: 2017/06/04 01:07:43 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

# include <math.h>
# include <mlx.h>
# include <libft.h>

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_N 45
# define KEY_M 46
# define KEY_K 40
# define KEY_I 34
# define KEY_W 13
# define KEY_ESC 53
# define KEY_J 38
# define KEY_L 37
# define KEY_Q 12
# define KEY_E 14
# define KEY_C 8
# define KEY_SPACE 49

typedef struct	s_vec3f
{
	float		x;
	float		y;
	float		z;
}				t_vec3f;

typedef struct	s_ixyz
{
	int			x;
	int			y;
	int			z;
}				t_ixyz;

typedef struct	s_ixy
{
	int			x;
	int			y;
}				t_ixy;

typedef struct	s_rgb
{
	float		r;
	float		g;
	float		b;
}				t_rgb;

typedef struct	s_vertex
{
	t_vec3f		*local;
	t_vec3f		*world;
	t_vec3f		*alligned;
}				t_vertex;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_data;
	int			ln;
	int			bpp;
	int			ed;
	int			map_h;
	int			map_w;
	int			win_w;
	int			win_h;
	int			max_point;
	int			color;
	float		scale;
	float		xtrans;
	float		ytrans;
	float		ax;
	float		ay;
	float		az;
	float		mat[4][4];
	t_vertex	**points;
}				t_env;

void			ft_putpixel(t_env *env, int x, int y);
void			ft_3d_draw(t_env *env, t_vec3f p0, t_vec3f p1);
void			key_state(int keycode, t_env *env, int state);
void			mat_id(float mat[4][4]);
void			mat_debug(float mat[4][4]);
void			mat_mult(float src1[4][4], float src2[4][4], float dst[4][4]);
void			mat_translate(float dst[4][4], float x, float y, float z);
void			mat_scale(float dst[4][4], float x, float y, float z);
void			mat_rotate(float dst[4][4], float ax, float ay, float az);
void			vec_mat_mult(t_vec3f *src1, float src2[4][4], t_vec3f *dst);
void			mat_bzero(float mat[4][4]);
void			mat_copy(float src[4][4], float dst[4][4]);

#endif
