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
//	sortrotatepush(pile);

/*si biggestA et dans la premiere moitie envoye biggestA sinon PivA*/

	printf("----  %d -----\n\n", quicksort(pile, pile->a[pile->asize - 1]));
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

/**********************************************************/
int		quicksort2(piles *pile)
{
	int	pivot;
	int	i;
	int	nb;

	nb = 0;
	i = -1;
printf("Biggsort : %d   Smallsort : %d\n\n", biggestsorted(pile, 0), smallestsorted(pile, 0));
	pivot = pivotb(pile);
printf("Pivot2 : %d\n", pivot);
	while (pivot != pile->b[0] && pile->bsize)
	{
printtab(pile);
printf("Pivot2 : %d\n", pivot);
//getchar();
		while (pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1])
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
			nb++;
			if (pile->b[0] > ((biggest(pile, 1) - smallest(pile, 1)) / 2))
				pusha(pile);
			else
				rotateb(pile);
				//swapb(pile);
			printtab(pile);
//getchar();
		}
		if (pile->a[0] > pile->a[pile->asize - 1] && pile->b[0] < pile->b[pile->bsize - 1])
		{
			rotateab(pile);
			nb++;
		}
		if (pile->b[0] < pivot)//pile->b[pile->bsize - 1])
		{
			nb++;
			rotateb(pile);
		}
		printtab(pile);
//getchar();
	}
//while (issorted(pile, 1) == 0)
//	nb += quicksort2(pile);
		return (nb);
}

int		quicksort(piles *pile, int pivot)
{
	int	i;
	int	nb;

	nb = 0;
/*partitioning*/
	i = -1;
printf("Pivot : %d\n", pivot);
//getchar();
	//while (pivot != pile->a[0] && (!((issorted(pile, 0) && pile->bsize == 0))))
	//while (pivot != pile->a[0] && issorted(pile, 0) == 0 && pile->a[0] > biggest(pile, 1))
	while (pivot != pile->a[0] && (!((issorted(pile, 0) && pile->a[0] > biggest(pile, 1)) && pile->bsize)))
	{
printf("Pivot : %d\n", pivot);
//getchar();
		if (pile->a[0] < pivot)
		{
			if (!(issorted(pile, 0) && smallest(pile, 0) > biggest(pile, 1)))
			{
				nb++;
				pushb(pile);
				printtab(pile);
//getchar();
			}
		}
		if (pile->a[0] > pivot)
		{
			nb++;
			if (pile->b[0] < pile->b[pile->bsize - 1])
				rotateab(pile);
			else
				rotatea(pile);
		}
		if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
		{
			nb++;
			swapab(pile);
		}
		else if (pile->a[0] > pile->a[1])
		{
			nb++;
			swapa(pile);
		}
		else if (pile->b[0] < pile->b[1]) //eessai ici enlever else
		{
			nb++;
			swapb(pile);
		}
		printtab(pile);
	}

while (!issorted(pile, 0) || !issorted(pile, 1))
{
	printtab(pile);
	printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
	nb += issorted(pile, 0) && pile->a[0] > biggest(pile, 1) ? 0 : quicksort(pile, pivota(pile));
//ici pile->a est trie parfait
while (pile->bsize && pile->b[0] == biggest(pile, 1))
{
	nb++;
	pusha(pile);
}
//ici pile->a est trie pafait et pile->b pret a etre trie
printtab(pile);
//getchar();
	nb += pile->bsize ? quicksort2(pile) : 0;
	printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
}
printtab(pile);
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
printf("i %d   j %d   bigb  %d     pilea[i] %d\n", i, j, bigb, pile->a[i]);
//getchar();
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
	i = pile->bsize - 1;
	while (i-- > 0)
	{
		if (pile->bsize == 1 || (pile->b[0] < smaa && issorted(pile, 1)))
			return (pile->b[0]);
// si j > pile->b[i] || pile->b[i] > smallest after i
		if (j > pile->b[i] || smallestafter(pile, 1, i) == 0) // tester ici j> smaa (j < smaa et l'enlever)
			return (j);
		j = pile->b[i];
printf("smaa %d   j %d\n", smaa, j);
	}
	return (pile->b[pile->bsize - 1]);
}

int	smallestafter(piles *pile, int w, int rang)
{
	int	i;
	int	j;

	i = rang;
	if (w == 1)
	{
		j = pile->b[rang];
		while (i-- > 0)
			if (j > pile->b[i])
				return (0);
	}
	return (1);
}
