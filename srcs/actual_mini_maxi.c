/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_mini_maxi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			actual_mini_maxi(t_tetriminos *tetri, int i)
{
		if ((i % 8) < pos->x)
			pos->x = i % 8;
		if ((i / 8) < pos->y)
			pos->y = i / 8;
		if ((i % 8) > dim->x)
			dim->x = i % 8;
		if ((i / 8) > dim->y)
			dim->y = i / 8;
}
