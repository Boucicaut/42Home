/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:14:21 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/28 15:21:12 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>

typedef struct	s_piles
{
	int			*a;
	int			*b;
	int			asize;
	int			bsize;
}				t_piles;

int				freechecker(char *ins, t_piles *pile);
int				quicksortbiggestpos(t_piles *pile);
int				quicksortope(t_piles *pile, int pivot);
int				execute_ins(t_piles *pile, char *ins);
int				checkerope(char *ins, t_piles *pile);
int				checkerope2(char *ins, t_piles *pile);
int				sortshortlist(t_piles *pile);
int				pusherror(char **s, int argc);
int				doublonerror(t_piles *pile);
int				intermediaire(t_piles *pile);
int				gestionrecursive(t_piles *pile);
int				swapornot(t_piles *pile, int i);
int				petittria(t_piles *pile);
int				petittrib(t_piles *pile);
int				mediumpivotb(t_piles *pile);
int				mediumpivot(t_piles *pile, int w);
int				rang(t_piles *pile, int w, int nb);
int				quicksort(t_piles *pile, int pivot);
int				checkvalue(t_piles *pile);
int				quicksort2(t_piles *pile, int p);
int				biggestafter(t_piles *pile, int w, int pivot);
int				biggestsorted(t_piles *pile, int w);
int				smallest(t_piles *pile, int w);
int				biggest(t_piles *pile, int w);
int				issorted(t_piles *pile, int w);
t_piles			*inittabs(int argc, char **argv, int k);
t_piles			*inittabs2(int k, char **argv, int argc, t_piles *pile);
int				printtab(t_piles *pile);
int				reducerank(t_piles *pile, int w);
int				increaserank(t_piles *pile, int w);
int				swapa(t_piles *pile, int print);
int				swapab(t_piles *pile, int print);
int				swapb(t_piles *pile, int print);
int				pusha(t_piles *pile, int print);
int				pushb(t_piles *pile, int print);
int				pushab(t_piles *pile, int print);
int				rotatea(t_piles *pile, int print);
int				rotateb(t_piles *pile, int print);
int				rotateab(t_piles *pile, int print);
int				revrotatea(t_piles *pile, int print);
int				revrotateb(t_piles *pile, int print);
int				revrotateab(t_piles *pile, int print);
#endif
