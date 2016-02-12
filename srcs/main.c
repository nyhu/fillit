/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/12 21:43:03 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF];

	if (ac == 2)
		if ((fd = open(av[1], O_RDONLY, S_IREAD)) > 0)
		{
			if ((ret = read(fd, buf, BUF)))
				if ((ret + 1) % 21 == 0)
				{
					buf[ret] = '\0';
					close(fd);
					fillit_structure(buf, ret);
				}
			close(fd);
			ft_putstr_fd("error\n", 1);
		}
	if (ac != 2)
		ft_putstr_fd("usage: fillit source_file\n", 1);
	return (0);
}
