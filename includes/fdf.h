/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:36:31 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/14 18:29:50 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_WIDTH 1600
# define W_HEIGHT 900

# include <stdlib.h>
# include <mlx.h>
# include <libft.h>


typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int8_t		r;
	int8_t		g;
	int8_t		b;
}				t_vector;

typedef struct	s_arr
{
	void		*elm;
	size_t		len;
	size_t		cap;
	size_t		sze;
}				t_arr;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	t_arr		*map;
}				t_env;

#endif
