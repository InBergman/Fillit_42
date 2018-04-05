/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filltab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 18:28:21 by mberedda          #+#    #+#             */
/*   Updated: 2016/01/22 21:39:21 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_result		*add_result(t_result *res, t_result *tmp, int i)
{
	tmp->i = i;
	res = tmp;
	return (res);
}

t_result			*remptab(t_tetrim *data, t_result *map, t_result *res)
{
	t_result	*tmp;
	int			x;
	int			y;

	x = 0;
	while (x < map->i)
	{
		y = 0;
		while (y < map->i)
		{
			if (check_place(data, map, x, y))
			{
				tmp = new_map(data, map, x, y);
				if (data->next)
					res = remptab(data->next, tmp, res);
				else if (!data->next)
					return (add_result(res, tmp, map->i));
				if (res)
					return (res);
			}
			y++;
		}
		x++;
	}
	return (cut_fcnt(data, map, res, x));
}

t_result			*cut_fcnt(t_tetrim *d, t_result *map, t_result *r, int x)
{
	free(map);
	if (d->index == 'A' && !r)
	{
		map = ft_create_elem2();
		map->i = x + 1;
		r = remptab(d, map, r);
	}
	return (r);
}

int					check_place(t_tetrim *data, t_result *map, int x, int y)
{
	if (data->coor[0][0] + x >= map->i || data->coor[0][1] + y >= map->i ||
			data->coor[1][0] + x >= map->i || data->coor[1][1] + y >= map->i ||
			data->coor[2][0] + x >= map->i || data->coor[2][1] + y >= map->i ||
			data->coor[3][0] + x >= map->i || data->coor[3][1] + y >= map->i)
		return (0);
	if (!map->tab[data->coor[0][0] + x][data->coor[0][1] + y] &&
			!map->tab[data->coor[1][0] + x][data->coor[1][1] + y] &&
			!map->tab[data->coor[2][0] + x][data->coor[2][1] + y] &&
			!map->tab[data->coor[3][0] + x][data->coor[3][1] + y])
		return (1);
	return (0);
}

t_result			*new_map(t_tetrim *data, t_result *map, int x, int y)
{
	t_result	*tmp;
	int			i;

	i = 0;
	tmp = ft_create_elem2();
	tmp->i = map->i;
	while (i < 225)
	{
		tmp->tab[i / 15][i % 15] = map->tab[i / 15][i % 15];
		i++;
	}
	tmp->tab[data->coor[0][0] + x][data->coor[0][1] + y] = data->index;
	tmp->tab[data->coor[1][0] + x][data->coor[1][1] + y] = data->index;
	tmp->tab[data->coor[2][0] + x][data->coor[2][1] + y] = data->index;
	tmp->tab[data->coor[3][0] + x][data->coor[3][1] + y] = data->index;
	return (tmp);
}
