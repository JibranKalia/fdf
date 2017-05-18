/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:20:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/17 13:55:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/**
 * i = Wx + y
 * y = i/W
 * x = i - Wy
**/

void		map_clean(void *elm)
{
	ft_bzero(elm, sizeof(t_vec3f));
}

void		file_clean(void *elm)
{
	(void)elm;
}

/**
static int	check_point(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->map->end)
	{
		printf("x = %.0f\n", env->points[i]->local->x);
		printf("y = %.0f\n", env->points[i]->local->y);
		printf("z = %.0f\n", env->points[i]->local->z);
		printf("i = %d\n", i);
		++i;
	}
	return (0);
}
**/

static int	save_point(t_env *env)
{
	int		i;
	t_vec3f		**tmp;
	t_vertex	**out;

	env->max_point = env->map_h * env->map_w;
	out = ft_memalloc(sizeof(t_vertex*) * env->max_point);
	tmp = (t_vec3f **)env->map->contents;
	i = 0;
	while (i < env->max_point)
	{
		out[i] = ft_memalloc(sizeof(t_vertex));	
		out[i]->local  = ft_memalloc(sizeof(t_vec3f));
		out[i]->alligned = ft_memalloc(sizeof(t_vec3f));
		++i;
	}
	i = 0;
	while (i < env->max_point)
	{
		out[i]->local->x = tmp[i]->x;
		out[i]->local->y = tmp[i]->y;
		out[i]->local->z = tmp[i]->z;
		++i;
	}
	env->points = out;
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

	DEBUG("read point");
	env->map = arr_create(sizeof(t_vec3f), env->map_h * env->map_w);
	MEMCHECK(env->map);
	env->map->del = map_clean;
	tmp = (char **)src->contents;
	i = 0;
	while (tmp[i])
	{
		out = ft_strsplit(tmp[i], ' ');
		j = 0;
		while (out[j])
		{	
			in = ft_memalloc(sizeof(t_vec3f));
			MEMCHECK(in);
			in->x = (double)j + 1;
			in->y = (double)i + 1;
			in->z = (double)ft_atoi(out[j]);
			arr_push(env->map, in);
			++j;
		}
		ft_tbldel(out);
		++i;
	}
	return (0);
}

int			fdf_reader(t_env *env, int fd)
{
	char	*line;
	int		count;
	int		b;
	t_arr	*file;

	DEBUG("fdf reader");
	file = arr_create(sizeof(char*), 100);
	MEMCHECK(file);
	file->del = file_clean;
	count = 0;
	while ((b = get_next_line(fd, &line)))
	{
		CHECK(b == -1, RETURN(-1), "Read Failed");
		if (count == 0)
		{
			arr_push(file, ft_strdup(line));
			env->map_w = ft_countwords(line, ' ');
		}
		else
			arr_push(file, ft_strdup(line));
		CHECK(ft_countwords(line, ' ') != env->map_w, RETURN(-1), "Error in FDF file");
		++count;
		free(line);
	}
	env->map_h = count;
	read_point(file, env);
	save_point(env);
//	check_point(env);
	arr_del(file);
	return (0);
}
