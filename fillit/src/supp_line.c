/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:00:20 by mberedda          #+#    #+#             */
/*   Updated: 2016/01/22 16:48:53 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*delpoin(char *s)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	s2 = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (s[i] != '\0')
	{
		while ((s[i] == '.' || s[i] == ' ') &&
				(s[i + 1] == '.' || s[i + 1] == ' ') &&
				(s[i + 2] == ' ' || s[i + 2] == '.') &&
				(s[i + 3] == ' ' || s[i + 3] == '.'))
			i = i + 5;
		s2[j] = s[i];
		i++;
		j++;
	}
	return (s2);
}

static void	space_(char *s, int i)
{
	if (s[i + 1] == '.' && s[i + 6] == '.' &&
			s[i + 11] == '.' && s[i + 16] == '.')
	{
		s[i + 1] = ' ';
		s[i + 6] = ' ';
		s[i + 11] = ' ';
		s[i + 16] = ' ';
	}
	if (s[i + 2] == '.' && s[i + 7] == '.' &&
			s[i + 12] == '.' && s[i + 17] == '.')
	{
		s[i + 2] = ' ';
		s[i + 7] = ' ';
		s[i + 12] = ' ';
		s[i + 17] = ' ';
	}
}

char		*space(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.' && s[i + 5] == '.' &&
				s[i + 10] == '.' && s[i + 15] == '.')
		{
			s[i] = ' ';
			s[i + 5] = ' ';
			s[i + 10] = ' ';
			s[i + 15] = ' ';
		}
		space_(s, i);
		i = i + 21;
	}
	return (s);
}

char		*delspace(char *s)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	s2 = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		s2[j] = s[i];
		i++;
		j++;
	}
	return (s2);
}
