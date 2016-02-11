/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/11 10:15:49 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void				ft_init_tetri_tab(t_tetriminos *tetri_tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tetri_tab[i].id = i + 'A';
		tetri_tab[i].valu = 0;
		tetri_tab[i].xp = 8;
		tetri_tab[i].yp = 8;
		tetri_tab[i].xd = 0;
		tetri_tab[i].yd = 0;
		tetri_tab[i].xs = 0;
		tetri_tab[i].ys = 0;
	}
}

void				tetris_define_type(t_tetriminos *tetri_tab, int nb)
{
	int				type_max;
	t_tetriminos	*tetris;
	int				first;

	type_max = 1;
	tetris = tetri_tab;
	first = 1;
	while (nb)
	{
		first = 0;
		if (tetri_tab->type > type_max)
			type_max = tetri_tab->type;
		if (tetri_tab->valu == tetris->valu)
			break;
		tetri_tab--;
		nb--;
	}
	if (nb)
		tetris->type = tetri_tab->type;
	else if (first)
		tetris->type = type_max;
	else
		tetris->type = type_max << 1;
}

void			finished_tetriminos(t_tetriminos *tetris)
{
	tetris->gap = (tetris->gap % 5) - tetris->xp; 
	tetris->xd = tetris->xd - tetris->xp;
	tetris->yd = tetris->yd - tetris->yp;
	tetris->valu = tetris->valu >> (tetris->xp + (tetris->yp * 8));
	tetris->xp = 0;
	tetris->yp = 0;
}
