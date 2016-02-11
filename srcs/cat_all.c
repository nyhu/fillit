/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:11:42 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/11 06:31:20 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_rm_tetri.h"
#include "debug.h"
#include <stdio.h>

/*area[x][y]*/
unsigned	long	ft_working_window(t_sqare *gr, int x, int y)
{
	unsigned	long	mh;
	unsigned	long	mv;
	unsigned	long	ecr;

	mh = get_vertical_mask(x);
	mv = get_horizontal_mask(y);
	ecr = ((gr->area[0][0] & ~mv & ~mh) >> (x + (8 * y)));
	ecr |= (((gr->area[0][1] & mv & ~mh) >> x) << (8 * (8 - y)));
	ecr |= (((gr->area[1][0] & ~mv & mh) << (8 - x)) >> (8 * y));
	ecr |= ((gr->area[1][1] & mv & mh) << ((8 - x) + (8 * (8 - y))));
	return (ecr);
}

void	ft_init_windows(unsigned long *windows, int stage)
{
	int					i;
	t_sqare				*ground;
	int					nb_win;
	int					x;
	int					y;

	ground = glb_ground(GET, 0);
	nb_win = glb_nb_windows(GET, 0);
	i = 0;
	y = stage * 4;
	while (i < nb_win)
	{
		x = (i * 4);
		windows[i] = ft_working_window(ground, x, y);
		i++;
	}
}

int		ft_set_tetris(t_tetriminos *t, int x, int y)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_sqare				*gr;

	gr = glb_ground(GET, 0);
	x *= 4;
	y *= 4;
	mv = get_vertical_mask(8 - x);
	mh = get_horizontal_mask(8 - y);
	gr->area[0][0] ^= (t->valu & mv & mh) << (x + (8 * y));
	gr->area[0][1] ^= ((t->valu & mv & ~mh) << x) >> (8 * (8 - y ));
	gr->area[1][0] ^= ((t->valu & ~mv & mh) >> (8 - x)) << (8 * y);
	gr->area[1][1] ^= (t->valu & ~mv & ~mh) >> (8 - x + (8 * (8 - y)));
	return (1);
}

void	ft_remouve_tetris(t_tetriminos *tetri)
{
	ft_set_tetris(tetri, tetri->ecr->x, tetri->ecr->y);
	ft_resting_posx(tetri);
	ft_resting_posy(tetri);
	tetri->ecr->x = 0;
	tetri->ecr->y = 0;
}

int		ft_last_loop(t_tetriminos *elem, int dim, unsigned long *windows)
{
	while ((X < 8 - DIM_X) && X + (4 * ECR_X) < dim - DIM_X)
	{
		if ((elem->valu & windows[ECR_X]) == 0)
		{
			ft_set_tetris(elem, ECR_X, ECR_Y);
			return (1);
		}
		elem->valu <<= 1;
		(X)++;
//dprintf(1, "CHANGEMANE DE COLONE x:%d y:%d ecrx:%d ecry:%d\n", X, Y, ECR_X, ECR_Y);
	}
//dprintf(1, "=========================X:%d  max:%d\n",  X + (4 * ECR_X), dim - DIM_X);
	(ECR_X)++;
	ft_resting_posx(elem);
	return (0);
}

int	ft_push_tetriminos(t_tetriminos *elem)
{
	unsigned	long	windows[3];
	int					nb_windows;
	int					dim;

	nb_windows = glb_nb_windows(GET, 0);
	dim = glb_sqr_dim(GET, 0);
	ECR_X = 0;
//dprintf(1, "ecr_x:%d	ecr_y:%d\n", ECR_X, ECR_Y);
//dprintf(1, "nb_windows:%d\n", nb_windows);
	while (ECR_Y < nb_windows)
	{
		ft_init_windows(windows, ECR_Y);
		while ((Y < 8 - DIM_Y) && Y + (4 * ECR_Y) < dim - DIM_Y)
		{
//dprintf(1, "		ecr	X:%d\n", ECR_X);
			while(ECR_X < nb_windows)
			{
				if (ft_last_loop(elem, dim, windows))
					return (1);
			}
			ECR_X = 0;
	//		ft_resting_posx(elem);
			elem->valu <<= 8;
			(Y)++;
//dprintf(1, "CHANGEMANE DE LIIIIIGNE x:%d y:%d ecrx:%d ecry:%d\n", X, Y, ECR_X, ECR_Y);
		}
		(ECR_Y)++;
	}
	ft_resting_posy(elem);
	ft_resting_posx(elem);
	ECR_Y = 0;
	ECR_X = 0;
//dprintf(1, "*** FAIL:%c: ***\n", elem->id);
	return (0);
}

