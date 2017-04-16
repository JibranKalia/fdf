/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:20:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/15 20:17:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define INDEX(x, y, w) ((y * w) + x)

/**
i = Hy + x;
x = i - Hy;
y = i/H
**/

static int	read_point(char *src, t_env *env)
{
	char	**tmp;
	int		x;
	int		y;
	int		z;
	
	max_idx = env->h * env->w;
	CHK1((env->map = ft_memalloc(sizeof(t_point) * env->h * env->w + 1)) == 0, ft_perror("Malloc Fail"), -1);
	tmp = ft_strsplit(src, ' ')

	y = 0;
	z = 0;
	i = 0;
	while (tmp[i])
	{
		y = i / env->w;
		x = i - (env->w * x);
		env->map[i].x = (double)x;
		env->map[i].y = (double)y;
		env->map[i].z = (double)ft_atoi(tmp[i]);
		z = (double)ft_atoi(tmp[i]);
		printf("x = %d\n", x);
		printf("y = %d\n", y);
		printf("z = %d\n", z);
		printf("---------\n");
		++i;
	}
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
	read_point(ret, env);
	return (0);
}
