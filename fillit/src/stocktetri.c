/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocktetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:09:21 by mberedda          #+#    #+#             */
/*   Updated: 2016/01/22 21:39:06 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		creer_compteur(t_compteur *compteur)
{
	compteur->i = 0;
	compteur->j = 0;
	compteur->k = 0;
	compteur->l = 0;
}

static void		cut_fcnt2(t_tetrim *data, t_compteur *compteur)
{
	data->coor[compteur->k][0] = compteur->i - compteur->l;
	data->coor[compteur->k][1] = compteur->j;
	compteur->k++;
}

static t_tetrim	*cut_fcnt3(t_tetrim *data, t_compteur *compteur)
{
	compteur->l = compteur->i + 1;
	data->next = ft_create_elem();
	data->next->index = data->index + 1;
	data = data->next;
	compteur->k = 0;
	return (data);
}

t_tetrim		*stocktetri(char **tab)
{
	t_tetrim	*data;
	t_tetrim	*beggin;
	t_compteur	*compteur;

	compteur = malloc(sizeof(t_compteur));
	creer_compteur(compteur);
	data = ft_create_elem();
	beggin = data;
	while (tab[compteur->i] != '\0')
	{
		compteur->j = 0;
		while (tab[compteur->i][compteur->j] != '\0')
		{
			if (tab[compteur->i][compteur->j] >= 'A' &&
					tab[compteur->i][compteur->j] <= 'Z')
				cut_fcnt2(data, compteur);
			if (compteur->k == 4 && tab[compteur->i + 1] != '\0')
				data = cut_fcnt3(data, compteur);
			compteur->j++;
		}
		compteur->i++;
	}
	return (beggin);
}