/*
 *	Il faut retracer le coportement de ft_push_tetriminos 
 *		savoir sur combien il se deplace par fenetre
 *		qu'est ce qu'il se passe quand il dit non et donc pourquoi
 *		est-ce qu'il y a bien un reset
 *		pourquoi la taille minimal de fenetre est plus que une
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coordone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/10 20:12:59 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordone.h"

t_coordone		*create_coordone(void)
{
	t_coordone	*position;

	if (!(position = (t_coordone*)malloc(sizeof(t_coordone))))
		return (NULL);
	position->x = 0;
	position->y = 0;
	return (position);
}

t_coordone		*create_coordone_y(int y)
{
	t_coordone	*position;

	if (!(position = (t_coordone*)malloc(sizeof(t_coordone))))
		return (NULL);
	position->x = 0;
	position->y = y;
	return (position);
}

void			copy_coordone(t_coordone *pos_dst, t_coordone *pos_src1, t_coordone *pos_src2)
{
	pos_dst->x = pos_src1->x + (pos_src2->x * 4);
	pos_dst->y = pos_src1->y + (pos_src2->y * 4);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:46:52 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/10 20:37:01 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_working_windows(unsigned long *windows)
{
	int	nb_windows;
	int	j;
	t_tetriminos	*tet;

	j = 0;
	tet = create_tetriminos(0);
	nb_windows = glb_nb_windows(GET, 0);
	while (j < nb_windows)
	{
		dprintf(1, "windows:%d", j);
		tet->valu = windows[j];
		print_tetris(tet);
		j++;
	}
	dprintf(1, "\n");
	free(tet);
}

void	print_ground(t_sqare *sqr)
{
	int	i;
	int	j;
	unsigned long unite;

	j = 0;
	unite = 1;
	dprintf(1, "len_sqr:%d\n", sqr->dim);
	while (j < 16)
	{
		i = 0;
		while (i < 16)
		{
			if (i == 8)
				dprintf(1, " | ");
			if (sqr->area[i / 8][j / 8] & (unite << ((i % 8) + (8 * (j % 8)))))
				dprintf(1, "#");
			else
				dprintf(1, ".");
			i++;
		}
		dprintf(1, "\n");
		j++;
		if (j == 8)
			dprintf(1, "--------   --------\n");
	}
}

void	print_tetris(t_tetriminos *piece)
{
	int					i;
	int					j;
	unsigned	long	unite;

	dprintf(1, "\n");
	unite = 1;
	j = 0;
	while (j < 8)
	{
		i = 0;
		while (i < 8)
		{
			if (piece->valu & (unite << (j * 8 + i)))
				dprintf(1, "#");
			else
				dprintf(1, ".");
			i++;
		}
		dprintf(1, "\n");
		j++;
	}
}

void	print_coordone(t_coordone *pos, char *name)
{
	dprintf(1, "%s: x:%d ", name, pos->x);
	dprintf(1, "%s: y:%d\n", name, pos->y);
}

void	describe_tetris(t_tetriminos *tetris)
{
	print_tetris(tetris);
	dprintf(1, "valu :%ld   ", (long)tetris->valu);
	dprintf(1, "id   :%c   ", tetris->id);
	dprintf(1, "type :%d   ", tetris->type);
	dprintf(1, "gap  :%d\n", tetris->gap);
	print_coordone(tetris->dim, " dim");
	print_coordone(tetris->pos, " pos");
	print_coordone(tetris->ecr, " ecr");
}

void	print_all_tetris(t_tetriminos *tetris)
{
	if (tetris)
	{
		describe_tetris(tetris);
		print_all_tetris(tetris->next);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 03:51:54 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int				error(int mode)
{
	static	int	error = 0;

	if (mode & INIT)
		return (error = 0);
	if (mode & SET)
		return (error = 1);
	if (mode & GET)
		return (error);
	return (error);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 07:38:47 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/04 20:21:28 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filling.h"

void			actual_mini_maxi(t_tetriminos *tetris, int i)
{
	int	x;
	int	y;

	x = i % 5;
	y = i / 5;
	if (x < tetris->pos->x)
		tetris->pos->x = x;
	if (y < tetris->pos->y)
		tetris->pos->y = y;
	if (x > tetris->dim->x)
		tetris->dim->x = x;
	if (y > tetris->dim->y)
		tetris->dim->y = y;
}

int				first_case(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && str[i] != '\n')
			return (-1);
		if (i % 5 != 4 && str[i] == '#')
			return (i);
		else if (i % 5 != 4 && str[i] != '.')
			return (-1);
		i++;
	}
	return (i);
}

void			search_the_diese(char *piece, t_tetriminos *tetris
				, int *nb, int i)
{
	unsigned	long	unite;

	unite = 1;
	if (piece[i] == '#')
	{
		piece[i] = '.';
		tetris->valu += unite << (i % 5 + ((i / 5) * 8));
		*nb += 1;
		actual_mini_maxi(tetris, i);
		if (i - 5 >= 0)
			search_the_diese(piece, tetris, nb, i - 5);
		if ((i - 1) % 5 != 4 && (i - 1) >= 0)
			search_the_diese(piece, tetris, nb, i - 1);
		if ((i + 1) % 5 != 0 && (i + 1) % 5 != 4 && (i + 1) < 20)
			search_the_diese(piece, tetris, nb, i + 1);
		if (i + 5 < 20)
			search_the_diese(piece, tetris, nb, i + 5);
	}
	else if (piece[i] != '.')
		tetris->id = 0;
}

int				style_alive(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#'
		|| (i % 5 == 4 && str[i] != '\n')
		|| (i % 5 != 4 && str[i] != '.'))
			return (1);
		i++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/06 20:09:23 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "structure.h"

static int		my_free(void *addr)
{
	free(addr);
	return (1);
}

t_tetriminos	*get_next_piece(int fd, int id)
{
	t_tetriminos	*tetris;
	int				oct_lu;
	char			str[21];

	if (!(tetris = create_tetriminos(id)) && error(SET))
		return (NULL);
	if ((oct_lu = read(fd, str, 20)) != 20 && error(SET) && my_free(tetris) + 1)
		return (NULL);
	oct_lu = 0;
	search_the_diese(str, tetris, &oct_lu, (tetris->gap = first_case(str)));
	if ((tetris->id == 0 || oct_lu != 4 || style_alive(str))
	&& error(SET) && my_free(tetris))
		return (NULL);
	finished_tetriminos(tetris);
	return (tetris);
}

t_tetriminos	*get_the_pieces(int fd)
{
	t_tetriminos	*begin;
	int				i;
	char			c;
	int				oct_lu;

	i = 0;
	oct_lu = 1;
	c = '\n';
	begin = NULL;
	while (i < 26 && oct_lu && c == '\n')
	{
		begin = tetris_push_front(begin, get_next_piece(fd, i));
		oct_lu = read(fd, &c, 1);
		if (oct_lu && c != '\n')
			error(SET);
		i++;
	}
	if (error(GET) && tetris_free(begin))
		return (NULL);
	return (begin);
}

int				fillit_structure(int fd)
{
	t_tetriminos	*first_tetris;

	error(INIT);
	first_tetris = get_the_pieces(fd);
	if (!first_tetris)
		return (-1);
//print_all_tetris(first_tetris);
	glb_ground(SET, ft_create_square());
	first_tetris = ft_squ_lunch(first_tetris, ft_tetrilen(first_tetris));
	ft_print_result(first_tetris);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reorder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <toussaint.boos@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:15:02 by tboos             #+#    #+#             */
