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
		i = i - j;
		edge += 2;
	}
	edge = (edge - 1) / 2;
	return (edge);
}

u_int		*ft_map_init(void)
{
	u_int			*map;
	int				i;

	if (!(map = (u_int *)malloc(sizeof(int) * 16)))
		return (NULL);
	i = 0;
	while (i < 16)
	{
		map[i] = 0;
		i++;
	}
	return (map);
}

void		ft_map_mask(int *map, int edge, int mode)
{
	if (mode)
	{
		mode = 0
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
			mode++
		}
		map[edge] = MAX;
		mode++;
		while (mode < 31)
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
	while (tetris_tab[stage] & map[x])
}
