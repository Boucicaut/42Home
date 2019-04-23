#include "pushswap.h"

int		petittria(piles *pile)
{
	int	i;
	int	nb;

	nb = 0;
	i = pile->asize - 1;
	while (!issorted(pile, 0))
	{
//printtab(pile);
//printf("Tri A\n");
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] == smallest(pile, 0))
		{
			pushb(pile, 1);
			nb++;
		}
		if (!issorted(pile, 0))
		{
			nb++;
			if (rang(pile, 0, smallest(pile, 0)) < pile->asize / 2)
			{
				if (pile->b[0] < pile->b[1])
					rotateab(pile, 1);
				else
					rotatea(pile, 1);
			}
			else
			{
				if (pile->b[pile->bsize - 1] > pile->b[0])
					revrotateab(pile, 1);
				else
					revrotatea(pile, 1);
			}
		}
	}
//getchar();
	return (nb);
}

int		petittrib(piles *pile)
{
	int	i;
	int	nb;

	nb = 0;
	i = pile->bsize - 1;
	while (pile->b[0] != biggest(pile, 1))
	{
//printtab(pile);
//printf("Tri B\n");
//getchar();
		if (rang(pile, 1, biggest(pile, 1)) < pile->bsize / 2)
			rotateb(pile, 1);
		else
			revrotateb(pile, 1);
		nb++;
	}
	pusha(pile, 1);
	nb++;
	return (nb);
}

int		sortshortlist(piles *pile)
{
	int	pivot;
	int	nb;

	nb = 0;
	if (pile->a[0] == biggest(pile, 0) && pile->a[pile->asize - 1] == biggestafter(pile, 0, biggest(pile, 0)))
	{
		rotatea(pile, 1);
		nb++;
	}
	while (!issorted(pile, 0))
	{
//printtab(pile);
//getchar();
		pivot = mediumpivot(pile, 0);
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] < pivot)
		{
			nb++;
			pushb(pile, 1);
		}
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] > pile->a[pile->asize - 1])
		{
			nb++;
			revrotatea(pile, 1);
		}
		else if (!issorted(pile, 0))
		{
			rotatea(pile, 1);
			nb++;
		}
	}
	while (pile->bsize)
	{
		nb++;
		pusha(pile, 1);
		nb += swapornot(pile, 1);
	}
	return (nb);
}
