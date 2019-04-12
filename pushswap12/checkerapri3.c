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

int		issortedtopivot(piles *pile, int w)
{
	int	i;
	int	pivot;
	int	j;

	if (w == 0)
	{
		pivot = pile->a[pile->asize - 1];
		j = pile->a[pile->asize - 1];
		i = pile->asize;
		while (i > 0 && pile->a[i - 1] != biggestsorted(pile, 0))
		{
			i--;
			if (pile->a[i] > j)
				return (0);
			j = pile->a[i];
		}
	}
	return (1);
}

int		gestionrecursive(piles *pile)
{
	int	nb;

	nb = 0;
	/* Gestion recursivite*/
	while (!issorted(pile, 0) || !issorted(pile, 1))
	{
if (issorted(pile, 0) && issorted(pile, 1))
{
	printf("OK\n\nKOKORWKG \nshweth\n");
	break ;
}
		printtab(pile);
		printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));

		nb += quicksort(pile, mediumpivot(pile, 0), 1);
		nb += quicksort2(pile);

		/* VOIR SI S"ARRETER AVANT ET FAIRE UN SORT MERGE*/
		printtab(pile);
		printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
	}
	while (pile->bsize)
	{
		nb++;
		pusha(pile);
	}
	printtab(pile);
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
	while (pile->bsize && !issorted(pile, 1))
	{
printtab(pile);
		if (!issorted(pile, 1) && pile->bsize < 15)
			nb += petittrib(pile);
		pivot = mediumpivot(pile, 1);
		k = testk(pile, 1, pivot);
printf("FIRST Pivot2 : %d || K : %d\n", pivot, k);
getchar();
		if (!issorted(pile, 1) && pile->b[0] > pivot)
		{
			nb++;
			pusha(pile);
getchar();
		}
		nb += swapornot(pile, 1);
		if (!issorted(pile, 1) && pile->b[0] <= pivot)
		{
			nb++;
			rotateb(pile);
getchar();
		}
		//nb += swapornot(pile, 1);
	}
printtab(pile);
	return (nb);
}

int		quicksort(piles *pile, int pivot, int sens)
{
	int	nb;
	int	k;

	nb = 0;
	k = 0;

	while (!(issorted(pile, 0)))
	{
		if (!issorted(pile, 0) && pile->asize < 15)
			nb += petittria(pile);
		pivot = mediumpivot(pile, 0);
		k = testk(pile, 0, pivot);
		printtab(pile);
printf("Pivot : %d || K : %d\n", pivot, k);
getchar();
		if (!issorted(pile, 0) && pile->a[0] < pivot)
		{
			nb++;
			pushb(pile);
			printtab(pile);
getchar();
		}
		else if (!issorted(pile, 0) && pile->a[0] >= pivot)
		{
			nb++;
			rotatea(pile);
getchar();
		}
		//nb += swapornot(pile, 1);
	}
(void)sens;
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
	/*	if (!issorted(pile, 0) && pile->a[0] > pile->a[1])
		{
			if (pile->b[0] < pile->b[1])
				swapab(pile);
			else
				swapa(pile);
			nb++;
		}*/
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
			//getchar();
		}
			printtab(pile);
printf("While petittri A\n");
	}
	printtab(pile);
	return (nb);
}

int		petittrib(piles *pile)
{
	int	big;
	int	i;
	int	nb;

	nb = 0;
	i = pile->bsize - 1;
	big = biggest(pile, 1);
	while (!issorted(pile, 1))
	{
		printtab(pile);
		//getchar();
		if (pile->b[0] == biggest(pile, 1))
		{
			pusha(pile);
			nb++;
		}
/*		if (!issorted(pile, 1) && pile->b[0] < pile->b[1])
		{
			if (pile->a[0] > pile->a[1])
				swapab(pile);
			else
				swapb(pile);
			nb++;
		}*/
		else if (!issorted(pile, 1))
		{
			nb++;
			if (rang(pile, 1, smallest(pile, 1)) < pile->bsize / 2)
				rotateb(pile);
			else
				revrotateb(pile);
		}
printf("While petittri A\n");
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
		else if (pile->a[0] > pile->a[1] && i)
			swapa(pile);
		else if (pile->b[0] < pile->b[1] && i)
			swapb(pile);
		return (1);
	}
	return (0);
}
