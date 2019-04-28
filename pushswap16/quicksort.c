#include "pushswap.h"

int		quicksort2(t_piles *pile, int pivot)
{
	if (pile->bsize < 30 && pile->asize + pile->bsize < 200)
		petittrib(pile);
	while (biggest(pile, 1) >= pivot && pile->bsize && !issorted(pile, 1))
	{
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] == pivot)
		{
			pusha(pile, 1);
			if (biggest(pile, 1) > pivot)
			{
				if (pile->b[0] < pivot)
					rotateab(pile, 1);
				else
					rotatea(pile, 1);
			}
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] > pivot)
			pusha(pile, 1);
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] < pivot)
			rotateb(pile, 1);
		swapornot(pile, 1);
	}
	if (pivot == pile->a[pile->asize - 1])
		revrotatea(pile, 1);
	return (0);
}

int		quicksort(t_piles *pile, int pivot)
{
	if (pile->asize < 25 && pile->asize + pile->bsize < 200)
		petittria(pile);
	else if (pile->asize < 10)
		petittria(pile);
	while (!issorted(pile, 0) && smallest(pile, 0) <= pivot)
		quicksortope(pile, pivot);
	if (pile->b[pile->bsize - 1] == pivot)
	{
		swapornot(pile, 1);
		revrotateb(pile, 1);
	}
	quicksortbiggestpos(pile);
	return (0);
}

int		quicksortope(t_piles *pile, int pivot)
{
	swapornot(pile, 1);
	if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] == pivot)
	{
		pushb(pile, 1);
		if (smallest(pile, 0) < pivot)
		{
			if (pile->a[0] > pivot)
				rotateab(pile, 1);
			else
				rotateb(pile, 1);
		}
	}
	if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] < pivot)
		pushb(pile, 1);
	if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] > pivot)
		rotatea(pile, 1);
	return (0);
}

int		quicksortbiggestpos(t_piles *pile)
{
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
	}
	return (0);
}
