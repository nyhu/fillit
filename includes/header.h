/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 19:49:35 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# define BUF 546

typedef unsigned int u_int;
void			ft_tetris_reset(u_int *tetris);
void			ft_tetris_fall(u_int *tetris);
void			ft_exit(int mode);
void			ft_free_tetris_tab(u_int **tetris_tab, int nb);
int				get_next_piece(char *tab, u_int *tetris);
int				ft_check_interbackn(char *tab, int ret);
u_int			**ft_init_tetris_tab(int nb);
#endif
