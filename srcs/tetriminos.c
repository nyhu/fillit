/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/12 11:20:44 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"
#include <stdio.h>

void				create_tetriminos(t_tetriminos *piece, int id)
{
	piece->id = id + 'A';
	piece->valu = 0;
	piece->xp = 8;
	piece->yp = 8;
}

void				tetris_define_type(t_tetriminos *array, int nb)
{
	int				type_max;
	t_tetriminos	*tetris;
	int				first;

	type_max = 1;
	tetris = &(array[nb]);
	first = 1;
	nb--;
	while (nb >= 0)
	{
		first = 0;
		if ((array[nb]).type > type_max)
			type_max = (array[nb]).type;
		if ((array[nb]).valu == tetris->valu)
			break;
		nb--;
	}
	if (nb)
		tetris->type = (array[nb]).type;
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
