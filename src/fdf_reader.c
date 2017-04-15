/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:20:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/15 12:48:34 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	read_point(char **src, t_env *env)
{
	int		x;
	int		y;
	int		z;
	int		i;

	y = 0;
	z = 0;
	i = 0;
	while (y < env->h)
	{
		x = 0;
		while (x < env->w)
		{
			env->map[y][x].x = (double)x;
			env->map[y][x].y = (double)y;
			//env->map[y][x].z = (double)ft_atoi(src);
			z = (double)ft_atoi(src[i]);
			printf("%s\n", src[i]);
			printf("x = %d\n", x);
			printf("y = %d\n", y);
			printf("z = %d\n", z);
			printf("---------\n");
			++x;
			++i;
		}
		++y;
	}
	return (0);
}

static int	map_malloc(char *src, t_env *env)
{
	int			i;
	t_point		**map;

	i = 0;
	CHK1((map = ft_memalloc(sizeof(t_point*) * env->h)) == 0, ft_perror("Malloc Fail"), -1);
	while (i < env->h)
	{
		CHK1((map[i] = ft_memalloc(sizeof(t_point*) * env->w)) == 0, ft_perror("Malloc Fail"), -1);
		++i;
	}
	env->map = map;
	read_point(ft_strsplit(src, ' '), env);
	return (0);
}

static int	count_width(char **str)
{
	int		i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int			fdf_reader(t_env *env, int fd)
{
	char	*line;
	char	*ret;
	int		count;
	int		b;

	(void)env;
	count = 0;
	while((b = get_next_line(fd, &line)))
	{
		CHK1(b == -1, ft_perror("Read Failed"), -1);
		if (count == 0)
		{
			ret = ft_strdup(line);
			env->w = count_width(ft_strsplit(ret, ' '));
		}
		else
		{
			ret = ft_strjoin(ret, " ");
			ret = ft_strjoin(ret, line);
		}
		if ((count_width(ft_strsplit(line, ' ')) != env->w))
				ft_perror("Error in FDF file");
		++count;
		free(line);
	}
	env->h = count;
	map_malloc(ret, env);
	return (0);
}
