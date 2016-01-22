/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_the_diese.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			search_the_diese(char *piece, t_tetriminos *tetri, int *nb, int i)
{
	unsigned	long	unite;

	unite = 1;
	if (piece[i] == '#')
	{
		piece[i] = '.';
		*tetri->valu += unite << (i % 5 + ((i / 5) * 8) );
		*nb += 1;
		actual_mini_maxi(tetri, i);
		if (i - 5 >= 0)
			search_the_diese(piece, val, nb, i - 5);
		if ((i - 1 ) % 5 != 4)
			search_the_diese(piece, val, nb, i - 1);
		if ((i + 1 ) % 5 != 0 && (i + 1) % 5 != 4)
			search_the_diese(piece, val, nb, i + 1);
		if (i + 5 < 20)
			search_the_diese(piece, val, nb, i + 5);
	}
	else if (piece[i] != '.')
		tetri->id = 0;
}
