/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 20:12:55 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_exit(int mode)
{
	if (mode)
		ft_putstr_fd("error\n", 1);
	exit(0);
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
