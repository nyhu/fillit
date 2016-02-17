/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 07:38:47 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 19:51:56 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			first_diese(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && str[i] != '\n')
			return (-1);
		if (i % 5 != 4 && str[i] == '#')
			return (i);
		else if (i % 5 != 4 && str[i] != '.')
			return (-1);
		i++;
	}
	return (-1);
}

static void			search_the_diese(char *piece, u_int *tetris,
					int *diese, int i)
{
	if (piece[i] == '#')
	{
		piece[i] = '.';
		tetris[i / 5] += 1 << (i % 5);
		*diese += 1;
		if (i - 1 >= 0)
			search_the_diese(piece, tetris, diese, i - 1);
		if (i + 1 < 20)
			search_the_diese(piece, tetris, diese, i + 1);
		if (i + 5 < 20)
			search_the_diese(piece, tetris, diese, i + 5);
	}
	else if (piece[i] != '.' && piece[i] != '\n')
		*diese = 5;
}

static int			style_alive(char *str)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if ((i % 5 == 4 && str[i] != '\n')
		|| (i % 5 != 4 && str[i] != '.'))
			return (1);
		i++;
	}
	return (0);
}

int					get_next_piece(char *tab, u_int *tetris)
{
	int		diese;
	int		first;

	diese = 0;
	first = 0;
	if ((first = first_diese(tab)) < 0)
		return (0);
	search_the_diese(tab, tetris, &diese, first);
	if (diese != 4 || style_alive(tab))
		return (0);
	ft_tetris_fall(tetris);
	ft_tetris_reset(tetris);
	return (1);
}
