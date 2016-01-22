/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_pieces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list			*get_the_pieces(int fd)
{
	t_tetriminos	*begin;
	int				i;
	char			c;
	int				oct_lu;

	i = 0;
	error(INIT);
	while (i < 26 && oct_lu && c == '\n')
	{
		begin = tetris_push_front(begin, get_next_piece(fd, i));
		oct_lu = read(fd, &c, 1);
		i++;
	}
	return (begin);
}
