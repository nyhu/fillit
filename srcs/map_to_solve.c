/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:43:31 by tboos             #+#    #+#             */
/*   Updated: 2016/02/17 21:45:57 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_find_edge(int nb)
{
	int				i;
	int				edge;

	i = nb * 4;
	edge = 1;
	while (i > 0)
	{
		i = i - edge;
		edge += 2;
	}
	edge = (edge - 1) / 2;
	return (edge);
}

u_int		*ft_map_init(void)
{
	u_int			*map;
	int				i;

	if (!(map = (u_int *)malloc(sizeof(u_int) * 16)))
		return (NULL);
	i = 0;
	while (i < 16)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}

void		ft_map_mask(u_int *map, int edge, int mode)
{
	if (mode)
	{
		mode = 0;
		while (mode < edge)
		{
			map[mode] = map[mode] << 1;
			mode++;
		}
	}
	if (!mode)
	{
		while (mode < edge)
		{
			map[mode] = MAX << edge;
			mode++;
		}
		map[edge] = MAX;
		mode++;
		while (mode < 16)
		{
			map[mode] = MAX;
			mode++;
		}
	}
}

int			ft_solve_map(u_int **tetris_tab, u_int *map, int edge, int stage)
{
	int				x;
	int				y;

	if (!(tetris_tab[stage]))
		return (1);
	x = 0;
	y = 0;
	while (tetris_tab[stage][0] & map[y] || tetris_tab[stage][1] & map[y + 1]
		|| tetris_tab[stage][2] & map[y + 2] || tetris_tab[stage][3] & map[y + 3])
		if (!(ft_tetris_slide(tetris_tab[stage], edge, &x, &y)))
			return (0);
	ft_set_tetris(tetris_tab[stage], map, y);
	while (!(ft_solve_map(tetris_tab, map, edge, stage + 1)))
	{
		ft_set_tetris(tetris_tab[stage], map, y);
		while (tetris_tab[stage][0] & map[y] || tetris_tab[stage][1] & map[y + 1]
			|| tetris_tab[stage][2] & map[y + 2] || tetris_tab[stage][3] & map[y + 3])
			if (!(ft_tetris_slide(tetris_tab[stage], edge, &x, &y)))
				return (0);
		ft_set_tetris(tetris_tab[stage], map, y);
	}
	return (1);
}
