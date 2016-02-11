/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 03:49:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/11 04:11:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_tata
{
	int i;
	int j;
}				t_tata;

void	init_tab(t_tata *tab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		tab[i].i = i;
		tab[i].j = i * 10;
		i++;
	}
}

int	main(void)
{
	int		i;
	t_tata	tab[11];

	init_tab(tab);
	i = 0;
	while (i < 11)
	{
		printf("haha %d %d\n", tab[i].i, tab[i].j);
		i++;
	}
	return (0);
}
