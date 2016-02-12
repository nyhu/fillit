/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/13 00:33:13 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "structure.h"
#include "glb.h"

static int		my_free(void *addr)
{
	free(addr);
	return (1);
}

int				get_next_piece(char *tab, t_tetriminos *tetris, int id)
{
	int		dieses;

	create_tetriminos(tetris, id);
	dieses = 0;
	if ((tetris->gap = first_case(tab)) < 0)
		return (0);
	search_the_diese(tab, tetris, &dieses, tetris->gap);
	if (tetris->id == 0 || dieses != 4 || style_alive(tab))
		return (0);
	finished_tetriminos(tetris);
	return (1);
}

t_tetriminos	*get_the_pieces(char *tab, int nb, int ret, t_tetriminos *array)
{
	int				i;

	i = 20;
	while (i < ret && tab[i] == '\n')
		i += 21;
	if (i < ret || !(array = (t_tetriminos *)malloc(sizeof(t_tetriminos) * nb)))
		ft_exit(1);
	i = 0;
	nb = 0;
	while (i < ret)
	{
		if (!(get_next_piece(tab + i, &(array[nb]), nb)))
		{
			free(array);
			ft_exit(1);
		}
		tetris_define_type(array, nb);
		i += 21;
		nb++;
	}
	return (array);
}

void			fillit_structure(char *tab, int ret)
{
	t_tetriminos	*array;
	t_tetriminos	**arrow;
	int				nb;

	array = NULL;
	nb = (ret + 1) / 21;
	array = get_the_pieces(tab, nb, ret, array);
	if (!(arrow = (t_tetriminos **)malloc(sizeof(t_tetriminos *) * nb)) 
		&& my_free(array))
		ft_exit(1);
	while (--nb > -1)
		arrow[nb] = array + (nb * sizeof(t_tetriminos));
	glb_ground(SET, ft_create_square());
	arrow = ft_squ_lunch(arrow, nb - 1);
	ft_print_result(*arrow, nb);
	free(array);
	free(arrow);
	ft_exit(0);
}