/*   Updated: 2016/02/05 06:14:20 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tetriminos	*ft_reorder(t_tetriminos *rabbit)
{
	t_tetriminos	*stick;
	t_tetriminos	*turtle;

	if (rabbit->prev)
		ft_remouve_tetris(rabbit->prev);
	stick = rabbit;
	while (stick && stick->next)
	{
		rabbit = stick->next;
		turtle = stick;
		while (rabbit)
		{
			if (rabbit->id < turtle->id)
				turtle = rabbit;
			rabbit = rabbit->next;
		}
		if (turtle != stick)
		{
			ft_tetriswap(turtle, stick);
			stick = turtle->next;
		}
		else
			stick = stick->next;
	}
	return (NULL);
}

void		ft_tetriswap(t_tetriminos *r1, t_tetriminos *r2)
{
	t_tetriminos	*s;

	if (r1 && r2)
	{
		if (r1->prev)
			r1->prev->next = r2;
		if (r2->prev)
			r2->prev->next = r1;
		s = r1->prev;
		r1->prev = r2->prev;
		r2->prev = s;
		if (r2->next)
			r2->next->prev = r1;
		if (r1->next)
			r1->next->prev = r2;
		s = r1->next;
		r1->next = r2->next;
		r2->next = s;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrilen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr> 	                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 21:44:00 by tboos             #+#    #+#             */
