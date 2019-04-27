#include "pushswap.h"

int		rang(piles *pile, int w, int nb)
{
	int	vl;
	int	i;

	i = 0;
	if (w == 0)
	{
		vl = pile->a[0];
		while (i < pile->asize)
		{
			if (pile->a[i] == nb)
				return (i);
			i++;
		}
	}
	else if (w == 1)
	{
		vl = pile->b[0];
		while (i < pile->bsize)
		{
			if (pile->a[i] == nb)
				return (i);
			i++;
		}
	}
	return (i);
}

int		biggestsorted(piles *pile, int w)
{
	int	i;
	int	j;

	i = pile->asize - 1;
	j = 0;
	if (w == 0)
	{
		if (pile->a[pile->asize - 1] != biggest(pile, 0))
			return (pile->a[pile->asize - 1]);
		j = pile->a[pile->asize - 1];
		while (i-- > 0 && pile->a[i] == biggestafter(pile, 0, j))
			j = pile->a[i];
	}
	else if (w == 1)
	{
		if (pile->b[pile->bsize - 1] != smallest(pile, 1))
			return (pile->b[pile->bsize - 1]);
		i = pile->bsize - 2;
		j = pile->b[pile->bsize - 1];
		while (i >= 0 && pile->b[i] == biggestafter(pile, 1, j))
			j = pile->b[i--];
	}
	return (j);
}

int		biggestafter(piles *pile, int w, int nb)
{
	int	i;
	int	j;

	i = w == 0 ? 0 : pile->bsize - 1;
	if (w == 0)
	{
		if (nb == smallest(pile, 0))
			return (nb);
		while (pile->a[i] >= nb)
			i++;
		j = pile->a[i];
		while (i++ < pile->asize - 1)
			j = (pile->a[i] < nb && pile->a[i] > j) ? pile->a[i] : j;
	}
	else
	{
		if (nb == biggest(pile, 1))
			return (nb);
		while (pile->b[i] <= nb)
			i--;
		j = pile->b[i];
		while (i-- > 0)
			j = (pile->b[i] > nb && pile->b[i] < j) ? pile->b[i] : j;
	}
	return (j);
}
