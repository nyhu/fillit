/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 03:49:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/12 02:33:32 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_tata
{
	int i;
	int j;
}				t_tata;

void	init_tab(t_tata tab[10][1])
{
	int		i;
//	t_tata	*swap;

	i = 0;
	while (i < 10)
	{
//		swap = tab[i];
//		tab[i] = swap;
		tab[i][0].i = i;
		tab[i][0].j = i * 10;
		i++;
	}
}

int		main(void)
{
	int		i;
	void	*tab[10];
	t_tata	oui;

	tab[0] = &oui;
	(void) tab;
//	init_tab(tab);
	i = 0;
	while (i < 11)
	{
//		printf("haha %d %d\n", tab[i][0].i, tab[i][0].j);
		i++;
	}
	return (0);
}