/*   Updated: 2016/02/05 21:24:26 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

int				ft_tetrilen(t_tetriminos *begin)
{
	short				i;

	i = 0;
	while (begin)
	{
		begin = begin->next;
		i++;
	}
	return (i - 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/11 01:20:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

static t_tetriminos			*ft_findbegin(t_tetriminos *begin)
{
	while (begin->prev)
		begin = begin->prev;
	return (begin);
}

static t_tetriminos 	*ft_followrightrabbit(t_tetriminos *rabbit, short *i, int *readymade)
{
	short			tmp;

	tmp = *i;
	while (tmp && rabbit)
	{
		rabbit = rabbit->next;
		tmp--;
	}
	while (rabbit && (*readymade & rabbit->type))
	{
		rabbit = rabbit->next;
		(*i)++;
	}
	if (rabbit)
		*readymade += rabbit->type;
	return (rabbit);
}

static	t_tetriminos	*ft_incrx_tetris(t_tetriminos *tetris)
{
	ft_remouve_tetris(tetris);
	tetris->valu <<= 1;
	(tetris->pos->x)++;
	return (tetris);
}

t_tetriminos			*ft_tetriorder(t_tetriminos *turtle, int len, int stage)
{
	short			i;
	int				readymade;
	t_tetriminos	*rabbit;
	t_tetriminos	*test;
	int				ok;

	ok = 1;
	if (stage == len && ft_push_tetriminos(turtle))
		return (ft_findbegin(turtle));
	else if (stage == len)
		return (ft_reorder(turtle));
	i = 0;
	readymade = 0;
	while (++i <= len - stage || rabbit)
	{
		if (ft_push_tetriminos(turtle))
		{
			if ((test = ft_tetriorder(turtle->next, len, stage + 1)))
				return (test);
		}
		else
			return (ft_reorder(turtle));
		rabbit = ft_followrightrabbit(turtle, &i, &readymade);
		ft_tetriswap(turtle, rabbit);
		if (rabbit)
			turtle = rabbit;
	}
	return (ft_reorder(turtle));
}

/*
		else if (!stage && ft_push_tetriminos(ft_increm_x_tetris(turtle)))
		{
			if ((test = ft_tetriorder(turtle->next, len, stage + 1)))
				return (test);
		}
*/
t_tetriminos			*ft_squ_lunch(t_tetriminos *begin, int len)
{
	int				i;
	int				j;
	int				sq;
	t_tetriminos	*result;

	i = (len + 1) * 4;
	j = 1;
	sq = 0;
	while (i > 0)
	{
		i = i - j;
		j += 2;
		sq++;
	}
	while (sq < 16)
	{
		glb_sqr_dim(SET, sq);
		if((result = ft_tetriorder(begin, len, 0)))
			return (result);
		sq++;
	}
	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:51:14 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/06 20:00:42 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glb.h"
#include <stdio.h>

int		glb_nb_windows(int mode, int sqr_dim)
{
	static	int	nb_windows = 1;

	if (mode & GET)
		return (nb_windows);
	else if (mode & SET)
	{
		nb_windows = (sqr_dim <= 12) ? 2 : 3;
		nb_windows = (sqr_dim <= 8) ? 1 : nb_windows;
		return (nb_windows);
	}
	else
		return (1);
}

int		glb_sqr_dim(int mode, int value)
{
	static	int	sqr_dim = 1;
	t_sqare		*ground;

	if (mode & GET)
		return (sqr_dim);
	else if (mode & SET)
	{
//dprintf(1, "ON SETTTTTT :::%d\n", value);
		ground = glb_ground(GET, 0);
		ground->dim = value;
		glb_nb_windows(SET, value);
		sqr_dim = value;
		return (sqr_dim);
	}
	else
		return (1);
}

t_sqare	*glb_ground(int mode, t_sqare *value)
{
	static	t_sqare	*ground;

	if (mode & GET)
		return (ground);
	else if (mode & SET)
	{
		ground = value;
		glb_sqr_dim(SET, ground->dim);
		return (ground);
	}
	else
		return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/04 19:16:03 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int ac, char **av)
{
	int		err;
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY, S_IREAD)) != 1)
		{
			err = fillit_structure(fd);
			if (err == -1)
				ft_putstr_fd("error\n", 2);
			else if (err == -2)
				ft_putstr_fd("error\n", 2);
		}
		else
			ft_putstr_fd("error\n", 2);
	}
	else if (ac == 1)
		ft_putstr_fd("error\n", 2);
	else
		ft_putstr_fd("error\n", 2);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 20:05:26 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/07 23:26:51 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manip_bin.h"

