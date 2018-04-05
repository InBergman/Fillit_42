/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaubie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:06:28 by ldaubie           #+#    #+#             */
/*   Updated: 2016/01/18 14:52:13 by ldaubie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_newline(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i + 4] == '\n')
			j++;
		if (s[i + 5] == '\n')
			j++;
		i = i + 5;
	}
	if (((j % 5) - 4) != 0)
		return (1);
	return (0);
}

int		check_file(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.' || s[i] == '#')
			j++;
		if (s[i] != '.' && s[i] != '#' &&
				s[i] != '\n')
			return (1);
		i++;
	}
	if ((j / 4) % 2 != 0)
		return (1);
	return (0);
}

int		check_diese(char *s)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while ((s[i] != '\n' || s[i + 1] != '\n') &&
				(s[i] != '\n' || s[i + 1] != '\0'))
		{
			if (s[i] == '#')
				j++;
			i++;
		}
		if (j != 4)
			return (1);
		i++;
	}
	return (0);
}

int		check_dieseside(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] != '#' && s[i + 5] != '#' &&
					s[i - 1] != '#' && s[i - 5] != '#')
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_dieselink(char *s)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while ((s[i] != '\n' || s[i + 1] != '\n') &&
				(s[i] != '\n' || s[i + 1] != '\0'))
		{
			if (s[i] == '#')
			{
				if (s[i + 1] == '#')
					j++;
				if (s[i + 5] == '#')
					j++;
			}
			i++;
		}
		if (j < 3)
			return (1);
		i++;
	}
	return (0);
}
