/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:56:08 by tboos             #+#    #+#             */
/*   Updated: 2016/02/24 22:59:16 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# define BUF 546
# define MAX 0xffffffff
# define CMP_L1 (tetris_tab[stage][0] & map[y])
# define CMP_L2 (tetris_tab[stage][1] & map[y + 1])
# define CMP_L3 (tetris_tab[stage][2] & map[y + 2])
# define CMP_L4 (tetris_tab[stage][3] & map[y + 3])
# define TT tetris_tab

typedef unsigned int	t_int;
t_int			*ft_map_init(void);
int				ft_solve_map(t_int **TT, t_int *map, int edge, int stage);
void			ft_fill_result(t_int **tetris_tab, char *result, int edge);
char			*ft_init_result(int edge);
void			ft_map_mask(t_int *map, int edge, int mode);
int				ft_tetris_slide(t_int *tetris, int edge, int *x, int *y);
void			ft_tetris_reset(t_int *tetris);
void			ft_tetris_fall(t_int *tetris);
void			ft_exit(int mode);
void			ft_free_tetris_tab(t_int **tetris_tab);
int				get_next_piece(char *tab, t_int *tetris);
int				ft_check_interbackn(char *tab, int ret);
t_int			**ft_init_tetris_tab(int nb);
int				ft_find_edge(int nb);
void			ft_set_tetris(t_int *tetris, t_int *map, int y);
int				ft_check_type(t_int **tetris_tab, int stage, int *x);
void			ft_tetris_def_type(t_int **tetris_tab);
#endif
