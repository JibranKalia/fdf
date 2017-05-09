/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:36:31 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/09 13:47:36 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define COLOR1 0x00ff00

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <libft.h>

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_data;
	int			ln;
	int			bpp;
	int			ed;
	int			h;
	int			w;
	t_arr		*map;
}				t_env;

int				fdf_reader(t_env *env, int fd);
void			ft_perror(const char *s);
void			drawline(int x0, int y0, int x1, int y1, t_env *env);
void			set_pixel(int x, int y, t_env *env);

#endif
