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

int	insertionsort(piles *pile);
int	quicksort(piles *pile, int pivot);
int	quicksort2(piles *pile);
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
