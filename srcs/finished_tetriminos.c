/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finished_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			finished_tetriminos(t_tetriminos tetri)
{
	tetri->dim->x = tetri->dim->x - tetri->pos->x;
	tetri->dim->y = tetri->dim->y - tetri->pos->y;
	tetri->valu  = tetri->valu >> (tetri->pos->x + (tetri->pos->y * 8));
	tetri->pos->x = 0;
	tetri->pos->y = 0;
	tetris_define_type(tetri);
}
