/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:36:31 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/02 10:13:57 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1330
# define COLOR1 0x20B2AA
# define COLOR2 0xFF6633
# include <fcntl.h>
# include <libgfx.h>
# define INDEX(x, y) (((y) * env->map_w) + (x))

/*
** FDF_READER
*/

int				fdf_reader(t_env *env, int fd);

/*
** FDF_COLOR
*/

int				random_color(int color_num);
void			print_controls(void);

/*
** FDF_MAIN
*/

void			init_mat(t_env *env);
int				reset_mat(t_env *env);

/*
** FDF_DRAW
*/

int				redraw(t_env *env);
int				draw(t_env *env);

/*
** FDF_POINT
*/

void			local_to_world(t_env *env);
void			world_to_aligned(t_env *env);
void			draw_wireframe(t_env *env);

/*
** FDF_KEY
*/

int				key_press(int keycode, t_env *env);
int				key_release(int keycode, t_env *env);
int				key_exit(t_env *env);

#endif
