/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:20:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 20:51:54 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** i = Wx + y
** y = i/W
** x = i - Wy
*/

void		map_clean(void *elm)
{
	ft_bzero(elm, sizeof(t_vec3f));
}

void		file_clean(void *elm)
{
	(void)elm;
}

static int	save_point(t_env *env)
{
	int			i;
	t_vec3f		**tmp;
	t_vertex	**out;

	env->max_point = env->map_h * env->map_w;
	out = ft_memalloc(sizeof(t_vertex*) * env->max_point);
	tmp = (t_vec3f **)env->map->contents;
	i = -1;
	while (++i < env->max_point)
	{
		out[i] = ft_memalloc(sizeof(t_vertex));
		out[i]->local = ft_memalloc(sizeof(t_vec3f));
		out[i]->alligned = ft_memalloc(sizeof(t_vec3f));
	}
	i = -1;
	while (++i < env->max_point)
	{
		out[i]->local->x = tmp[i]->x;
		out[i]->local->y = tmp[i]->y;
		out[i]->local->z = tmp[i]->z;
	}
	env->points = out;
	env->map->del = map_clean;
//	arr_del(env->map);
	return (0);
}

static int	read_point(t_arr *src, t_env *env)
{
	char		**tmp;
	char		**out;
	t_vec3f		*in;
	int			i;
	int			j;

	env->map = arr_create(sizeof(t_vec3f), env->map_h * env->map_w);
	MEMCHECK(env->map);
	tmp = (char **)src->contents;
	i = -1;
	while (tmp[++i])
	{
		out = ft_strsplit(tmp[i], ' ');
		j = -1;
		while (out[++j])
		{
			CHECK(!(in = ft_memalloc(sizeof(t_vec3f))), RETURN(-1), "Malloc");
			in->x = (float)(j + 1);
			in->y = (float)(i + 1);
			in->z = (float)ft_atoi(out[j]);
			arr_push(env->map, in);
		}
		ft_tbldel(out);
	}
	return (0);
}

int			fdf_reader(t_env *env, int fd)
{
	char	*line;
	int		b;
	t_arr	*file;

	file = arr_create(sizeof(char*), 100);
	MEMCHECK(file);
	file->del = file_clean;
	while ((b = get_next_line(fd, &line)))
	{
		CHECK(b == -1, RETURN(-1), "Read Failed");
		if (env->map_h == 0)
		{
			arr_push(file, ft_strdup(line));
			env->map_w = ft_countwords(line, ' ');
		}
		else
			arr_push(file, ft_strdup(line));
		CHECK(ft_countwords(line, ' ') != env->map_w, RETURN(-1), "File Error");
		++env->map_h;
		free(line);
	}
	CHK(read_point(file, env) == -1, -1);
//	arr_del(file);
	CHK(save_point(env) == -1, -1);
	return (0);
}