unsigned	long	get_vertical_mask(int size)
{
	static	unsigned	long	masks[9];
	static	int					init = 1;
	unsigned	long			vertical;
	int							i;
	int							j;

	if (init)
	{
		init = 0;
		vertical = VERTICAL;
		j = 0;
		while (j < 9)
		{
			i = 0;
			masks[j] = 0;
			while (i < j)
			{
				masks[j] |= vertical << i;
				i++;
			}
			j++;
		} 
	}
	return (masks[size]);
}

unsigned	long	get_horizontal_mask(int size)
{
	static	unsigned	long	masks[9];
	static	int					init = 1;
	unsigned	long			horizontal;
	int							i;
	int							j;

	if (init)
	{
		init = 0;
		horizontal = HORIZONTAL;
		j = 0;
		while (j < 9)
		{
			i = 0;
			masks[j] = 0;
			while (i < j)
			{
				masks[j] |= horizontal << (i * 8);
				i++;
			}
			j++;
		} 
	}
	return (masks[size]);
}

int		ft_resting_posx(t_tetriminos *elem)
{
	elem->valu >>= (elem->pos->x);
	elem->pos->x = 0;
	return (0);
}

int		ft_resting_posy(t_tetriminos *elem)
{
	elem->valu >>= ((elem->pos->y) * 8);
	elem->pos->y = 0;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:03:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/10 22:09:30 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <stdio.h>
#include "header.h"
#include "debug.h"

char	*ft_init_str_result(int len)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * (len * (len + 1) + 1))))
		return (NULL);
	while (i < len * (len + 1))
	{
		if (i % (len + 1) == len)
			result[i] = '\n';
		else
			result[i] = '.';
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_add_strtetri(t_tetriminos *elem, t_coordone *pos, char *str, int len)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (elem->valu & (1 << (i + (8 * j))))
				str[i + pos->x + ((len + 1) * (j + pos->y))] = elem->id;
			i++;
		}
		j++;
	}
}

void	ft_print_result(t_tetriminos *begin)
{
	t_coordone			*pos;
	int					len;
	char	*result;

//print_all_tetris(begin);
//print_ground(glb_ground(GET, 0));
	pos = create_coordone();
	len = glb_sqr_dim(GET, 0) - 1;
	result = ft_init_str_result(len);
	while (begin)
	{
		copy_coordone(pos, begin->pos, begin->ecr);
		ft_resting_posx(begin);
		ft_resting_posy(begin);
		ft_add_strtetri(begin, pos, result, len);
		begin = begin->next;
	}
	ft_putstr(result);
//printf("###############################################:	%s\n", result);
	free(result);
	free(pos);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 06:18:56 by fjanoty          ###   ########.fr       */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

# include "square_result.h"

t_sqare	*ft_create_square(void)
{
	t_sqare	*ground;
	int		i;
	int		j;

	ground = (t_sqare*)malloc(sizeof(t_sqare));
	if (!ground)
		return (NULL);
	ground->area = (unsigned long **)malloc(sizeof(unsigned long *) * 2);
	if (!ground->area)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		j = -1;
		ground->area[i] = (unsigned long *)malloc(sizeof(unsigned long) * 2);
		if (!ground->area[i])
			return (NULL);
		while (++j < 2)
			ground->area[i][j] = 0;
		i++;
	}
	ground->dim = 0;
	return (ground);
}






//ft_tetrilen(t_tetriminos);


/*	IMPRIMER LES PIECE:
 *		-on sauvgard la position
 *		-on decale la piece en haut a gauche
 *		-on fait une boucle sur un carer de 4*4
 *			-on incremente a la bose position chaque piece;
 *
 * */


/*
   .
00 | 10
<- # ->
01 | 11
   .
*/

