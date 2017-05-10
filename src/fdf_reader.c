/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:20:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/09 18:09:48 by jkalia           ###   ########.fr       */
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
	ft_bzero(elm, sizeof(t_point));
}

void		file_clean(void *elm)
{
	(void)elm;
}

static int	check_point(t_env *env)
{
	t_point	**tmp;
	int		i;

	i = 0;
	tmp = (t_point **)env->map->contents;
	while (i < env->map->end)
	{
		printf("x = %.0f\n", tmp[i]->x);
		printf("y = %.0f\n", tmp[i]->y);
		printf("z = %.0f\n", tmp[i]->z);
		printf("i = %d\n", i);
		++i;
	}
	return (0);
}

static int	read_point(t_arr *src, t_env *env)
{
	char		**tmp;
	char		**out;
	t_point		*in;
	int			i;
	int			j;

	env->map = arr_create(sizeof(t_point), env->map_h * env->map_w);
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
			in = ft_memalloc(sizeof(t_point));
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
	check_point(env);
	arr_del(file);
	return (0);
}
