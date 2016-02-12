/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coordone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/12 05:20:52 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordone.h"

t_coordone		*create_coordone(void)
{
	t_coordone	*position;

	if (!(position = (t_coordone*)malloc(sizeof(t_coordone))))
		return (NULL);
	position->x = 0;
	position->y = 0;
	return (position);
}

t_coordone		*create_coordone_y(int y)
{
	t_coordone	*position;

	if (!(position = (t_coordone*)malloc(sizeof(t_coordone))))
		return (NULL);
	position->x = 0;
	position->y = y;
	return (position);
}

void			copy_coordone(t_coordone *pos_dst, t_tetriminos *tetris)
{
	pos_dst->x = tetris->xp + (tetris->xp * 4);
	pos_dst->y = tetris->yp + (tetris->yp * 4);
}
