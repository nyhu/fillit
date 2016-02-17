/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 18:04:14 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define BUF 546
# include <stdlib.h>
# include <stdio.h>

typedef unsigned int u_int;
void			ft_exit(int mode);
void			ft_free_tetris_tab(u_int **tetris_tab, int nb);
int				get_next_piece(char *tab, u_int *tetris);
int				ft_check_interbackn(char *tab, int ret);
u_int			**ft_init_tetris_tab(int nb);
#endif
