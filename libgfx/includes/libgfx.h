/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:34:37 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/13 22:44:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H
# include <math.h>
# include <mlx.h>
# include <libft.h>
# include "keys.h"

typedef struct	s_vec3f
{
	float	x;
	float	y;
	float	z;
}		t_vec3f;

typedef	struct	s_ixyz
{
	int	x;
	int	y;
	int	z;
}		t_ixyz;

typedef	struct	s_rgb
{
	float	r;
	float	g;
	float	b;
}		t_rgb;

typedef struct	s_vertex
{
	t_vec3f		*local;
	t_vec3f		*alligned;

}		t_vertex;

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
	int		max_point;
	float		scale_x;
	float		scale_y;
	float		scale_z;
	t_arr		*map;
	t_vertex	**points;
	t_arr		*scaled;
	t_ixyz		center;
	t_keys		pressed;
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
#endif
