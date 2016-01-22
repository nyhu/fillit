/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:55:52 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	int		err;

	if (ac == 2)
	{
		err = ft_print_file(av[1]);
		if (err == -1)
			ft_putstr_fd("error\n", 2);
		else if (err == -2)
			ft_putstr_fd("error\n", 2);
	}
	else
		ft_putstr("usage: fillit source_file\n");
	return (0);
}
