/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:24:51 by tboos             #+#    #+#             */
/*   Updated: 2016/01/19 23:22:02 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strsplitclean(char **split, char *cpy, size_t nmot)
{
	size_t	i;

	i = 0;
	while (i < nmot)
	{
		split[i] = ft_strdup(split[i]);
		i++;
	}
	split[i] = NULL;
	free(cpy);
	return (split);
}

static char	**ft_strsplitcpy(char *cpy, char c, size_t j, size_t i)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (j + 1));
	if (!split)
		return (NULL);
	j = 0;
	while (cpy[i])
	{
		split[j] = &(cpy[i]);
		while (cpy[i] != c && cpy[i])
			i++;
		if (!cpy[i])
			return (ft_strsplitclean(split, cpy, j + 1));
		cpy[i] = '\0';
		i++;
		j++;
		while (cpy[i] == c)
			i++;
	}
	split[j] = NULL;
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*cpy;
	size_t	i;
	size_t	j;

	while (*s == c)
		s++;
	cpy = ft_strdup(s);
	i = ft_strlen(cpy);
	while (i && cpy[i - 1] == c)
		i--;
	cpy[i] = '\0';
	j = 1;
	while (i > 0)
	{
		if (cpy[i] == c)
		{
			j++;
			while (cpy[i] == c)
				i--;
		}
		i--;
	}
	return (ft_strsplitcpy(cpy, c, j, i));
}