/*
 *	mask_v = get_vertical_mask(scr_pos->x * 4);
 *
 *
*/



/*	ENLEVER UNE PIECE
 *
 *	c'est comme si on veux l'ajouter
 *	sauf que on veux ecrire des 0 au lieu d'ecrire des 1
 *
 *
 *
 * */

/*
AJOIUTER UNE PIECE
	-Il faut stoquer le tableau dans un singleton mais garder 
	l'adresse en memoir.
nb ecr:
	1 si dim <= 8
	2 si dim <= 12
	3 si dim <= 16
-on check sur la largeur
	-on peu switcher d'ecran
	-et revenir a la ligne (recalage de la piece)
-qund on a fini la hauteur des ecran on en regenere 3 autre
	-on reclae la piece tut comme il faut
	et on recomence
quand on a tout fini et que c'est nun on renvoir (0)

j < nb_ecr
{
	y < 8 - dim->y
	{
		i < nb_ecr
		{
			x < 8 - dim->x
			{
				x++
			}
			raz->x(ecr) && i++
		}
		y++
	}
	get_window();
	raz->y(ecr) && j++
}

(i,j) -> indice
(x,y) -> pos

CONVERSION (x(ecr) + i) => x(ground)
	- ground->x - (4 * indice->x) = ecr->x
	- ecr->x + (4 * indice->x) = ground->x
CONVERSION (y(ecr) + j) => y(ground)
	- ground->y - (4 * indice->y) = ecr->y
	- ecr->y + (4 * indice->y) = ground->y

+++++++++++++++++++++++++++++++
ou commencer sur un nouvelle ecran

	-on les renouvelle quand on a fini
largeur de travaille = 8 - largeur de la piece
01234567 89ABCDEF
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........

12 = 2*6 
12 = 3*4
12 = 4*3
12 = 1*12

26*4




AAAABBBBCCCC
DDDDEEEEFFFF
GGGGHHHHIIII
JJJJKKKKLLLL
MMMMNNNNOOOO
PPPPQQQQRRRR
SSSSTTTTUUUU
VVVVWWWWXXXX
YYYYZZZZ....
............
............
............


01234567 | 456789ABCD


*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/07 23:16:24 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

t_tetriminos	*create_tetriminos(int id)
{
	t_tetriminos	*piece;
	if (!(piece = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
		return (NULL);
	if (!(piece->dim = create_coordone()) || !(piece->pos = create_coordone())
		|| !(piece->ecr = create_coordone()))
		return (NULL);
	piece->id = id + 'A';
	piece->valu = 0;
	piece->pos->x = 8;
	piece->pos->y = 8;
	piece->next = NULL;
	piece->prev = NULL;
	return (piece);
}

void				tetris_define_type(t_tetriminos *elem)
{
	int				type_max;
	t_tetriminos	*tetris;
	int				first;
	type_max = 1;
	tetris = elem->prev;
	first = 1;
	while (tetris && tetris->valu != elem->valu)
	{
		first = 0;
		if (tetris->type > type_max)
			type_max = tetris->type;
		tetris = tetris->prev;
	}
	if (tetris)
		elem->type = tetris->type;
	else if (first)
		elem->type = type_max;
	else
		elem->type = type_max << 1;
}

int	tetris_free(t_tetriminos *elem)
{
	t_tetriminos	*save;

	if (elem)
	{
		while (elem)
		{
			save = (elem)->next;
			free(elem->ecr);
			free(elem->pos);
			free(elem->dim);
			free(elem);
			elem = save;
		}
	}
	return (1);
}

void			finished_tetriminos(t_tetriminos *tetris)
{
	tetris->gap = (tetris->gap % 5) - tetris->pos->x; 
	tetris->dim->x = tetris->dim->x - tetris->pos->x + 1;
	tetris->dim->y = tetris->dim->y - tetris->pos->y + 1;
	tetris->valu = tetris->valu >> (tetris->pos->x + (tetris->pos->y * 8));
	tetris->pos->x = 0;
	tetris->pos->y = 0;
}

t_tetriminos	*tetris_push_front(t_tetriminos *begin, t_tetriminos *elem)
{
	t_tetriminos	*tmp;

	if (begin && elem)
	{
		tmp = begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
		tetris_define_type(elem);
		return (begin);
	}
	else if (elem)
	{
		tetris_define_type(elem);
		return (elem);
	}
	else
		return (NULL);
}


