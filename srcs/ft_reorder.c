/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <toussaint.boos@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:15:02 by tboos             #+#    #+#             */
/*   Updated: 2016/02/12 09:46:41 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tetriminos	**ft_reorder(t_tetriminos **arrow, int stage, int len)
{
	int				i;
	int				m;

	if ((stage - 1) >= 0)
		ft_remouve_tetris(arrow[stage - 1]);
	while (stage < len)
	{
		i = stage + 1;
		m = stage;
		while (i <= len)
		{
			if (arrow[i]->id < arrow[m]->id)
				m = i;
			i++;
		}
		if (m != stage)
			ft_tetriswap(arrow, stage, m);
		stage++;
	}
	return (NULL);
}

void		ft_tetriswap(t_tetriminos **arrow, int stage, int i)
{
	t_tetriminos	*s;

	s = arrow[stage];
	arrow[stage] = arrow[i];
	arrow[i] = s;
}
