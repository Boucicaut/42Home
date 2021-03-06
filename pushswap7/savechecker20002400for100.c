#include "pushswap.h"

int	main(int argc, char **argv)
{
	int	sizes[2];
	piles	*pile;
	int		i;
	int		j;

	pile = inittabs(argc, argv, 1);

	issorted(pile, 0);
	printtab(pile);
//	sortrotatepush(pile);

printf("----  %d -----\n\n", quicksort(pile, pile->a[pile->asize - 1]));
	j = 0;
	/*while (j++ < pile->asize)
		pushb(pile);
fullifelse(pile);*/

	//printtab(pile);

//trier b a l'envers pour pusha et pas rb et pusha
//attention de bien optimiser les swapab si faisable !!
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

int		quicksort3(piles *pile)
{
	int	pivot;
	int	i;
	int	nb;
	int	rangbiggest;

printf("Biggsort : %d   Smallsort : %d\n\n", biggestsorted(pile, 1), smallestsorted(pile, 1));
//getchar();
	nb = 0;
//printf("BEFORE\n");
	//pivot = pile->bsize ? biggest(pile, 1) : 0;
	//pivot = pile->b[0]; // GARDER ?
	//pivot = biggestsorted(pile, 1);	//utiliser biggest a et biggest b !!attention
	rangbiggest = 0;
	while (pile->b && pile->b[0] == biggest(pile, 1))
	{
		pusha(pile);
		nb++;
	}
	pivot = pile->b[pile->bsize - 1];
	//pivot = biggest(pile, 1);
printf("Pivot2 : %d\n", pivot);
while (pile->bsize && pile->b[0] != pivot)
{
printf("Pivot2 : %d\n", pivot);
		if (pile->b[0] < pile->b[1] || pile->a[0] > pile->a[1])
		{
			if (pile->b[0] < pile->b[1] && pile->a[0] > pile->a[1])
				swapab(pile);
			else if	(pile->a[0] > pile->a[1])
				swapa(pile);
			else if (pile->b[0] < pile->b[1])
				swapb(pile);
			nb++;
		}
		if (pile->b[0] < pivot)
		{
			rotateb(pile);
			nb++;
		}
		if (pile->b[0] > pivot)
		{
			pusha(pile);
			nb++;
		}
		printtab(pile);
}
/*if (issorted(pile, 0) && pile->bsize == 0)
	return (quicksort2(pile));
	printtab(pile);*/
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
	i = pile->asize;
	while (i-- > 0)
	{
		if (j < bigb || j < pile->a[i])
			return (j);
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
printf("+++++++++++++++++++++++++++++++\n++++++++++++++++++++\n");
	i = 0;
	smaa = smallest(pile, 0);
	j = pile->b[pile->bsize - 1];
	i = pile->bsize;
	while (i-- > 0)
	{
		if (pile->bsize == 1 || (pile->b[0] < smaa && issorted(pile, 1)))
			return (pile->b[0]);
		if (j > smaa || j > pile->b[i])
			return (j);
		j = pile->b[i];
printf("smaa %d   j %d\n", smaa, j);
	}
	return (pile->b[pile->bsize - 1]);
}
/**********************************************************/
int		quicksort2(piles *pile)
{
	int	pivot;
	int	i;
	int	nb;

	nb = 0;
/*partitioning*/
	i = -1;
printf("Biggsort : %d   Smallsort : %d\n\n", biggestsorted(pile, 0), smallestsorted(pile, 0));
//getchar();
	//pivot = pile->a[pile->asize - 1];
	//pivot = pile->b[pile->bsize - 1];
	//pivot = biggestsorted(pile, 1);
	pivot = pivotb(pile);
printf("Pivot2 : %d\n", pivot);
//getchar();
	while (pivot != pile->b[0])
	{
printf("Pivot2 : %d\n", pivot);
getchar();
		if (pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1])
		{
			if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
				swapab(pile);
			else if (pile->a[0] > pile->a[1])
				swapa(pile);
			else if (pile->b[0] < pile->b[1])
				swapb(pile);
			nb++;
		}
		if (pile->b[0] > pivot)
		{
			if (issorted(pile, 1) && pile->b[0] < smallest(pile, 0))
				;
			nb++;
			pusha(pile);
			printtab(pile);
			//getchar();
		}
		//else if (pile->b[0] < pivot || (pile->a[0] > pile->a[1] && pile->a[0] > pile->a[pile->asize]))
		{
			//if (pile->b[0] < pivot && (pile->a[0] > pile->a[1] && pile->a[0] > pile->a[pile->asize]))
			//	rotateab(pile);
			if (pile->b[0] < pivot)
			{
				rotateb(pile);
				nb++;
			}
			//else
			//	rotatea(pile);
		}
printtab(pile);
	}
	return (nb);
}


int		quicksort(piles *pile, int pivot)
{
	int	i;
	int	nb;

	nb = 0;
/*partitioning*/
	i = -1;
printf("Biggsort : %d   Smallsort : %d\n\n", biggestsorted(pile, 0), smallestsorted(pile, 0));
//getchar();
	//pivot = pile->a[pile->asize - 1];
	//pivot = biggestsorted(pile, 0);
	//pivot = pivota(pile);
printf("Pivot : %d\n", pivot);
	while (pivot != pile->a[0])
	{
printf("Pivot : %d\n", pivot);
getchar();
		if (pile->a[0] < pivot)
		{
			if (!(issorted(pile, 0) && smallest(pile, 0) > biggest(pile, 1)))
			{
				nb++;
				pushb(pile);
				printtab(pile);
			}
		}
		if (pile->a[0] > pivot)
		{
			rotatea(pile);
			nb++;
		}
printtab(pile);
	}
printf("Nb : %d\n", nb);
while (!issorted(pile, 0) || !issorted(pile, 1))
{
printtab(pile);
printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
		//getchar();
	nb += pile->bsize ? quicksort2(pile) : 0;
printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
		//getchar();
	nb += issorted(pile, 0) ? 0 : quicksort(pile, pivota(pile));
}
while (pile->bsize)
{
	pusha(pile);
	nb++;
}
	return (nb);
}

int		recursivequicksort2(piles *pile)
{
	int	pivot;
	int	i;
	int	nb;

	nb = 0;
	if (pile->b[0] < pile->b[1])
	{
		nb++;
		swapb(pile);
	}
	//pivot = pile->b[0];
	pivot = smallestsorted(pile, 1);;
	i = -1;
	while (pile->b[0] < pivot)
	{
		if (pile->b[1] > pivot)
		{
			nb++;
			swapb(pile);
		}
		while (pile->b[0] < pivot)
		{
			nb++;
			revrotateb(pile);
			printtab(pile);
			//getchar();
		}
		printtab(pile);
		//getchar();
	}
	pusha(pile);
	nb++;
	while ((pile->b[0] == pivot && pile->bsize) || (pile->bsize > 1 && pile->b[1] == pivot))
	{
		if (pile->b[0] < pile->b[1])
		{
			nb++;
			swapb(pile);
		}
		pusha(pile);
		nb++;
		printtab(pile);
		i++;
		//getchar();
	}
	if (pile->bsize > 0)
		nb += recursivequicksort2(pile);
	return (nb);
}

int		recursivequicksort(piles *pile)
{
	int	pivot;
	int	i;
	int	nb;

	nb = 0;
/*partitioning*/
	i = -1;
	//pivot = pile->a[pile->asize - 1];
	pivot = biggestsorted(pile, 0);
while (pivot != pile->a[0])
{
printf("Pivot %d\n--------------------------\n", pivot);
	if (pile->a[0] > pile->a[1])
	{
		nb++;
		swapa(pile);
	}
	if (pile->a[0] < pivot)
	{
		nb++;
		pushb(pile);
	}
	while (pile->a[0] > pivot)
	{
		revrotatea(pile);
		nb++;
	}
	printtab(pile);
}
while (!issorted(pile, 0) || pile->bsize != 0)
{
	nb += recursivequicksort2(pile);
	nb += recursivequicksort(pile);
}
	printf("NB %d \n", nb);
	return (nb);
}

int		fullifelse(piles *pile)
{
	int	i;
	int	last;
	
	last = pile->asize -1;
	i = pile->a[0];
	if (pile->a[0] < pile->a[1] && pile->a[0] < pile->a[pile->asize - 1])
	{
		if (pile->a[1] < pile->a[last])
		{
			revrotatea(pile);
			swapa(pile);
			rotatea(pile);
			swapa(pile);
		}
		else
		{
			revrotatea(pile);
			swapa(pile);
		}
	}
	else if (pile->a[0] > pile->a[1] && pile->a[0] < pile->a[pile->asize - 1])
	{
		if (pile->a[1] < pile->a[last])
			swapa(pile);
		else
			rotatea(pile);
	}
	else if (pile->a[0] < pile->a[1] && pile->a[0] > pile->a[pile->asize - 1])
		revrotatea(pile);
	else if (pile->a[0] > pile->a[1] && pile->a[0] > pile->a[pile->asize - 1])
	{
		if (pile->a[1] < pile->a[last])
		{
			revrotatea(pile);
			swapa(pile);
			rotatea(pile);
		}
		else
		{
			swapa(pile);
			revrotatea(pile);
		}
	}
printtab(pile);
//getchar();
	
	while (issorted(pile, 0) != 1)
		fullifelse(pile);
	printtab(pile);
	return (0);
}

int		sortrotatepush(piles *pile)
{
	int	i;
	int j;
	int	nbins;

	nbins = 0;
	while (issorted(pile, 0) != 1)
	{
		j = 0; // plus grand nb possible
		i = pile->a[0];
		while (j < pile->asize)
		{
			i = pile->a[j] < i ? pile->a[j] : i;
			j++;
		}
		while (pile->a[0] != i)
		{
			rotatea(pile); // ou rev si j > asize / 2
			nbins++;
		}
		pushb(pile);
		nbins++;
	}
	i = 0;
	while (i < pile->bsize)
	{
		nbins++;
		pusha(pile);
	}
	printf("Nombre d'instructions : %d\n", nbins);
	return (0);
}
