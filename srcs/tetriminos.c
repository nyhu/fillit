/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 16:29:36 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					**ft_init_tetri_tab(int nb)
{
	u_int	**tetris_tab;

	if (!(tetris_tab = (u_int **)malloc(sizeof(u_int *) * nb)))
		return (NULL);
	nb--;
	while (nb > -1)
	{
		if (!(tetris_tab[nb] = (u_int *)malloc(sizeof(u_int) * 4)))
			return (NULL);
		tetris_tab[nb][0] = 0;
		tetris_tab[nb][1] = 0;
		tetris_tab[nb][2] = 0;
		tetris_tab[nb][3] = 0;
		nb--;
	}
	return (tetris_tab);
}
