#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "./libft/libft.h"

#include <stdlib.h>
#include <string.h>

typedef struct	s_piles
{
	int	*a;
	int	*b;
	int	asize;
	int	bsize;
}	t_piles;

int		freechecker(char *ins, t_piles *pile);
int		quicksortbiggestpos(t_piles *pile);
int		quicksortope(t_piles *pile, int pivot);
int		checkerope(char *ins, t_piles *pile);
int		checkerope2(char *ins, t_piles *pile);
int		sortshortlist(t_piles *pile);
int		pusherror(char **str, int argc, int mode);
int		doublonerror(char **str, int argc, int mode);
int		doublonerror2(char **str);
<<<<<<< Updated upstream
int		intermediaire(t_piles *pile);
int		gestionrecursive(t_piles *pile);
int		swapornot(t_piles *pile, int i);
int		petittria(t_piles *pile);
int		petittrib(t_piles *pile);
int		mediumpivotb(t_piles *pile);
int		mediumpivot(t_piles *pile, int w);
int		rang(t_piles *pile, int w, int nb);
int		quicksort(t_piles *pile, int pivot);
int		quicksort2(t_piles *pile, int pivot);
int		biggestafter(t_piles *pile, int w, int pivot);
int		biggestsorted(t_piles *pile, int w);
int		smallest(t_piles *pile, int w);
int		biggest(t_piles *pile, int w);
int		issorted(t_piles *pile, int w);
t_piles	*inittabs(int argc, char **argv, int mode);
t_piles	*inittabs2(char **argv, t_piles *pile);
int		printtab(t_piles *pile);
int		reducerank(t_piles *pile, int w);
int		increaserank(t_piles *pile, int w);
int		swapa(t_piles *pile, int print);
int		swapab(t_piles *pile, int print);
int		swapb(t_piles *pile, int print);
int		pusha(t_piles *pile, int print);
int		pushb(t_piles *pile, int print);
int		pushab(t_piles *pile, int print);
int		rotatea(t_piles *pile, int print);
int		rotateb(t_piles *pile, int print);
int		rotateab(t_piles *pile, int print);
int		revrotatea(t_piles *pile, int print);
int		revrotateb(t_piles *pile, int print);
int		revrotateab(t_piles *pile, int print);
=======
int		intermediaire(piles *pile);
int		gestionrecursive(piles *pile);
int		swapornot(piles *pile, int i);
int		petittria(piles *pile);
int		petittrib(piles *pile);
int		mediumpivotb(piles *pile);
int		mediumpivot(piles *pile, int w);
int		rang(piles *pile, int w, int nb);
int		quicksort(piles *pile, int pivot);
int		checkvalue(piles *pile);
int		quicksort2(piles *pile, int pivot);
int		biggestafter(piles *pile, int w, int pivot);
int		biggestsorted(piles *pile, int w);
int		smallest(piles *pile, int w);
int		biggest(piles *pile, int w);
int		issorted(piles *pile, int w);
piles	*inittabs(int argc, char **argv, int mode);
piles	*inittabs2(char **argv, piles *pile);
int		printtab(piles *pile);
int		reducerank(piles *pile, int w);
int		increaserank(piles *pile, int w);
int		swapa(piles *pile, int print);
int		swapab(piles *pile, int print);
int		swapb(piles *pile, int print);
int		pusha(piles *pile, int print);
int		pushb(piles *pile, int print);
int		pushab(piles *pile, int print);
int		rotatea(piles *pile, int print);
int		rotateb(piles *pile, int print);
int		rotateab(piles *pile, int print);
int		revrotatea(piles *pile, int print);
int		revrotateb(piles *pile, int print);
int		revrotateab(piles *pile, int print);
>>>>>>> Stashed changes
#endif
