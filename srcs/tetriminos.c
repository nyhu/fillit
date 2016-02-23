/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 21:45:56 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

u_int					**ft_init_tetris_tab(int nb)
{
	u_int	**tetris_tab;

	if (!(tetris_tab = (u_int **)malloc(sizeof(u_int *) * (nb + 1))))
		ft_exit(1);
	tetris_tab[nb--] = NULL;
	while (nb > -1)
	{
		if (!(tetris_tab[nb] = (u_int *)ft_memalloc(sizeof(u_int) * 6)))
		{
			free(tetris_tab);
			ft_exit(1);
		}
		nb--;
	}
	return (tetris_tab);
}

void			ft_tetris_fall(u_int *tetris)
{
	while (!(tetris[0]))
	{
		tetris[0] = tetris[1];
		tetris[1] = tetris[2];
		tetris[2] = tetris[3];
		tetris[3] = 0;
	}
}

void			ft_tetris_reset(u_int *tetris)
{
	int		i;

	while (!(tetris[0] & 1) && !(tetris[1] & 1) && !(tetris[2] & 1))
	{
		i = 0;
		while (i < 4)
		{
			tetris[i] = tetris[i] >> 1;
			i++;
		}
	}
}

void			ft_set_tetris(u_int *tetris, u_int *map, int y)
{
	map[y] ^= tetris[0];
	map[y + 1] ^= tetris[1];
	map[y + 2] ^= tetris[2];
	map[y + 3] ^= tetris[3];
	tetris[4] = y;
}

int				ft_tetris_slide(u_int *tetris, int edge, int *x, int *y)
{
	if (*x < edge)
	{
		tetris[0] = tetris[0] << 1;
		tetris[1] = tetris[1] << 1;
		tetris[2] = tetris[2] << 1;
		tetris[3] = tetris[3] << 1;
		(*x)++;
	}
	else if (*x >= edge)
	{
		tetris[0] = tetris[0] >> *x;
		tetris[1] = tetris[1] >> *x;
		tetris[2] = tetris[2] >> *x;
		tetris[3] = tetris[3] >> *x;
		(*x) = 0;
		(*y)++;
		if (*y >= edge)
		{
			tetris[4] = 0;
			return (0);
		}
	}
	return (1);
}
