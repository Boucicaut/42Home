#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "./libft/libft.h"

#include <stdlib.h>
#include <string.h>

enum	name_piles	{a = 0, b};

typedef struct	piles
{
	int	*a;
	int	*b;
	int	asize;
	int	bsize;
}	piles;

int		freechecker(char *ins, piles *pile);
int		quicksortbiggestpos(piles *pile);
int		quicksortope(piles *pile, int pivot);
int		checkerope(char *ins, piles *pile);
int		checkerope2(char *ins, piles *pile);
int		sortshortlist(piles *pile);
int		pusherror(char **str, int argc, int mode);
int		doublonerror(piles *pile);//char **str, int argc, int mode);
int		doublonerror2(char **str);
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
#endif
