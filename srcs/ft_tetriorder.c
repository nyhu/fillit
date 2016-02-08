/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/05 10:54:40 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

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

t_tetriminos			**ft_tetriorder(t_tetriminos **turtle, int len, int stage)
{
	short			i;
	short			rabbit;
	int				readymade;
	t_tetriminos	**test;

	if (stage == len && ft_push_tetriminos(arrow[stage]))
		return (arrow);
	else if (stage == len)
		return (ft_reorder(arrow, stage));
	i = 0;
	readymade = 0;
	while (++i <= len - stage || rabbit)
	{
		if (ft_push_tetriminos(turtle))
			if ((test = ft_tetriorder(turtle->next, len, stage + 1)))
				return (test);
		else
			return (ft_reorder(arrow, stage));
		rabbit = ft_followrightrabbit(arrow, stage, len, &readymade);
		ft_tetriswap(arrow, stage, rabbit);
		if (rabbit)
			turtle = rabbit;
	}
	return (ft_reorder(arrow, stage));
}

t_tetriminos			**ft_squ_lunch(t_tetriminos **arrow, int len)
{
	int				i;
	int				j;
	int				sq;

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
		if((arrow = ft_tetriorder(arrow, len, 0)))
			return (arrow);
		sq++;
	}
	return (NULL);
}
