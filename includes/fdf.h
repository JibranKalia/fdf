/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:36:31 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 20:39:53 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# include <fcntl.h>
# include <libgfx.h>
# define INDEX(x, y) (((y) * env->map_w) + (x))

int				fdf_reader(t_env *env, int fd);
void			set_pixel(int x, int y, t_env *env);
void			puttoimg(t_env *env);
void			scale(t_env *env);
void			translate(t_env *env);
void			rotate(t_env *env);
void			applypoint(t_env *env);
int				key_press(int keycode, t_env *env);
int				key_release(int keycode, t_env *env);
int				key_exit(t_env *env);
int				draw(t_env *env);
int				redraw(t_env *env);
int				init_draw(t_env *env);
void			init_mat(t_env *env);
void			applyalligned(t_env *env);
int				set_color(t_env *env);
void			print_controls(void);
int				reset_mat(t_env *env);
#endif
