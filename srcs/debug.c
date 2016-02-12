/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:46:52 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/12 06:05:31 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_long(unsigned long valu)
{
	int					i;
	int					j;
	unsigned	long	unite;
	
	i = 0;
	j = 0;
	unite = 1;
	while (j < 8)
	{
		while (i < 8)
		{
			if (valu & unite << (i + (8 * j)))
				printf("#");
			else
				printf(".");
			i++;
		}
		printf("\n");
		j++;
	}
}

void	print_working_windows(unsigned long *windows)
{
	int	nb_windows;
	int	j;

	j = 0;
	nb_windows = glb_nb_windows(GET, 0);
	while (j < nb_windows)
	{
		dprintf(1, "windows:%d", j);
		print_long(windows[j]);
		j++;
	}
	dprintf(1, "\n");
}

void	print_ground(t_sqare *sqr)
{
	int	i;
	int	j;
	unsigned long unite;

	j = 0;
	unite = 1;
	dprintf(1, "len_sqr:%d\n", sqr->dim);
	while (j < 16)
	{
		i = 0;
		while (i < 16)
		{
			if (i == 8)
				dprintf(1, " | ");
			if (sqr->area[i / 8][j / 8] & (unite << ((i % 8) + (8 * (j % 8)))))
				dprintf(1, "#");
			else
				dprintf(1, ".");
			i++;
		}
		dprintf(1, "\n");
		j++;
		if (j == 8)
			dprintf(1, "--------   --------\n");
	}
}

void	print_tetris(t_tetriminos *piece)
{
	int					i;
	int					j;
	unsigned	long	unite;

	dprintf(1, "\n");
	unite = 1;
	j = 0;
	while (j < 8)
	{
		i = 0;
		while (i < 8)
		{
			if (piece->valu & (unite << (j * 8 + i)))
				dprintf(1, "#");
			else
				dprintf(1, ".");
			i++;
		}
		dprintf(1, "\n");
		j++;
	}
}

void	print_coordone(int x, int y, char *name)
{
	dprintf(1, "%s: x:%d ", name, x);
	dprintf(1, "%s: y:%d\n", name, y);
}

void	describe_tetris(t_tetriminos *tetris)
{
	print_tetris(tetris);
	dprintf(1, "valu :%ld   ", (long)tetris->valu);
	dprintf(1, "id   :%c   ", tetris->id);
	dprintf(1, "type :%d   ", tetris->type);
	dprintf(1, "gap  :%d\n", tetris->gap);
	print_coordone(tetris->xd, tetris->yd, " dim");
	print_coordone(tetris->xp, tetris->yp, " pos");
	print_coordone(tetris->xs, tetris->ys, " ecr");
}

void	print_all_tetris(t_tetriminos *tetris)
{
	if (tetris->id >= 'A' && tetris->id <= 'Y')
	{
		describe_tetris(tetris);
		print_all_tetris(tetris++);
	}
	if (tetris->id == 'Z')
		describe_tetris(tetris);
}
