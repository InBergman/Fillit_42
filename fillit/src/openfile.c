/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaubie <ldaubie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:34:53 by ldaubie           #+#    #+#             */
/*   Updated: 2016/01/22 21:39:42 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

char				ft_error(void)
{
	ft_putendl("error");
	return (0);
}

static char			**work_map(char *s)
{
	char			*tab;
	char			**tab1;

	tab = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	tab1 = (char **)malloc(sizeof(char *) * BUFFER_SIZE);
	tab = space(s);
	tab = delpoin(tab);
	tab = delspace(tab);
	tab = namediese(tab);
	tab1 = ft_strsplit(tab, '\n');
	free(tab);
	return (tab1);
}

static t_result		*resolve(char *s)
{
	t_tetrim		*data;
	t_result		*map;
	t_result		*res;

	res = NULL;
	map = ft_create_elem2();
	data = stocktetri(work_map(s));
	res = remptab(data, map, res);
	return (res);
}

int					main(int ac, char **argv)
{
	int				fd;
	int				ret;
	char			*s;

	if (ac != 2)
	{
		ft_error();
		return (0);
	}
	s = malloc(sizeof(char) * BUFFER_SIZE);
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, s, BUFFER_SIZE);
	if (ft_checkall(s) == 1)
		return (0);
	if (ft_checkall2(s) == 1)
		return (0);
	if (s[0] == '\n')
	{
		ft_error();
		return (0);
	}
	afficher_sol(resolve(s));
	free(s);
	return (0);
}
