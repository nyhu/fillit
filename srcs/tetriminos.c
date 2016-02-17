/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 19:24:02 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

u_int					**ft_init_tetris_tab(int nb)
{
	u_int	**tetris_tab;

	if (!(tetris_tab = (u_int **)malloc(sizeof(u_int *) * nb)))
		ft_exit(1);
	nb--;
	while (nb > -1)
	{
		if (!(tetris_tab[nb] = (u_int *)malloc(sizeof(u_int) * 4)))
		{
			free(tetris_tab);
			ft_exit(1);
		}
		tetris_tab[nb][0] = 0;
		tetris_tab[nb][1] = 0;
		tetris_tab[nb][2] = 0;
		tetris_tab[nb][3] = 0;
		nb--;
	}
	return (tetris_tab);
}

int				ft_check_interbackn(char *tab, int ret)
{
	int		i;

	i = 20;
	while (i < ret && tab[i] == '\n')
		i += 21;
	if (i < ret)
		return (0);
	return (1);
}

void			ft_free_tetris_tab(u_int **tetris_tab, int nb)
{
	nb--;
	while (nb >= 0)
	{
		free(tetris_tab[nb]);
		nb--;
	}
	free(tetris_tab);
}
