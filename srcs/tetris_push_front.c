/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tetriminos	*tetris_push_front(t_tetriminos *begin, t_tetriminos elem)
{
	t_tetriminos	*t_elem;

	if (begin)
	{
		t_elem = begin;
		while (t_elem->next)
			t_elem = t_elem->next;
		t_elem->next = elem;
		elem->prev = t_elem;
	}
	else
		return (elem);
}
