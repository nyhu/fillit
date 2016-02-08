/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/08 16:38:33 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

static void				ft_followrightrabbit(t_tetriminos **arrow, int *i, int len, int *readymade)
{
	while (i <= len && (*readymade & (arrow[*i])->type))
		(*i)++;
	if (i <= len)
	{
		*readymade += (arrow[*i])->type;
		return (1);
	}
	return (0);
}

t_tetriminos			**ft_tetriorder(t_tetriminos **arrow, int len, int stage)
{
	int				i;
	int				readymade;
	t_tetriminos	**test;

	if (stage == len && ft_push_tetriminos(arrow[stage]))
		return (arrow);
	else if (stage == len)
		return (ft_reorder(arrow, stage));
	i = stage;
	readymade = 0;
	while (++i <= len - stage || rabbit)
	{
		if (ft_push_tetriminos(arrow[stage]))
			if ((test = ft_tetriorder(arrow, len, stage + 1)))
				return (test);
		else
			return (ft_reorder(arrow, stage));
		if ((ft_followrightrabbit(arrow, &i, len, &readymade)))
			ft_tetriswap(arrow, stage, i);
	}
	return (ft_reorder(arrow, stage, len));
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
