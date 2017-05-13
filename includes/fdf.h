/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:36:31 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/12 14:54:44 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 1600
# define WIN_HEIGHT 800
# define COLOR1 0x00ff00

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <libft.h>
# define INDEX(x, y) (((y) * env->map_w) + (x))

typedef struct	s_ixyz
{
	int			x;
	int			y;
	int			z;
}				t_ixyz;

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_point;

typedef	struct	s_rotation
{
	float		x;
	float		y;
	float		z;
	float		d;
	float		theta;
}				t_rotation;

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
}				t_env;

int				fdf_reader(t_env *env, int fd);
void			ft_perror(const char *s);
void			drawline(int x0, int y0, int x1, int y1, t_env *env);
void			ft_3d_draw(t_point p0, t_point p1, t_env *env);
void			set_pixel(int x, int y, t_env *env);
void			centerfind(t_env *env);
void			puttoimg(t_env *env);
void			xrotation(t_env *env, float rad);
void			scale(t_env *env);
void			pad(t_env *env);

#endif
