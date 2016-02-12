/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/12 11:35:48 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

static int	ft_followrightrabbit(t_tetriminos **arrow, int *i, int len, int *readymade)
{
	while (*i <= len && (*readymade & (arrow[*i])->type))
		(*i)++;
	if (*i <= len)
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

	dprintf(1, "tetriorderoiu len:%d stage:%d arrow:%ld\n", len, stage, (long)arrow);
	if (stage == len && ft_push_tetriminos(arrow[stage]))
		return (arrow);
	else if (stage == len)
		return (ft_reorder(arrow, stage, len));
	dprintf(1, "tetriorder 2\n");
	i = stage;
	readymade = 0;
	while (++i <= len - stage)
	{
	dprintf(1, "tetriorder bcl2 len:%d stage:%d arrow:%ld\n", len, stage, (long)arrow);
		if (ft_push_tetriminos(arrow[stage]))
		{
	dprintf(1, "tetriorder bcl\n");
			if ((test = ft_tetriorder(arrow, len, stage + 1)))
				return (test);
		}
		else
			return (ft_reorder(arrow, stage, len));
		if ((ft_followrightrabbit(arrow, &i, len, &readymade)))
			ft_tetriswap(arrow, stage, i);
	dprintf(1, "tetriorder bcl3\n");
	}
	dprintf(1, "tetriorder end\n");
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
		if((arrow = ft_tetriorder(arrow, len - 1, 0)))
			return (arrow);
		sq++;
	}
	return (NULL);
}
