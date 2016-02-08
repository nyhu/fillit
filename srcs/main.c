/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/04 19:16:03 by tboos            ###   ########.fr       */
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
			if ((ret = read(fd, tab, BUF)))
				if (!((ret % 21) - 1))
				{
					tab[ret] = '\0';
					close(fd);
					fillit_structure(tab, ret);
				}
			close(fd);
		}	
	ft_putstr_fd("error\n", 1);
	return (0);
}
