/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:36:31 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/12 12:20:19 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_WIDTH 1600
# define W_HEIGHT 900

# include <stdlib.h>
# include <mlx.h>
# include <libft.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_env;

#endif
