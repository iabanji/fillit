/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:07:27 by anestor           #+#    #+#             */
/*   Updated: 2017/11/13 17:28:00 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_doit(t_lst *tet_list, int square_size)
{
	char	**square;
	int		k;

	square = ft_create_map(square_size);
	k = 0;
	g_max = 0;
	while (k != 1)
	{
		square = ft_create_map(square_size);
		k = ft_put_recursion(square, tet_list, square_size);
		if (k != 1)
		{
			g_max = 0;
			free(square);
			square_size++;
		}
	}
	ft_print_square(square);
}

int		ft_put_recursion(char **square, t_lst *tet_list, int square_size)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (g_max++ > 10000000)
		return (0);
	if (tet_list == NULL)
		return (1);
	while (y < square_size)
	{
		if (ft_place_check(x, y, square, tet_list) == 1)
		{
			ft_put_tetrimino(x, y, square, tet_list);
			if (ft_put_recursion(square, tet_list->next, square_size) == 1)
				return (1);
			ft_del_tetrimino(x, y, square, tet_list);
		}
		if (++x >= square_size)
		{
			x = 0;
			y++;
		}
	}
	return (0);
}

void	ft_del_tetrimino(int x, int y, char **square, t_lst *tetrimino)
{
	int		n;
	int		temp_x;
	int		temp_y;

	n = 0;
	while (n != 4)
	{
		temp_x = x + tetrimino->map_xy[n];
		temp_y = y + tetrimino->map_xy[n + 4];
		square[temp_y][temp_x] = '.';
		n++;
	}
}

void	ft_put_tetrimino(int x, int y, char **square, t_lst *tetrimino)
{
	int		n;
	int		temp_x;
	int		temp_y;

	n = 0;
	while (n != 4)
	{
		temp_x = x + tetrimino->map_xy[n];
		temp_y = y + tetrimino->map_xy[n + 4];
		square[temp_y][temp_x] = tetrimino->letter;
		n++;
	}
}

int		ft_place_check(int x, int y, char **square, t_lst *tetrimino)
{
	int		n;
	int		temp_x;
	int		temp_y;

	n = 0;
	while (n != 4)
	{
		temp_x = x + tetrimino->map_xy[n];
		temp_y = y + tetrimino->map_xy[n + 4];
		if (temp_x < 0 || temp_x >= (int)(ft_strlen(square[0])))
			return (0);
		if (temp_y >= (int)(ft_strlen(square[0]) - 1))
			return (0);
		n++;
	}
	n = 0;
	while (n != 4)
	{
		temp_x = x + tetrimino->map_xy[n];
		temp_y = y + tetrimino->map_xy[n + 4];
		if (square[temp_y][temp_x] != '.')
			return (0);
		n++;
	}
	return (1);
}
