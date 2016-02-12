/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:51:42 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/12 06:22:33 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "tetriminos.h"
# include "filling.h"
# include "debug.h"

void			fillit_structure(char *tab, int ret);
int				get_next_piece(char *tab, t_tetriminos *tetris, int id);
t_tetriminos	*get_the_pieces(char *tab, int nb, int ret, t_tetriminos *array);
#endif
