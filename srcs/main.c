/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/17 19:52:02 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_recurbit(u_int ligne)
{
	int i;
	i = 0;
	while (i < 8)
	{
		ft_putchar('0' + (ligne % 2));
		ligne /= 2;
		i++;
	}
}

void			ft_printbit(u_int *tetris_tab)
{
	int	i;
	i = 0;
	while (i < 4)
	{
ft_putstr("octet\n");
		ft_recurbit(tetris_tab[i]);
	ft_putstr("\n");
		i++;
	}
}

static void		ft_solve(u_int **tetris_tab, int nb)
{
int		i;
i = 0;
while(i < nb)
{
	ft_putstr("tetris\n");
	ft_printbit(tetris_tab[i]);
	ft_putstr("\n");
	i++;
}
ft_exit(0);
}

static void		ft_filling(char *tab, int ret)
{
	u_int			**tetris_tab;
	int				nb;
	int				i;

	nb = (ret + 1) / 21;
	i = 0;
	if (!(tetris_tab = ft_init_tetris_tab(nb)))
		ft_exit(1);
	if ((ft_check_interbackn(tab, ret)))
	{
		while (i < nb)
		{
			if (!(get_next_piece(tab + (i * 21), *(tetris_tab + i))))
				nb = 0;
			i++;
		}
		if (nb)
			ft_solve(tetris_tab, nb);
	}
	ft_free_tetris_tab(tetris_tab, (ret + 1) / 21);
	ft_exit(1);
}

static void		ft_read(fd)
{
	int		ret;
	char	buf[BUF];

	if ((ret = read(fd, buf, BUF)))
		if ((ret + 1) % 21 == 0)
		{
			buf[ret] = '\0';
			close(fd);
			ft_filling(buf, ret);
		}
	close(fd);
	ft_exit(1);
}

int				main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
		if ((fd = open(av[1], O_RDONLY, S_IREAD)) > 0)
			ft_read(fd);
	if (ac == 1)
	{
		ft_putstr_fd("usage: fillit missing_input_file\n", 1);
		ft_exit(0);
	}
	ft_exit(1);
	return (0);
}
