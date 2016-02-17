/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 14:02:32 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "structure.h"
#include "glb.h"

int				get_next_piece(char *tab, t_tetriminos *tetris, int id)
{
	int		dieses;

	dieses = 0;
	if ((tetris->gap = first_case(tab)) < 0)
		return (0);
	search_the_diese(tab, tetris, &dieses, tetris->gap);
	if (tetris->id == 0 || dieses != 4 || style_alive(tab))
		return (0);
	finished_tetriminos(tetris);
	return (1);
}

void	ft_filling_tetris(char *tab, int ret, int nb, t_tetriminos *tetri_tab)
{
	int				i;

	i = 20;
	while (i < ret && tab[i] == '\n')
		i += 21;
	if (i < ret)
		ft_exit(1);
	i = 0;
	while (i < nb)
	{
		if (!get_next_piece(str + (i * 21), tetri_tab + i, i))
			ft_exit(1);
		tetris_define_type(tetri_tab + i, i);
		finished_tetriminos(tetri_tab + i);
		i++;
	}
}

void			fillit_structure(char *tab, int ret)
{
	t_tetriminos	tetri_tab[26];
	int				nb;
	int				i;
	t_sqare			ground;

	nb = (ret + 1) / 21;
	ft_init_tetri_tab(tetri_tab, nb);
	ft_filling_tetris(tab, ret, nb, tetri_tab);
	glb_ground(SET, ft_init_ground(&ground));
	tetri_tab = ft_squ_lunch(tetri_tab, nb);
	ft_print_result(tetri_tab, nb);
	ft_exit(0);
}
