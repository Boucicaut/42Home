#include "pushswap.h"

int		quicksort2(piles *pile)
{
	int	pivot;
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	pivot = mediumpivot(pile, 1);
	if (pile->bsize < 30 && pile->asize + pile->bsize < 200)
		nb += petittrib(pile);
	while (biggest(pile, 1) >= pivot && pile->bsize && !issorted(pile, 1))
	{
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] == pivot)
		{
			pusha(pile, 1);
			nb++;
			if (biggest(pile, 1) > pivot)
			{
				if (pile->b[0] < pivot)
					rotateab(pile, 1);
				else
					rotatea(pile, 1);
				nb++;
			}
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] > pivot)
		{
			nb++;
			pusha(pile, 1);
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] < pivot)
		{
			nb++;
			rotateb(pile, 1);
		}
		nb += swapornot(pile, 1);
	}
	if (pivot == pile->a[pile->asize - 1])
	{
		nb++;
		revrotatea(pile, 1);
	}
	return (nb);
}

int		quicksort(piles *pile, int pivot)
{
	int	nb;

	nb = 0;
	pivot = mediumpivot(pile, 0);
	if (pile->asize < 25 && pile->asize + pile->bsize < 200)
		nb += petittria(pile);
	else if (pile->asize < 10)// && pile->asize + pile->bsize < 200)
		nb += petittria(pile);
	while (!issorted(pile, 0) && smallest(pile, 0) <= pivot)
	{
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] == pivot)
		{
			pushb(pile, 1);
			nb++;
			if (smallest(pile, 0) < pivot)
			{
				nb++;
				if (pile->a[0] > pivot)
					rotateab(pile, 1);
				else
					rotateb(pile, 1);
			}
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] < pivot)
		{
			nb++;
			pushb(pile, 1);
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] > pivot)
		{
			nb++;
			rotatea(pile, 1);
		}
	}
	if (pile->b[pile->bsize - 1] == pivot)
	{
		nb += swapornot(pile, 1);
		revrotateb(pile, 1);
		nb++;
	}
	while (pile->a[pile->asize - 1] != biggest(pile, 0))
	{
		if (rang(pile, 0, biggest(pile, 0)) < pile->asize / 2)
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
		nb++;
	}
	return (nb);
}
