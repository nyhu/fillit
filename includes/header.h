/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/13 00:39:57 by tboos            ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "structure.h"
# include "libft.h"
# include "glb.h"

void				ft_exit(int mode);
t_sqare				*glb_ground(int mode, t_sqare *value);
t_sqare				*ft_create_square(void);
void				ft_remouve_tetris(t_tetriminos *t);
int					tetris_free(t_tetriminos *elem);
int					ft_tetrilen(t_tetriminos *begin);
void				print_all_tetris(t_tetriminos *tetris);
void				ft_tetriswap(t_tetriminos **arrow, int stage, int i);
t_tetriminos		**ft_reorder(t_tetriminos **arrow, int stage, int len);
t_tetriminos		**ft_tetriorder(t_tetriminos **arrow, int len, int stage);
t_tetriminos		**ft_squ_lunch(t_tetriminos **arrow, int len);
void				ft_print_result(t_tetriminos *begin, int size);
int					glb_sqr_dim(int mode, int value);
int					ft_push_tetriminos(t_tetriminos *elem);
#endif
