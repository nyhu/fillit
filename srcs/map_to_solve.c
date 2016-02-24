/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:43:31 by tboos             #+#    #+#             */
/*   Updated: 2016/02/24 23:10:36 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_tetris_def_type(t_int **tetris_tab)
{
	int				i;
	int				j;
	int				type;

	i = 0;
	type = 1;
	tetris_tab[0][5] = type;
	while (tetris_tab[++i])
	{
		j = i;
		while (j--)
			if (!(tetris_tab[i][0] ^ tetris_tab[j][0])
				&& !(tetris_tab[i][1] ^ tetris_tab[j][1])
				&& !(tetris_tab[i][2] ^ tetris_tab[j][2])
				&& !(tetris_tab[i][3] ^ tetris_tab[j][3]))
				tetris_tab[i][5] = tetris_tab[j][5];
		if (!(tetris_tab[i][5]))
		{
			type = type << 1;
			tetris_tab[i][5] = type;
		}
	}
}

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

t_int		*ft_map_init(void)
{
	t_int			*map;
	int				i;

	if (!(map = (t_int *)malloc(sizeof(t_int) * 16)))
		return (NULL);
	i = 0;
	while (i < 16)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}

void		ft_map_mask(t_int *map, int edge, int mode)
{
	if (mode)
	{
		mode = 0;
		while (mode < edge - 1)
		{
			map[mode] = map[mode] << 1;
			mode++;
		}
		map[mode] = map[mode] << edge;
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

int			ft_solve_map(t_int **tetris_tab, t_int *map, int edge, int stage)
{
	int				x;
	int				y;

	if (!(tetris_tab[stage]))
		return (1);
	x = 0;
	y = ft_check_type(tetris_tab, stage, &x);
	while (CMP_L1 || CMP_L2 || CMP_L3 || CMP_L4)
		if (!(ft_tetris_slide(tetris_tab[stage], edge, &x, &y)))
			return (0);
	ft_set_tetris(tetris_tab[stage], map, y);
	while (!(ft_solve_map(tetris_tab, map, edge, stage + 1)))
	{
		ft_set_tetris(tetris_tab[stage], map, y);
		if (!(ft_tetris_slide(tetris_tab[stage], edge, &x, &y)))
			return (0);
		while (CMP_L1 || CMP_L2 || CMP_L3 || CMP_L4)
			if (!(ft_tetris_slide(tetris_tab[stage], edge, &x, &y)))
				return (0);
		ft_set_tetris(tetris_tab[stage], map, y);
	}
	return (1);
}
