/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 20:43:31 by tboos             #+#    #+#             */
/*   Updated: 2016/02/17 20:43:39 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_find_edge(int nb)
{
	int				i;
	int				edge;

	i = nb * 4;
	edge = 1;
	while (i > 0)
	{
		i = i - j;
		edge += 2;
	}
	edge = (edge - 1) / 2;
	return (edge);
}

u_int	*ft_map_init(void)
{
	u_int			map;

	if (!(map = (u_int *)malloc(sizeof(int) * 16)))
		return (NULL);

}
