/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:20:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/05/09 14:02:37 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define INDEX(x, y, w) ((y * w) + x)

/**
 * i = Wx + y
 * y = i/W
 * x = i - Wy
**/

void		map_clean(void *elm)
{
	ft_bzero(elm, sizeof(t_point));
}

static int	read_point(char *src, t_env *env)
{
	char		**tmp;
	t_point		*in;
	int	i;
	int	x;
	int	y;

	env->map = arr_create(sizeof(t_point), env->h * env->w);
	MEMCHECK(env->map);
	env->map->del = map_clean;
	tmp = ft_strsplit(src, ' ');
	i = 0;
	while (tmp[i])
	{
		in = ft_memalloc(sizeof(t_point));
		MEMCHECK(in);
		y = i / env->w;
		x = i - (env->w * y);
		in->x = (double)x + 1;
		in->y = (double)y + 1;
		in->z = (double)ft_atoi(tmp[i]);
		arr_push(env->map, in);
		++i;
	}
	return (0);
}

int			fdf_reader(t_env *env, int fd)
{
	char	*line;
	char	*ret;
	int		count;
	int		b;

	count = 0;
	while ((b = get_next_line(fd, &line)))
	{
		CHECK(b == -1, RETURN(-1), "Read Failed");
		if (count == 0)
		{
			ret = ft_strdup(line);
			env->w = ft_countwords(ret, ' ');
		}
		else
		{
			ret = ft_strjoin(ret, " ");
			ret = ft_strjoin(ret, line);
		}
		CHECK(ft_countwords(line, ' ') != env->w, RETURN(-1), "Error in FDF file");
		++count;
		free(line);
	}
	env->h = count;
	read_point(ret, env);
	return (0);
}
