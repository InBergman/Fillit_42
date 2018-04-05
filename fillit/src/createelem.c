/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaubie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 10:41:11 by ldaubie           #+#    #+#             */
/*   Updated: 2016/01/07 15:52:01 by ldaubie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_tetrim		*ft_create_elem(void)
{
	t_tetrim	*data;
	int			i;

	i = 0;
	data = (t_tetrim *)malloc(sizeof(t_tetrim));
	if (!data)
		return (NULL);
	while (i < 8)
	{
		data->coor[i / 4][i % 2] = 0;
		i++;
	}
	data->next = NULL;
	data->index = 'A';
	return (data);
}

t_result		*ft_create_elem2(void)
{
	t_result	*map;
	int			i;

	i = 0;
	map = (t_result *)malloc(sizeof(t_result));
	if (!map)
		return (NULL);
	map->i = 2;
	while (i < 225)
	{
		map->tab[i / 15][i % 15] = 0;
		i++;
	}
	map->next = NULL;
	return (map);
}
