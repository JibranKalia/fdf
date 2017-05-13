/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:34:37 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/12 22:07:48 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H
# include <math.h>
# include <mlx.h>
# include <libft.h>
# include "keys.h"

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	int	color;
}		t_point;

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
	t_arr		*map;
	t_ixyz		center;
	t_keys		pressed;
}				t_env;

void			ft_putpixel(t_env *env, int x, int y);
void			ft_3d_draw(t_env *env, t_point p0, t_point p1);
void			key_state(int keycode, t_env *env, int state);
void			mat_id(float mat[4][4]);
void			mat_mult(float src1[4][4], float src2[4][4], float dst[4][4]);
void			mat_translate(float dst[4][4], float x, float y, float z);
void			mat_scale(float dst[4][4], float x, float y, float z);
void			mat_rotate(float org[4][4], float ax, float ay, float az);


#endif