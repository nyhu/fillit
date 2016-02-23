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

void			ft_free_tetris_tab(u_int **tetris_tab)
{
	int		i;

	i = 0;
	while (tetris_tab[i])
	{
		free(tetris_tab[i]);
		i++;
	}
	free(tetris_tab);
}

void			ft_fill_result(u_int **tetris_tab, char *result, int edge)
{
	int		i;
	int		j;
	int		k;
	int		mask;
	int		y;

	i = -1;
	while (tetris_tab[++i])
	{
		mask = 1;
		j = -1;
		while (++j < edge)
		{
			k = -1;
			while (++k < 4)
			{
				y = (tetris_tab[i][4] + k) * (edge + 1);
				if (tetris_tab[i][k] & mask)
					result[y + j] = 'A' + i;
			}
			mask = mask << 1;
		}
	}
}

char			*ft_init_result(int edge)
{
	static char	result[290];
	int		i;

	i = 0;
	while (i < ((edge + 1) * edge))
	{
		if (i % (edge + 1) == edge)
			result[i] = '\n';
		else
			result[i] = '.';
		i++;
	}
	result[i] = '\0';
	return (result);
}
