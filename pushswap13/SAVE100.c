#include "pushswap.h"

int	main(int argc, char **argv)
{
	piles	*pile;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pile = inittabs(argc, argv, 1);

	issorted(pile, 0);


	printf("----  %d -----\n\n", gestionrecursive(pile));
	free(pile);
	return (0);
}

int		gestionrecursive(piles *pile)
{
	int	nb;

	nb = 0;
	/* Gestion recursivite*/
	while (!issorted(pile, 0) || !issorted(pile, 1))
	{
		while (issorted(pile, 0) == 0)
			nb += quicksort(pile, mediumpivot(pile, 0), 1);
		if (!issorted(pile, 0) || !issorted(pile, 1))
			nb += quicksort2(pile);
		nb += intermediaire(pile);
	}
	while (pile->bsize)
	{
		nb++;
		pusha(pile);
	}
printtab(pile);
	return (nb);
}

int		intermediaire(piles *pile)
{
	int	nb;

	nb = 0;
	while (issorted(pile, 0) && ((pile->bsize && pile->b[0] == biggest(pile, 1)) || (pile->bsize > 1 && pile->b[1] == biggest(pile, 1))))
	{
		nb += swapornot(pile, 1);
		if (pile->b[1] == biggest(pile, 1))
		{
			nb += swapornot(pile, 1);
			nb++;
		}
		if (pile->b[0] == biggest(pile, 1))
		{
			pusha(pile);
			nb++;
		}
printtab(pile);
	}
	return (nb);
}
/**********************************************************/
int		quicksort2(piles *pile)
{
	int	pivot;
	int	i;
	int	nb;
	int	k;
	
	nb = 0;
	i = -1;
	//pivot = pivotb(pile);
	pivot = mediumpivot(pile, 1);
if (pile->bsize < 10)
	nb += petittrib(pile);	// TESTER PETIT TRI ***
	while (biggest(pile, 1) > pivot && pile->bsize && !issorted(pile, 1))
	{
printtab(pile);
printf("PivotA : %d\n", pivot);
getchar();
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] == pivot)
		{
			nb += 2;
			pusha(pile);
			rotatea(pile); // opti ici avec rotateab(pile);
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] > pivot)
		{
			nb++;
			pusha(pile);
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] < pivot)
		{
			nb++;
			rotateb(pile);
		}
		nb += swapornot(pile, 1);
	}
	if (pivot == pile->a[pile->asize - 1])
	{
		nb++;
		revrotatea(pile);
	}
	return (nb);
}

int		quicksort(piles *pile, int pivot, int sens)
{
	int	nb;

	nb = 0;
	pivot = mediumpivot(pile, 0);
	if (pile->asize < 40)
		nb += petittria(pile);
	while (!issorted(pile, 0) && smallest(pile, 0) <= pivot)
	{
printtab(pile);
printf("PivotA : %d\n", pivot);
getchar();
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] == pivot)
		{
			nb += 2;
			pushb(pile);
			rotateb(pile);
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] < pivot)
		{
			nb++;
			pushb(pile);
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] > pivot)
		{
			nb++;
			rotatea(pile);
		}
		nb += swapornot(pile, 1);
	}
	if (pile->b[pile->bsize - 1] == pivot)
	{
		nb += swapornot(pile, 1);
		revrotateb(pile);
		nb++;
	}
	while (pile->a[pile->asize - 1] != biggest(pile, 0))
	{
		if (rang(pile, 0, biggest(pile, 0)) <= pile->asize / 2)
			rotatea(pile);
		else
			revrotatea(pile);
		nb++;
	}
	nb += swapornot(pile, 1);
	return (nb);
}

int		pivota(piles *pile)
{
	int	i;
	int	bigb;
	int	j;

	i = 0;
	bigb = biggest(pile, 1);
	j = pile->a[pile->asize - 1];
	if (0 >= issortedfrom(pile, 0, biggest(pile, 0)))
	{
		while (i < pile->asize)
		{
			if (pile->a[i] == biggest(pile, 0) && i + 1 < pile->asize)
			{
				printf("|| %d ||\n", pile->a[i + 1]);
				return (pile->a[i + 1]);
			}
			i++;
		}
	}
	i = pile->asize;
	while (i-- > 0)
	{
		if (j < bigb || j < pile->a[i])
		{
			return (j);
		}
		j = pile->a[i];
	}
	return (pile->a[pile->asize - 1]);
}

int		pivotb(piles *pile)
{
	int	i;
	int	smaa;
	int	j;

	printtab(pile);
	//getchar();
	i = 0;
	smaa = smallest(pile, 0);
	j = pile->b[pile->bsize - 1];
	i = pile->bsize;
	while (i-- > 0)
	{
		if (pile->bsize == 1 || (pile->b[0] < smaa && issorted(pile, 1)))
			return (pile->b[0]);
		if (j > smaa || j > pile->b[i])
		{
			//while (j != pile->b[i])
			//	j = pile->b[i--];
			printf("J : %d\n", j);
			return (j);
		}
		j = pile->b[i];
	}
	return (pile->b[pile->bsize - 1]);
}

int		petittria(piles *pile)
{
	int	i;
	int	nb;

	nb = 0;
	i = pile->asize - 1;
	while (!issorted(pile, 0))
	{
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] == smallest(pile, 0))
		{
			pushb(pile);
			nb++;
		}
		if (!issorted(pile, 0))
		{
			nb++;
			if (rang(pile, 0, smallest(pile, 0)) < pile->asize / 2)
				rotatea(pile);
			else
				revrotatea(pile);
		}
	}
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
		if (rang(pile, 1, biggest(pile, 1)) < pile->bsize / 2)
			rotateb(pile);
		else
			revrotateb(pile);
		nb++;
	}
	pusha(pile);

/*	while (!issorted(pile, 1))
	{
		nb += swapornot(pile, 1);
		while (pile->b[0] == biggest(pile, 1))
		{
			pusha(pile);
			nb++;
		}
		if (!issorted(pile, 1))
		{
			nb++;
			if (rang(pile, 1, biggest(pile, 1)) < pile->bsize / 2)
				rotateb(pile);
			else
				revrotateb(pile);
		}
	}*/
	return (nb);
}

int		swapornot(piles *pile, int i)
{
	if ((pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1]))
	{
		if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
			swapab(pile);
		else if (i && pile->a[0] > pile->a[1])
			swapa(pile);
		else if (i && pile->b[0] < pile->b[1])
			swapb(pile);
		return (1);
	}
	return (0);
}
