/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 16:29:32 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	fillit_structure(char *tab, int ret)
{
	int				**tetris_tab;
	int				**map;
	int				nb;
	int				i;

	nb = (ret + 1) / 21;
	if (!(tetris_tab = ft_init_tetris_tab(nb)))
		ft_exit(1);
	if (!(tetris_tab = ft_filling_tetris(tab, ret, nb, tetri_tab)))
		ft_exit(1);
	glb_ground(SET, ft_init_ground(&ground));
	tetri_tab = ft_squ_lunch(tetri_tab, nb);
	ft_print_result(tetri_tab, nb);
	ft_exit(0);
}

static void	ft_read(fd)
{
	int		ret;
	char	buf[BUF];

	if ((ret = read(fd, buf, BUF)))
	{
		if ((ret + 1) % 21 == 0)
		{
			buf[ret] = '\0';
			close(fd);
			fillit_structure(buf, ret);
		}
	}
}

int			main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY, S_IREAD)) > 0)
		{
			ft_read(fd);
			close(fd);
		}	
	}
	else if (ac = 1)
	{
		ft_putstr_fd("usage: fillit missing_input_file\n", 1);
		ft_exit(0);
	}
	ft_exit(1);
	return (0);
}
