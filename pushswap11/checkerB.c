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
	printtab(pile);


	printf("LstA\n");
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
		{
			nb += quicksort(pile, mediumpivot(pile, 0));
printtab(pile);
printf("\n\nNb after quicksortA : %d\n", nb);
			getchar();
		}
		nb += intermediaire(pile);
printtab(pile);
printf("\n\nNb after inter : %d\n", nb);
getchar();

		if (!issorted(pile, 0) || !issorted(pile, 1))
			nb += quicksort2(pile);
printtab(pile);
printf("\n\nNb after quicksortB : %d\n", nb);
getchar();

		printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
	}
	while (pile->bsize)
	{
		nb++;
		pusha(pile);
	}
	return (nb);
}

int		intermediaire(piles *pile)
{
	int	nb;

	nb = 0;
	while (issorted(pile, 0) && ((pile->bsize && pile->b[0] == biggest(pile, 1)) || (pile->bsize > 1 && pile->b[1] == biggest(pile, 1))))
	{
		if (pile->bsize > 1 && (pile->b[1] == biggest(pile, 1)))
		{
			swapb(pile);
			nb++;
		}
		pusha(pile);
		nb++;
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
if (pile->bsize < 20)
	nb += petittrib(pile);	// TESTER PETIT TRI ***
	printf("Biggsort : %d   Smallsort : %d\n\n", biggestsorted(pile, 0), smallestsorted(pile, 0));
	//pivot = pivotb(pile);
	pivot = mediumpivot(pile, 1);
printf("FIRST Pivot2 : %d\n", pivot);
	while (biggest(pile, 1) > pivot && pile->bsize && !issorted(pile, 1))
	{
printtab(pile);
printf("Pivot2 : %d\n", pivot);
//getchar();
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] == pivot)
		{
			nb += 2;
			pusha(pile);
			rotatea(pile); // opti ici avec rotateab(pile);
			//getchar();
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] > pivot)
		{
			//if (issorted(pile, 1) && pile->b[0] > smallest(pile, 0))
			//	return (nb);
			nb++;
			pusha(pile);
			printtab(pile);
			//getchar();
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] < pivot)
		{
			nb++;
			rotateb(pile);
			printtab(pile);
			//getchar();
		}
		nb += swapornot(pile, 1);
		printtab(pile);
	}
	if (pivot == pile->a[pile->asize - 1])
	{
		nb++;
		revrotatea(pile);
		printtab(pile);
	printf("ON REPLACE PIVOT2 AU TOP DE A\n\n");
		//getchar();
	}
	printtab(pile);
	return (nb);
}

int		quicksort(piles *pile, int pivot)
{
	int	nb;

	nb = 0;
	if (pile->asize < 20)
		nb += petittria(pile);
	pivot = mediumpivot(pile, 0);
printtab(pile);
printf("FIRSTPivot : %d\n", pivot);
	while (!issorted(pile, 0) && smallest(pile, 0) <= pivot)
	{
		printtab(pile);
printf("Pivot : %d\n", pivot);
//getchar();
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] == pivot)
		{
			nb += 2;
			pushb(pile);
			rotateb(pile);
			printtab(pile);
			//getchar();
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] < pivot)
		{
			nb++;
			pushb(pile);
			printtab(pile);
			//getchar();
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] > pivot)
		{
			nb++;
			rotatea(pile);
			printtab(pile);
			//getchar();
		}
		printtab(pile);
		nb += swapornot(pile, 1);
		//getchar();
	}
	if (pile->b[pile->bsize - 1] == pivot)
	{
		nb++;
		revrotateb(pile);
	}
	while (pile->a[pile->asize - 1] != biggest(pile, 0))
	{
		nb += swapornot(pile, 1);
		revrotatea(pile);
		nb++;
	}
	printtab(pile);
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
		printtab(pile);
printf("Issorted triiA ? %d\n", issorted(pile, 0));
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
		printtab(pile);
printf("While petittri A\n");
	}
	printtab(pile);
	return (nb);
}

int		petittrib(piles *pile)
{
	int	i;
	int	nb;

	nb = 0;
	i = pile->bsize - 1;
	while (!issorted(pile, 1))
	{
		printtab(pile);
		//getchar();
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
printf("While petittri B\n");
	}
	printtab(pile);
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

int		mediumpivot(piles *pile, int w)
{
	int	i;
	int	j;
	int	bigsort;

	j = smallest(pile, 0);
	if (w == 0)
	{
		if (pile->a[pile->asize - 1] == biggest(pile, 0))
		{
			bigsort = (rang(pile, 0, biggestsorted(pile, 0)) / 2);
			j = biggestsorted(pile, 0);
		}
		else
		{
			bigsort = pile->asize / 2;
			j = biggest(pile, 0);
		}
		i = 0;
		while (i++ < bigsort)
		{
			j = biggestafter(pile, 0, j);
		}
		return (j);
	}

	else if (w == 1)
	{
		if (pile->b[pile->bsize - 1] == smallest(pile, 1))
		{
			bigsort = (rang(pile, 1, biggestsorted(pile, 1)) / 2);
			j = biggestsorted(pile, 1);
		}
		else
		{
			bigsort = pile->bsize / 2;
			j = smallest(pile, 1);
		}
		i = 0;
		while (i++ < bigsort)
			j = biggestafter(pile, 1, j);
		return (j);
	}
	return (j);
}
