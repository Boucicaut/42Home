#include "pushswap.h"

int		petittria(t_piles *pile)
{
	while (!issorted(pile, 0))
	{
		swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] == smallest(pile, 0))
			pushb(pile, 1);
		if (!issorted(pile, 0))
		{
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
	return (0);
}

int		petittrib(t_piles *pile)
{
	int	i;

	i = pile->bsize - 1;
	while (pile->b[0] != biggest(pile, 1))
	{
		if (rang(pile, 1, biggest(pile, 1)) < pile->bsize / 2)
			rotateb(pile, 1);
		else
			revrotateb(pile, 1);
	}
	pusha(pile, 1);
	return (0);
}

int		sortshortlist(t_piles *pile)
{
	int	pivot;

	if (pile->a[0] == biggest(pile, 0) && pile->a[pile->asize - 1] == biggestafter(pile, 0, biggest(pile, 0)))
		rotatea(pile, 1);
	while (!issorted(pile, 0))
	{
		pivot = mediumpivot(pile, 0);
		swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] < pivot)
			pushb(pile, 1);
		swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] > pile->a[pile->asize - 1])
			revrotatea(pile, 1);
		else if (!issorted(pile, 0))
			rotatea(pile, 1);
	}
	while (pile->bsize)
	{
		pusha(pile, 1);
		swapornot(pile, 1);
	}
	return (0);
}
