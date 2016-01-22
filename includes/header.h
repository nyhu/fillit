/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:19:43 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADEr_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define ERROR
# define INIT 1
# define SET 2
# define GET 4

typedef	struct		s_list;
{
	struct	s_list	*next;
	void			*data;
}					t_list
typedef	struct		s_coordone
{
	int				x;
	int				y;
}					t_coordone;
typedef	struct		s_tetriminos;
{
	unsigned long	valu;
	char			id;
	int				type;
	t_coordone		*dim;
	t_coordone		*pos;
}					t_tetrimonos;
typedef				s_plateau
{
	t_list			*pieces;
	int				taille;

}					t_plateau;
int					ft_atoi(const char *str);
void				ft_bzero(void(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
size_t				ft_strlen(const char *s);
int					ft_memdel_i(void *ap);
t_coordone			*create_coordone(void);
t_tetriminos		*create_tetriminos(int id);
t_tetriminos		*tetris_push_front(t_tetriminos *begin, t_tetriminos elem);
int					first_case(char *str);
void				actual_mini_maxi(t_tetriminos *tetri, int i);
int					error(int mode);
void				search_the_diese(char *piece, t_tetriminos *tetri, int *nb, int i);
int					style_alive(str);
void				tetris_define_type(t_teriminos *t_elem);
void				finished_tetriminos(t_tetriminos tetri);
t_tetriminos		*get_next_piece(int fd, int id);
t_list				*get_the_pieces(int fd);
void				generate_order(t_tetriminos tetri, int size, int indice)

#endif


//	1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256

//	RECUPERER LES PIECE:
//		-on fait un read de 20
//			-si il echou => erreur
//		-on cherche le premier '#'
//		-on lance l'ago de recherche_connex/supression
//			-on enregistre les case dans un double
//			-on stoque x_min/x_max y_min\y_max
//			-si : nb_case != 4 || len(ligne) != 4 || mauvais char
//				=> erreur
//		-on cherche j'usqu'a la fin si il reste des '#' (on a suprimer ceux lu)
//		-on decale le plus en haut et le plus a gauche;
//		-on lui assigne une id en fontion de l'ordre darriver (maj dan l'ordre)
//		-on lui assigne un type:
//			-un nouveau si la piece est unique, sinon le meme que celle identique
//		
//		-si il y a un '\n' on recomence


//	Le PLATEU:
//		-recuperer un ecran a partir de coordone
//		
//

//	ALGO RECHERCHE:
//		-generer les different ordre recurivement en evitant les doublon
//		-on definie une taille minimale de carre
//		-
