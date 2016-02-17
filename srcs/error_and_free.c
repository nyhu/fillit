/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:45:01 by tboos             #+#    #+#             */
/*   Updated: 2016/02/17 20:45:09 by tboos            ###   ########.fr       */
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
