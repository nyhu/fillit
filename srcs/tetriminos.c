/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 06:19:26 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void				create_tetriminos(t_tetriminos *piece, int id)
{
	piece->id = id + 'A';
	piece->valu = 0;
	piece->xp = 8;
	piece->yp = 8;
}

void				tetris_define_type(t_tetriminos *elem)
{
	int				type_max;
	t_tetriminos	*tetris;
	int				first;

	type_max = 1;
	tetris = elem->prev;
	first = 1;
	while (tetris && tetris->valu != elem->valu)
	{
		first = 0;
		if (tetris->type > type_max)
			type_max = tetris->type;
		tetris = tetris->prev;
	}
	if (tetris)
		elem->type = tetris->type;
	else if (first)
		elem->type = type_max;
	else
		elem->type = type_max << 1;
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
