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

recursivequicksort(pile);
	j = 0;
	/*while (j++ < pile->asize)
		pushb(pile);
fullifelse(pile);*/

	printtab(pile);

//trier b a l'envers pour pusha et pas rb et pusha
//attention de bien optimiser les swapab si faisable !!
	free(pile);
	return (0);
}
int		smallest(piles *pile, int w)
{
	int	i;
	int	j;

	i = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (i++ < pile->asize)
			j = j > pile->a[i] ? pile->a[i] : j;
	}
	else if (w == 1)
	{
		j = pile->b[0];
		while (i++ < pile->bsize)
			j = j > pile->b[i] ? pile->b[i] : j;
	}
	return (j);
}
int		biggest(piles *pile, int w)
{
	int	i;
	int	j;

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
		while (i++ < pile->bsize)
			j = j < pile->b[i] ? pile->b[i] : j;
	}
	return (j);
}

int		recursivequicksort2(piles *pile)
{
	int	pivot;
	int	i;

	if (pile->b[0] < pile->b[1])
		swapb(pile);
	pivot = biggest(pile, 1);
	i = -1;
	while (pile->b[0] < pivot)
	{
		if (pile->b[0] < pile->b[1])
			swapb(pile);
		while (pile->b[0] < pivot)
		{
			revrotateb(pile);
			printtab(pile);
			getchar();
		}
		printtab(pile);
		getchar();
	}
	pusha(pile);
	while ((pile->b[0] == pivot && pile->bsize) || (pile->bsize > 1 && pile->b[1] == pivot))
	{
		if (pile->b[0] < pile->b[1])
			swapb(pile);
		pusha(pile);
		printtab(pile);
	getchar();
		i++;
		pivot = biggest(pile, 1);
	}
	if (pile->bsize > 0)
		recursivequicksort2(pile);
	return (0);
}

int		recursivequicksort(piles *pile)
{
	int	pivot;
	int	i;
/*partitioning*/
	i = -1;
	pivot = pile->a[pile->asize - 1];
while (!issorted(pile, 0))
{
	pivot = pile->a[pile->asize - 1];
	
printf("Pivot %d\n--------------------------\n", pivot);
	while (pile->a[0] != pivot)
	{
	getchar();
	printtab(pile);
	if (pile->a[0] > pile->a[1])
		swapa(pile);
	while (pile->a[0] < pivot)
	{
		pushb(pile);
		printtab(pile);
		getchar();
	}
	while (pile->a[0] > pivot)	
	{
		rotatea(pile);
		printtab(pile);
		getchar();
	}
	}
}
if (pile->bsize > 0)
{
	recursivequicksort2(pile);
	recursivequicksort(pile);
}
	return (0);
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
getchar();
	
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
