/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:51:58 by anestor           #+#    #+#             */
/*   Updated: 2017/11/13 17:28:02 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*ft_create_lst(char *file, int size, char ltr)
{
	int		fd;
	t_lst	**temp;
	t_lst	*tmp;
	char	*tetrimino_box;
	char	**tetrimino_matrix;

	if ((temp = (t_lst **)malloc(sizeof(t_lst *) * size)) == NULL)
		ft_exit("Out of memory");
	*temp = NULL;
	if ((tetrimino_box = (char *)malloc(sizeof(char) * 21)) == NULL)
		ft_exit("Out of memory");
	fd = open(file, O_RDWR);
	if (fd == -1)
		ft_exit("No such file or directory");
	while (read(fd, tetrimino_box, 21))
	{
		tetrimino_matrix = ft_tetrimino_matrix(tetrimino_box);
		ft_create_lst_elem(temp, tetrimino_matrix, ('A' + ('A' + ltr++) % 26));
	}
	close(fd);
	tmp = *temp;
	return (*temp);
}

int		ft_create_lst_elem_sub(char **tetrimino_matrix, int *map_xy,
																int x, int y)
{
	int		n;

	n = 0;
	while (y != 4)
	{
		x = 0;
		while (x != 4)
		{
			if (tetrimino_matrix[y][x] == '#')
			{
				map_xy[n] = x;
				map_xy[n + 4] = y;
				n++;
			}
			x++;
		}
		y++;
	}
	return (n);
}

void	ft_create_lst_elem(t_lst **temp, char **tetrimino_matrix, char letter)
{
	int		n;
	int		*map_xy;

	map_xy = (int *)malloc(sizeof(int) * 8);
	n = ft_create_lst_elem_sub(tetrimino_matrix, map_xy, 0, 0) - 1;
	while (n > -1)
	{
		map_xy[n] = map_xy[n] - map_xy[0];
		map_xy[n + 4] = map_xy[n + 4] - map_xy[4];
		n--;
	}
	ft_ltadd_back(temp, ft_ltnew(map_xy, letter));
}

t_lst	*ft_ltnew(int *map_xy, char letter)
{
	t_lst	*temp;

	if ((temp = (t_lst *)malloc(sizeof(t_lst))) == NULL)
		ft_exit("Out of memory");
	else
	{
		if ((temp->map_xy = (int *)malloc(sizeof(int) * 8)) == NULL)
			ft_exit("Out of memory");
		ft_memcpy(temp->map_xy, map_xy, (sizeof(int) * 8));
		temp->letter = letter;
	}
	temp->next = NULL;
	return (temp);
}

void	ft_ltadd_back(t_lst **alst, t_lst *new)
{
	t_lst	*temp;

	if (new && alst)
	{
		temp = *alst;
		if (*alst)
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			*alst = new;
	}
}
