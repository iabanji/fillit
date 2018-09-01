/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:26:53 by anestor           #+#    #+#             */
/*   Updated: 2017/11/13 17:30:33 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_lst	*tet_list;
	int		n;

	if (argc > 2)
		ft_exit("Argument list too long");
	if (argc < 2)
		ft_exit("Argument list too small");
	n = ft_check(argv[1]);
	if (n < 1)
		ft_exit("error");
	tet_list = ft_create_lst(argv[1], n, 'A');
	ft_doit(tet_list, ft_sqr(4 * n));
	return (0);
}

int		ft_check(char *file)
{
	char	*tetrimino_box;
	int		fd;
	int		size;

	if ((tetrimino_box = (char *)malloc(sizeof(char) * 20)) == NULL)
		ft_exit("Out of memory");
	fd = open(file, O_RDWR);
	if (fd == -1)
		ft_exit("No such file or directory");
	size = ft_checkings(fd, tetrimino_box);
	close(fd);
	free(tetrimino_box);
	return (size);
}
