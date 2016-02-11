/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/11 11:50:15 by fjanoty          ###   ########.fr       */
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

t_tetriminos			*ft_tetriorder(t_tetriminos *arrow, int len, int stage)
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


void				ft_squ_lunch(t_tetriminos *tetri_tab, int len)
{
	int				i;
	int				j;
	int				sq;

	i = len * 4;
	j = 1;
	sq = 0;
	while (i > 0)
	{
		i -= j;
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


int		ft_generate_order(t_tetriminos *tetri_tab, int stage, int len)
{
	int				i;
	int				size;
	t_tetriminos	*swap;

	i = 0;
	size = len - stage - 1;
	while (i < size)
	{
		//	on test
		if (ft_push_tetriminos(tetri_tab, stage) && )
			
		//	on swap [stage] et [i + 1]
		i++;
	}
	//	on test le dernier ordre swape
	//
}

/*
			
	sur l'etage n:
	-on tente dans sur la niem place tout les cas restant l'ordre cronologique du niem
	
 * */

/*
1234
1243
1324
1342
1423
1432

2134
2143
2314
2341
2413
2431

3124
3142
3214
3241
3412
3421

4123
4132
4213
4231
4312
4321

ETAGE 1:
1234
2134
3124
4123

ETAGE 2: 1234
1234
1324
1423

ETAGE 2: 2134
2134
2314
2413

ETAGE 2: 3124
3124
3214
3412

ETAGE 2: 4123
4123
4213
4312

ETAGE 3: 1234
1234
1243

ETAGE 3: 1324
1324
1342

ETAGE 3: 1423
1423
1432

ETAGE 3: 2134
2134
2143

ETAGE 3: 2314
2314
2341

ETAGE 3: 2413
2413
2431

ETAGE 3: 3124
3124
3142

ETAGE 3: 3214
3214
3241

ETAGE 3: 3412
3412
3421

ETAGE 3: 4123
4123
4132

ETAGE 3: 4213
4213
4231

ETAGE 3: 4312
4312
4321
*/
