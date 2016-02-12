/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:03:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/08 17:23:24 by tboos            ###   ########.fr       */
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
				str[i + pos->x + ((len + 1) * j + pos->y)] = elem->id;
			i++;
		}
		j++;
	}
}

void	ft_print_result(t_tetriminos **arrow, int size)
{
	t_coordone			*pos;
	int					len;
	int					i;
	char				*result;

	pos = create_coordone();
	len = glb_sqr_dim(GET, 0) - 1;
	result = ft_init_str_result(len);
	i = 0;
	while (i < size)
	{
		copy_coordone(pos, begin->pos);
		ft_resting_posx(arrow[i], 0);
		ft_resting_posy(arrow[i], 0);
		ft_add_strtetri(arrow[i], pos, result, len);
		i++;
	}
	ft_putstr(result);
	free(result);
	free(pos);
}
