/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tetriminos	*get_next_piece(int fd, int id)
{
	t_tetriminos	*tetri;
	int				oct_lu;
	char			str[20];

	if (!(tetri = create_tetriminos(id)) && error(SET))
		return (NULL);
	if ((oct_lu = read(fd, str, 20)) != 20 && error(SET) && my_free(tetri) + 1)
		return(NULL);
	oct_lu = 0;
	search_the_diese(str, tetri, &oct_lu, first_case(str));
	if ((tetri->id == 0 || oct_lu != 4 || style_alive(str)) && error(SET)
	&& my_free(tetri) + 1)
		return (NULL);
	finished_tetriminos(tetri);
	return (tetri);
}
