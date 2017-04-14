/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:36:31 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/13 19:07:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_WIDTH 1600
# define W_HEIGHT 900

# include <stdlib.h>
# include <mlx.h>
# include <libft.h>

typedef struct	s_win
{
	void		*id;
	int			x;
	int			y;
}				t_win;

typedef struct	s_img
{
	void		*id;
	int			x;
	int			y;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	t_win		*win;
	t_img		*img;
}				t_env;

#endif
