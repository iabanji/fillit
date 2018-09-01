/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:46:46 by anestor           #+#    #+#             */
/*   Updated: 2017/11/13 17:28:04 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_square(char **square)
{
	int		n;
	int		k;

	k = 0;
	while (square[k] != '\0')
	{
		n = 0;
		while (square[k][n] != '\n')
		{
			ft_putchar(square[k][n]);
			n++;
		}
		ft_putchar(square[k][n]);
		k++;
	}
}

char	**ft_create_map(int size)
{
	char	**temp;
	int		n;

	temp = (char **)malloc(sizeof(char *) * (size + 1));
	temp[size] = 0;
	n = 0;
	while (n != size)
	{
		temp[n] = (char *)malloc(sizeof(char) * (size + 2));
		ft_memset(temp[n], '.', size);
		temp[n][size] = '\n';
		temp[n][size + 1] = '\0';
		n++;
	}
	return (temp);
}

char	**ft_tetrimino_matrix(char *tetrimino_box)
{
	int		n;
	char	**tetrimino_matrix;

	tetrimino_matrix = (char **)malloc(sizeof(char *) * 4);
	n = 0;
	while (n != 4)
	{
		tetrimino_matrix[n] = (char *)malloc(sizeof(char) * 4);
		ft_memcpy(tetrimino_matrix[n], tetrimino_box, 4);
		tetrimino_box = tetrimino_box + 5;
		n++;
	}
	return (tetrimino_matrix);
}

int		ft_sqr(int k)
{
	int		i;

	i = 1;
	while (i * i < k)
	{
		i++;
	}
	return (i);
}

void	ft_exit(char *text)
{
	ft_putendl(text);
	exit(-1);
}
