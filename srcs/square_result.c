/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/11 10:12:35 by fjanoty          ###   ########.fr       */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

# include "square_result.h"

t_square	*ft_init_ground(t_square *ground)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ground->[i / 2][i % 2] = 0;
		i++;
	}
	ground->dim = 0;
	return (ground);
}






//ft_tetrilen(t_tetriminos);


/*	IMPRIMER LES PIECE:
 *		-on sauvgard la position
 *		-on decale la piece en haut a gauche
 *		-on fait une boucle sur un carer de 4*4
 *			-on incremente a la bose position chaque piece;
 *
 * */


/*
   .
00 | 10
<- # ->
01 | 11
   .
*/

/*
 *	mask_v = get_vertical_mask(scr_pos->x * 4);
 *
 *
*/



/*	ENLEVER UNE PIECE
 *
 *	c'est comme si on veux l'ajouter
 *	sauf que on veux ecrire des 0 au lieu d'ecrire des 1
 *
 *
 *
 * */

/*
AJOIUTER UNE PIECE
	-Il faut stoquer le tableau dans un singleton mais garder 
	l'adresse en memoir.
nb ecr:
	1 si dim <= 8
	2 si dim <= 12
	3 si dim <= 16
-on check sur la largeur
	-on peu switcher d'ecran
	-et revenir a la ligne (recalage de la piece)
-qund on a fini la hauteur des ecran on en regenere 3 autre
	-on reclae la piece tut comme il faut
	et on recomence
quand on a tout fini et que c'est nun on renvoir (0)

j < nb_ecr
{
	y < 8 - dim->y
	{
		i < nb_ecr
		{
			x < 8 - dim->x
			{
				x++
			}
			raz->x(ecr) && i++
		}
		y++
	}
	get_window();
	raz->y(ecr) && j++
}

(i,j) -> indice
(x,y) -> pos

CONVERSION (x(ecr) + i) => x(ground)
	- ground->x - (4 * indice->x) = ecr->x
	- ecr->x + (4 * indice->x) = ground->x
CONVERSION (y(ecr) + j) => y(ground)
	- ground->y - (4 * indice->y) = ecr->y
	- ecr->y + (4 * indice->y) = ground->y

+++++++++++++++++++++++++++++++
ou commencer sur un nouvelle ecran

	-on les renouvelle quand on a fini
largeur de travaille = 8 - largeur de la piece
01234567 89ABCDEF
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........
........ ........

12 = 2*6 
12 = 3*4
12 = 4*3
12 = 1*12

26*4




AAAABBBBCCCC
DDDDEEEEFFFF
GGGGHHHHIIII
JJJJKKKKLLLL
MMMMNNNNOOOO
PPPPQQQQRRRR
SSSSTTTTUUUU
VVVVWWWWXXXX
YYYYZZZZ....
............
............
............


01234567 | 456789ABCD


*/
