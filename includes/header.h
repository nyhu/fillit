/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:56:08 by tboos             #+#    #+#             */
/*   Updated: 2016/02/17 21:45:58 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# define BUF 546
# define MAX 0xffffffff

typedef unsigned int u_int;
u_int			*ft_map_init(void);
int				ft_solve_map(u_int **tetris_tab, u_int *map, int edge, int stage);
void			ft_fill_result(u_int **tetris_tab, char *result, int edge);
char			*ft_init_result(int edge);
void			ft_map_mask(u_int *map, int edge, int mode);
int				ft_tetris_slide(u_int *tetris, int edge, int *x, int *y);
void			ft_tetris_reset(u_int *tetris);
void			ft_tetris_fall(u_int *tetris);
void			ft_exit(int mode);
void			ft_free_tetris_tab(u_int **tetris_tab, int nb);
int				get_next_piece(char *tab, u_int *tetris);
int				ft_check_interbackn(char *tab, int ret);
u_int			**ft_init_tetris_tab(int nb);
int				ft_find_edge(int nb);
void			ft_set_tetris(u_int *tetris, u_int *map, int y);
#endif
