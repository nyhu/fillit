/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:15:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 07:21:10 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include <stdlib.h>
# include "error.h"

typedef	struct s_tetriminos	t_tetriminos;
struct				s_tetriminos
{
	unsigned long	valu;
	char			id;
	int				type;
	int				gap;
	int				xd;
	int				yd;
	int				xp;
	int				yp;
};

void				create_tetriminos(t_tetriminos *tetris, int id);
void				tetris_define_type(t_tetriminos *elem);
void				finished_tetriminos(t_tetriminos *tetris);

#endif
