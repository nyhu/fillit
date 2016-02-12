/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 20:05:26 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/12 05:07:08 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manip_bin.h"

unsigned	long	get_vertical_mask(int size)
{
	static	unsigned	long	masks[9];
	static	int					init = 1;
	unsigned	long			vertical;
	int							i;
	int							j;

	if (init)
	{
		init = 0;
		vertical = VERTICAL;
		j = 0;
		while (j < 9)
		{
			i = 0;
			masks[j] = 0;
			while (i < j)
			{
				masks[j] |= vertical << i;
				i++;
			}
			j++;
		} 
	}
	return (masks[size]);
}

unsigned	long	get_horizontal_mask(int size)
{
	static	unsigned	long	masks[9];
	static	int					init = 1;
	unsigned	long			horizontal;
	int							i;
	int							j;

	if (init)
	{
		init = 0;
		horizontal = HORIZONTAL;
		j = 0;
		while (j < 9)
		{
			i = 0;
			masks[j] = 0;
			while (i < j)
			{
				masks[j] |= horizontal << (i * 8);
				i++;
			}
			j++;
		} 
	}
	return (masks[size]);
}

void		ft_resting_posx(t_tetriminos *elem)
{
	elem->valu >>= (elem->xp);
	elem->xp = 0;
}

void		ft_resting_posy(t_tetriminos *elem)
{
	elem->valu >>= ((elem->yp) * 8);
	elem->yp = 0;
}
