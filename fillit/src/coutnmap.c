/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coutnmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:57:02 by mberedda          #+#    #+#             */
/*   Updated: 2016/01/25 11:55:35 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*namediese(char *s)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			j++;
			s[i] = 'A' + k;
			if (j % 4 == 0)
				k++;
		}
		i++;
	}
	return (s);
}

int			line(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i - 1] != '\n')
		{
			count++;
			if (count > 4)
				return (1);
		}
		if (s[i] == '\n' && s[i + 1] == '\n')
		{
			if (count != 4)
				return (1);
			else
				count = 0;
		}
		i++;
	}
	return (0);
}

int			ft_checkall(char *s)
{
	if (line(s) == 1)
	{
		ft_error();
		return (1);
	}
	if (check_newline(s) == 1)
	{
		ft_error();
		return (1);
	}
	if (check_file(s) == 1)
	{
		ft_error();
		return (1);
	}
	if (check_diese(s) == 1)
	{
		ft_error();
		return (1);
	}
	return (0);
}

int			ft_checkall2(char *s)
{
	if (check_dieseside(s) == 1)
	{
		ft_error();
		return (1);
	}
	if (check_dieselink(s) == 1)
	{
		ft_error();
		return (1);
	}
	return (0);
}

void		afficher_sol(t_result *map)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x < map->i)
	{
		y = 0;
		while (y < map->i)
		{
			if (map->tab[x][y] == 0)
				ft_putchar('.');
			else
				ft_putchar(map->tab[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
