/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:20:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/14 18:29:58 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		reader(t_env *env)
{
	t_arr		*map;
	t_vector	point;

	arr_init(map, 10, sizeof(t_vector));



}

int8_t	arr_init(t_arr *src, size_t cap, size_t	sze)
{
	int		i;
	
	i = 0;
	CHK((src = (t_arr *)ft_memalloc(sizeof(t_arr) * cap)) == -1, -1)
	src->sze = sze;
	while (i < cap)
	{
		CHK((src[i].elm = ft_memalloc(sze)) == -1, -1);
		++i;
	}
	return (0);
}

int8_t	arr_insert(t_arr *dst, size_t idx, const void *src)
{
	if (idx > src->cap)
		return (0);
	ft_memcpy(dst[idx].elm, src, dst->sze);
	++dst->len;
	return (0);
}
