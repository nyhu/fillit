/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coordone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_coordone		*create_coordone(void)
{
	t_coordone	*position;

	if (!(position = (t_coordone*) malloc(sizeof(t_coordone))))
		return (NULL);
	position->x = 0;
	position->y = 0;
	return (position);
}
