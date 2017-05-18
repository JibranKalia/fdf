/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:20:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/18 13:48:24 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** i = Wx + y
** y = i/W
** x = i - Wy
*/

void		file_clean(void *elm)
{
	(void)elm;
}

static int	malloc_vertex(t_vertex ***tmp, t_env *env)
{
	int		i;
	t_vertex	**out;
	
	out = ft_memalloc(sizeof(t_vertex *) * env->max_point);
	MEMCHECK(out);
	i = -1;
	while (++i < env->max_point)
	{
		out[i] = ft_memalloc(sizeof(t_vertex));
		MEMCHECK(out[i]);
		out[i]->local = ft_memalloc(sizeof(t_vec3f));
		MEMCHECK(out[i]->local);
		out[i]->alligned = ft_memalloc(sizeof(t_vec3f));
		MEMCHECK(out[i]->alligned);
	}
	*tmp = out;
	return (0);

}

static int	save_point(t_arr *src, t_env *env)
{
	char		**tmp;
	char		**split;
	t_vertex	**out;
	int			i;
	int			j;

	CHK(malloc_vertex(&out, env) == -1, -1);
	env->points = out;
	tmp = (char **)src->contents;
	i = -1;
	while (tmp[++i])
	{
		split = ft_strsplit(tmp[i], ' ');
		j = -1;
		while (split[++j])
		{
			(*out)->local->x = (float)(j + 1);
			(*out)->local->y = (float)(i + 1);
			(*out)->local->z = (float)ft_atoi(split[j]);
			++out;
		}
		ft_tbldel(split);
	}
	return (0);
}

int			fdf_reader(t_env *env, int fd)
{
	char	*line;
	int		b;
	t_arr	*file;

	file = arr_create(sizeof(char*), 10000);
	MEMCHECK(file);
	file->del = file_clean;
	env->map_h = 0;
	while ((b = get_next_line(fd, &line)))
	{
		CHECK(b == -1, RETURN(-1), "Read Failed");
		if (env->map_w == 0)
			env->map_w = ft_countwords(line, ' ');
		arr_push(file, ft_strdup(line));
		CHECK(ft_countwords(line, ' ') != env->map_w, RETURN(-1), "File Error");
		++env->map_h;
		free(line);
	}
	env->max_point = env->map_h * env->map_w;
	CHK(save_point(file, env) == -1, -1);
	arr_del(file);
	return (0);
}
