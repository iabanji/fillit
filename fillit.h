/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:27:24 by anestor           #+#    #+#             */
/*   Updated: 2017/11/13 17:20:01 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_lst
{
	int				*map_xy;
	char			letter;
	struct s_lst	*next;
}					t_lst;

unsigned long		g_max;

int					ft_check(char *file);
t_lst				*ft_ltnew(int *map_xy, char letter);
void				ft_ltadd_back(t_lst **alst, t_lst *new);
t_lst				*ft_create_lst(char *file, int size, char ltr);
char				**ft_tetrimino_matrix(char *tetrimino_box);
int					ft_create_lst_elem_sub(char **tetrimino_matrix,
												int *map_xy, int x, int y);
void				ft_create_lst_elem(t_lst **temp,
										char **tetrimino_matrix, char letter);
void				ft_doit(t_lst *tet_list, int square_size);
void				ft_print_square(char **square);
char				**ft_create_map(int size);
int					ft_place_check(int x, int y, char **square,
														t_lst *tetrimino);
void				ft_put_tetrimino(int x, int y, char **square,
														t_lst *tetrimino);
void				ft_del_tetrimino(int x, int y, char **square,
														t_lst *tetrimino);
int					ft_put_recursion(char **square, t_lst *tet_list,
															int square_size);
int					ft_countmarg(char *s, int *arr);
int					ft_isnorm(char *s, int *arr);
int					ft_isvalid_map(char *str);
int					ft_checker_tetrimino(char *str);
int					ft_checkings(int fd, char *tetrimino_box);
int					ft_sqr(int k);
void				ft_exit(char *text);

#endif
