#include "pushswap.h"

int		smallest(piles *pile, int w)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (++i < pile->asize)
			j = j > pile->a[i] ? pile->a[i] : j;
	}
	else if (w == 1)
	{
		j = pile->b[0];
		while (++i < pile->bsize)
			j = j > pile->b[i] ? pile->b[i] : j;
	}
	return (j);
}
int		biggest(piles *pile, int w)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (i++ < pile->asize)
			j = j < pile->a[i] ? pile->a[i] : j;
	}
	else if (w == 1)
	{
		j = pile->b[0];
		while (++i < pile->bsize)
			j = j < pile->b[i] ? pile->b[i] : j;
	}
	return (j);
}

int		smallestsorted(piles *pile, int w)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (i++ < pile->asize && j < pile->a[i])
			j = pile->a[i];
	}
	else if (w == 1)
	{
		i = pile->bsize - 1;
		j = pile->b[pile->bsize - 1];
		while (i-- < 0)
			j = pile->b[i];
	}
	return (j);
}

int		rangbiggest(piles *pile, int w)
{
	int	big;
	int	i;

	i = -1;
	big = w == 1 ? biggest(pile, 1) : biggest(pile, 0);
	if (w == 0)
	{
		while (i++ < pile->asize)
			if (pile->a[i] == big)
				return (i);
	}
	else if (w == 1)
	{
		while (++i < pile->bsize)
			if (pile->b[i] == big)
				return (i);
	}
	return (i);
}

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

int		issortedfrom(piles *pile, int w, int nb)
{
	int	i;
	int	j;

	i = rangbiggest(pile, 0);
	j = pile->a[i];
	if (w == 0)
	{
		while (i-- > 0)
		{
			if (j < pile->a[i])
				return (i); // ou i - 1 ?
			j = pile->a[i];
		}
	}
	else if (w == 1)
	{
		i = rangbiggest(pile, 1);
		j = pile->b[i];
		while (i-- > 0)
		{
			if (j > pile->a[i])
				return (i);
			j = pile->b[i];
		}
	}
(void)nb;
	return (i);
}

int		isperfectsortedfrom(piles *pile, int w, int nb)
{
	int	i;
	int	j;

	i = rangbiggest(pile, 1);
	j = pile->b[i];
	if (w == 1)
	{
		while (i-- > 0)
		{
			if (j < pile->a[i] || pile->a[i] != biggestafter(pile, 0, j))
				return (i);
			j = pile->a[i];
		}
	}
(void)nb;
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
		{
			j = pile->b[i];
			i--;
		}
	}
	return (j);
}

int		biggestafter(piles *pile, int w, int nb)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (w == 0)
	{
		if (nb == smallest(pile, 0))
			return (nb);
		while (pile->a[i] >= nb)
			i++;
		j = pile->a[i];
		while (i++ < pile->asize - 1)
		{
			if (pile->a[i] < nb && pile->a[i] > j)
				j = pile->a[i];
		}
	}
	else if (w == 1)
	{
		i = pile->bsize - 1;
		if (nb == biggest(pile, 1))
			return (nb);
		while (pile->b[i] <= nb)
			i--;
		j = pile->b[i];
		while (i-- > 0)
		{
	//printf("!!!!!!\n!!!!!!!!!!!!!!!!!!!!!!!!!\nj : %d||pileb[i] : %d   , nb %d, w %d, i %d\n",j,pile->b[i],nb,w,i);
	//getchar();
			if (pile->b[i] > nb && pile->b[i] < j)
				j = pile->b[i];
		}
	}
	return (j);
}

int		testk(piles *pile, int w, int nb)
{
	int	i;

	if (w == 0)
	{
		//if (pile->a[pile->asize - 1] != biggest(pile, 0))
		//	return (pile->a[pile->asize - 1]);
		i = pile->asize;
		while (i--)
			if (nb > pile->a[i])
				return (pile->a[i]);
	}
	else if (w == 1)
	{
		//if (pile->b[pile->bsize - 1] != smallest(pile, 1))
		//	return (pile->b[pile->bsize - 1]);
		i = pile->bsize;
		while (i--)
			if (nb < pile->b[i])
				return (pile->b[i]);
	}
	return (0);
}
