/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 20:42:24 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

u_int					**ft_init_tetris_tab(int nb)
{
	u_int	**tetris_tab;

	if (!(tetris_tab = (u_int **)malloc(sizeof(u_int *) * nb)))
		ft_exit(1);
	nb--;
	while (nb > -1)
	{
		if (!(tetris_tab[nb] = (u_int *)malloc(sizeof(u_int) * 5)))
		{
			free(tetris_tab);
			ft_exit(1);
		}
		tetris_tab[nb][0] = 0;
		tetris_tab[nb][1] = 0;
		tetris_tab[nb][2] = 0;
		tetris_tab[nb][3] = 0;
		tetris_tab[nb][4] = 0;
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
