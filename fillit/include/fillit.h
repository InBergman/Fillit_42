/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaubie <ldaubie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:06:00 by ldaubie           #+#    #+#             */
/*   Updated: 2016/01/19 14:33:47 by ldaubie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFFER_SIZE 1024
# include "libft.h"

typedef struct		s_tetrim
{
	int				index;
	int				coor[4][2];
	struct s_tetrim *next;
}					t_tetrim;

typedef struct		s_result
{
	int				i;
	int				tab[15][15];
	struct s_result *next;
}					t_result;

typedef struct		s_compteur
{
	int				i;
	int				j;
	int				k;
	int				l;
}					t_compteur;

int					line(char *s);
int					ft_checkall(char *s);
int					ft_checkall2(char *s);
int					check_place(t_tetrim *data, t_result *map, int x, int y);
int					check_newline(char *s);
int					check_file(char *s);
int					check_diese(char *s);
int					check_dieseside(char *s);
int					check_dieselink(char *s);
char				ft_error(void);
char				**empty_line(char **tab);
char				*delpoin(char *s);
char				*space(char *s);
char				*delspace(char *s);
char				*namediese(char *s);
char				**ft_tetri(char **tableau, char *s);
char				**filltab(char **tab);
t_result			*remptab(t_tetrim *data, t_result *map, t_result *res);
void				afficher_sol(t_result *map);
t_tetrim			*stocktetri(char **str);
t_tetrim			*ft_create_elem(void);
t_result			*ft_create_elem2(void);
t_result			*new_map(t_tetrim *data, t_result *map, int x, int y);
t_result			*cut_fcnt(t_tetrim *data, t_result *map,
t_result			*res, int x);
#endif
