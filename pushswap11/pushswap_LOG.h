#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum	name_piles	{a, b};

typedef struct	piles
{
	int	*a;
	int	*b;
	int	asize;
	int	bsize;
}	piles;

char	*strrealloc(char *str, char *new);

char	*intermediaire(piles *pile, char *ins);

int	testk(piles *pile, int w, int nb);
char	*gestionrecursive(piles *pile, char *ins);

char *swapornot(piles *pile, int i, char *ins);

int	issortedfrom(piles *pile, int w, int nb);
int	isperfectsortedfrom(piles *pile, int w, int nb);

char	*petittria(piles *pile, char *ins);
char	*petittrib(piles *pile, char *ins);

int	mediumpivot(piles *pile, int w);
int	randompivot(piles *pile, int w);
int	canbesortedb(piles *pile);
int	canbesorteda(piles *pile);
int	canbesorted(piles *pile, int w);

int	randompivot(piles *pile, int w);
int	canbesortedb(piles *pile);
int	canbesorteda(piles *pile);

int	pivota(piles *pile);
int	pivotb(piles *pile);
int	rang(piles *pile, int w, int nb);
int	rangbiggest(piles *pile, int w);
int	insertionsort(piles *pile);


char	*quicksort(piles *pile, int pivot, char *ins);
char	*quicksort2(piles *pile, char *ins);


int	quicksort3(piles *pile, int pivot);
int	smallestsorted(piles *pile, int w);
int	biggestafter(piles *pile, int w, int pivot);
int	biggestsorted(piles *pile, int w);
int	smallest(piles *pile, int w);
int	biggest(piles *pile, int w);
int	recursivequicksort(piles *pile);
int	*formatargpushswap(char *arg);
int	fullifelse(piles *pile);
int	issorted(piles *pile, int w);
int	printtab(piles *pile);
int	printtabslowmo(piles *pile);
piles	*inittabs(int argc, char **argv, int mode);
int	printtab(piles *pile);
int	sortrotatepush(piles *pile);
int	reducerank(piles *pile, int w);
int	increaserank(piles *pile, int w);
int	swapa(piles *pile);
int	swapab(piles *pile);
int	swapb(piles *pile);
int	pusha(piles *pile);
int	pushb(piles *pile);
int	pushab(piles *pile);
int	rotatea(piles *pile);
int	rotateb(piles *pile);
int	rotateab(piles *pile);
int	revrotatea(piles *pile);
int	revrotateb(piles *pile);
int	revrotateab(piles *pile);
#endif
