/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_define_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				tetris_define_type(t_teriminos *t_elem)
{
	int			type_max;
	t_teriminos	*tetri;

	type_max = 1;
	tetri = t_elem;
	while (tetri->valu != t_elem->valu)
	{
		if (tetri->type > type_max)
			type_max = tetri->type;
		tetri = tetri->prev;
	}
	if (tetri)
		t_elem->type = tetri->type;
	else
		t_elem->type = type_max << 1;
}
