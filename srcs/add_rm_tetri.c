/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:11:42 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/13 00:16:02 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_rm_tetri.h"
#include "debug.h"
#include <stdio.h>

/*area[x][y]*/
unsigned	long	ft_working_window(t_sqare *gr, int x, int y)
{
	unsigned	long	mh;
	unsigned	long	mv;
	unsigned	long	ecr;

	mh = get_vertical_mask(x);
	mv = get_horizontal_mask(y);
	ecr = ((gr->area[0][0] & ~mv & ~mh) >> (x + (8 * y)));
	ecr |= (((gr->area[0][1] & mv & ~mh) >> x) << (8 * (8 - y)));
	ecr |= (((gr->area[1][0] & ~mv & mh) << (8 - x)) >> (8 * y));
	ecr |= ((gr->area[1][1] & mv & mh) << ((8 - x) + (8 * (8 - y))));
	return (ecr);
}

void	ft_init_windows(unsigned long *windows, int stage)
{
	int					i;
	t_sqare				*ground;
	int					nb_win;
	int					x;
	int					y;

	ground = glb_ground(GET, 0);
	nb_win = glb_nb_windows(GET, 0);
	i = 0;
	y = stage * 4;
	while (i < nb_win)
	{
		x = (i * 4);
		windows[i] = ft_working_window(ground, x, y);
		i++;
	}
}

int		ft_set_tetris(unsigned long valu, int x, int y)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_sqare				*gr;

	gr = glb_ground(GET, 0);
	x *= 4;
	y *= 4;
	mv = get_vertical_mask(8 - x);
	mh = get_horizontal_mask(8 - y);
	gr->area[0][0] ^= (valu & mv & mh) << (x + (8 * y));
	gr->area[0][1] ^= ((valu & mv & ~mh) << x) >> (8 * (8 - y ));
	gr->area[1][0] ^= ((valu & ~mv & mh) >> (8 - x)) << (8 * y);
	gr->area[1][1] ^= (valu & ~mv & ~mh) >> (8 - x + (8 * (8 - y)));
	return (1);
}

void	ft_remouve_tetris(t_tetriminos *tetri)
{
	ft_set_tetris(tetri->valu, tetri->xs, tetri->ys);
	ft_resting_posx(tetri);
	ft_resting_posy(tetri);
	tetri->xs = 0;
	tetri->ys = 0;
}

int		ft_last_loop(t_tetriminos *elem, t_tetriminos tetri, int dim, unsigned long *windows)
{
	while ((X < 8 - DIM_X) && X + (4 * ECR_X) < dim - DIM_X)
	{
		if ((tetri.valu & windows[ECR_X]) == 0)
		{
			ft_set_tetris(tetri.valu, ECR_X, ECR_Y);
			*elem = tetri;
			return (1);
		}
		tetri.valu <<= 1;
		(X)++;
	}
	(ECR_X)++;
	ft_resting_posx(&tetri);
	return (0);
}

static	void	ft_ending_push(t_tetriminos *elem, t_tetriminos *tetri)
{
	*elem = *tetri;
	ft_resting_posy(elem);
	ft_resting_posx(elem);
	elem->xs = 0;
	elem->ys = 0;
}

int		ft_push_tetriminos(t_tetriminos *elem, int dim)
{
	unsigned	long	windows[3];
	int					nb_windows;
	t_tetriminos		tetri;
	
	tetri = *elem; 
	nb_windows = glb_nb_windows(GET, 0);
	while (ECR_Y < nb_windows)
	{
		ft_init_windows(windows, ECR_Y);
		while ((Y < 8 - DIM_Y) && Y + (4 * ECR_Y) < dim - DIM_Y)
		{
			while(ECR_X < nb_windows)
			{
				if (ft_last_loop(elem, tetri, dim, windows))
					return (1);
			}
			ECR_X = 0;
			tetri.valu <<= 8;
			(Y)++;
		}
		(ECR_Y)++;
	}
	ft_ending_push(elem, &tetri);
	return (0);
}
