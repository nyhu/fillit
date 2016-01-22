/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				error(int mode)
{
	static	int	error = 0;

	if (mode & INIT)
		return (error = 0);
	if (mode & SET)
		return (error = 1);
	if (mode & GET)
		return (error);
}
