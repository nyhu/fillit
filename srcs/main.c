/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:55:56 by tboos             #+#    #+#             */
/*   Updated: 2016/02/24 23:00:49 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_print_result(t_int **tetris_tab, int edge)
{
	char			*result;

	if (!(result = ft_init_result(edge)))
	{
		ft_free_tetris_tab(tetris_tab);
		ft_exit(1);
	}
	ft_fill_result(tetris_tab, result, edge);
	ft_putstr(result);
	ft_free_tetris_tab(tetris_tab);
	exit(0);
}

static void		ft_solve(t_int **tetris_tab, int nb)
{
	int				edge;
	t_int			*map;

	edge = ft_find_edge(nb);
	ft_tetris_def_type(tetris_tab);
	if (!(map = ft_map_init()))
	{
		ft_free_tetris_tab(tetris_tab);
		ft_exit(1);
	}
	ft_map_mask(map, edge, 0);
	while (!(ft_solve_map(tetris_tab, map, edge, 0)))
	{
		edge++;
		ft_map_mask(map, edge, 1);
	}
	free(map);
	ft_print_result(tetris_tab, edge);
}

static void		ft_filling(char *tab, int ret)
{
	t_int	**tetris_tab;
	int		nb;
	int		i;

	nb = (ret + 1) / 21;
	i = 0;
	if (!(tetris_tab = ft_init_tetris_tab(nb)))
		ft_exit(1);
	if ((ft_check_interbackn(tab, ret)))
	{
		while (i < nb)
		{
			if (!(get_next_piece(tab + (i * 21), *(tetris_tab + i))))
				nb = 0;
			i++;
		}
		if (nb)
			ft_solve(tetris_tab, nb);
	}
	ft_free_tetris_tab(tetris_tab);
	ft_exit(1);
}

static void		ft_read(int fd)
{
	int		ret;
	char	buf[BUF];

	if ((ret = read(fd, buf, BUF)))
		if ((ret + 1) % 21 == 0)
		{
			buf[ret] = '\0';
			close(fd);
			ft_filling(buf, ret);
		}
	close(fd);
	ft_exit(1);
}

int				main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
		if ((fd = open(av[1], O_RDONLY, S_IREAD)) > 0)
			ft_read(fd);
	if (ac == 1)
	{
		ft_putstr_fd("usage: fillit missing_input_file\n", 1);
		ft_exit(0);
	}
	ft_exit(1);
	return (0);
}
