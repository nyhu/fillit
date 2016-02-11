/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/11 03:38:33 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define BUF 546
# include <stdlib.h>
# include <stdio.h>
# include "tetriminos.h"
# include "coordone.h"
# include "square_result.h"

void				ft_exit(int mode);
t_sqare				*glb_ground(int mode, t_sqare *value);
t_sqare				*ft_create_square(void);
void				ft_remouve_tetris(t_tetriminos *t);
int					tetris_free(t_tetriminos *elem);
int					ft_tetrilen(t_tetriminos *begin);
void				print_all_tetris(t_tetriminos *tetris);
void				ft_tetriswap(t_tetriminos *r1, t_tetriminos *r2);
t_tetriminos		*ft_reorder(t_tetriminos *rabbit);
t_tetriminos		*ft_tetriorder(t_tetriminos *turtle, int len, int stage);
t_tetriminos		*ft_squ_lunch(t_tetriminos *begin, int len);
void				ft_print_result(t_tetriminos *begin);
int					glb_sqr_dim(int mode, int value);
int					ft_push_tetriminos(t_tetriminos *elem);
#endif
