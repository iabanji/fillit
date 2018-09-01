/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:01:22 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/13 17:10:49 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_countmarg(char *s, int *arr)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		if (s[arr[i] - 1] == '#' && arr[i] - 1 > -1)
			count++;
		if (s[arr[i] + 1] == '#' && arr[i] + 1 < 19)
			count++;
		if (s[arr[i] - 5] == '#' && arr[i] - 5 > -1)
			count++;
		if (s[arr[i] + 5] == '#' && arr[i] + 5 < 19)
			count++;
	}
	return (count);
}

int		ft_isnorm(char *s, int *arr)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (arr[i] + 5 < 19 && arr[i] - 5 > -1)
		{
			if (s[arr[i] - 1] != '#' && s[arr[i] + 1] != '#' &&
					s[arr[i] + 5] != '#' && s[arr[i] - 5] != '#')
				ft_exit("error");
		}
		else if (arr[i] + 5 < 19 && arr[i] - 5 < 1)
		{
			if (s[arr[i] - 1] != '#' && s[arr[i] + 1] != '#' &&
					s[arr[i] + 5] != '#')
				ft_exit("error");
		}
		else if (arr[i] + 5 > 18 && arr[i] - 5 > 0)
		{
			if (s[arr[i] - 1] != '#' && s[arr[i] + 1] != '#' &&
					s[arr[i] - 5] != '#')
				ft_exit("error");
		}
	}
	return (1);
}

int		ft_isvalid_map(char *str)
{
	int		i;
	int		j;
	int		*arr;

	if ((arr = (int*)malloc(sizeof(int) * 4)) == NULL)
		ft_exit("Out of memory");
	i = -1;
	j = -1;
	while (++i < 20)
	{
		if (str[i] == '#')
			arr[++j] = i;
	}
	if (ft_isnorm(str, arr) == 0 || ft_countmarg(str, arr) < 6)
		ft_exit("error");
	free(arr);
	return (1);
}

int		ft_checker_tetrimino(char *str)
{
	int		i;
	int		count;

	if (!str)
		return (0);
	count = 0;
	i = -1;
	while (++i < 20)
	{
		if (((i % 5) != 4) && str[i] != '.' && str[i] != '#')
			return (0);
		if ((i % 5) == 4 && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			count++;
	}
	if (count != 4)
		ft_exit("error");
	if (ft_isvalid_map(str) == 0)
		ft_exit("error");
	return (1);
}

int		ft_checkings(int fd, char *tetrimino_box)
{
	int		size;
	char	*s;
	int		i;

	i = -1;
	if ((s = (char *)malloc(sizeof(char) * 26)) == NULL)
		ft_exit("Out of memory");
	ft_memset(s, 0, 26);
	size = 0;
	while (read(fd, tetrimino_box, 20))
	{
		if (ft_checker_tetrimino(tetrimino_box) == 0)
			ft_exit("error");
		size++;
		if (size > 26)
			ft_exit("error");
		read(fd, &s[++i], 1);
		if (s[i] != '\n' && s[i] != '\0')
			ft_exit("error");
		ft_memset(tetrimino_box, 0, 21);
	}
	if (ft_strlen(s) >= (size_t)size)
		ft_exit("error");
	free(s);
	return (size);
}
