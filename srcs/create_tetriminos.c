/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tetriminos	*create_tetriminos(int id)
{
	t_tetriminos	*piece;

	if (!(piece = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
		return (NULL);
	if (!(piece->dim = create_coordone()) || !(piece->pos = create_coordone()))
		return (NULL);
	piece->id = id + 'A';
	piece->valu = 0;
	piece->pos->x = 8;
	piece->pos->y = 8;
	piece->next = 0;
	piece->prev = 0;
	return (piece);
}
