/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:36:31 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/12 20:08:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 1600
# define WIN_HEIGHT 1200

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <libgfx.h>

# define INDEX(x, y) (((y) * env->map_w) + (x))

typedef	struct	s_rotation
{
	float		x;
	float		y;
	float		z;
	float		d;
	float		theta;
}				t_rotation;

int				fdf_reader(t_env *env, int fd);
void			ft_perror(const char *s);
void			set_pixel(int x, int y, t_env *env);
void			centerfind(t_env *env);
void			puttoimg(t_env *env);
void			xrotation(t_env *env, float rad);
void			scale(t_env *env);
void			pad(t_env *env);

#endif
