/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:59:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/12 05:56:21 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "coordone.h"
# include "tetriminos.h"
# include <stdio.h>
# include "glb.h"
void	print_tetris(t_tetriminos *piece);
void	print_coordone(int x, int y, char *name);
void	describe_tetris(t_tetriminos *tetris);
void	print_all_tetris(t_tetriminos *tetris);

#endif
