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

	printf("LstA\n");
	printf("----  %d -----\n\n", quicksort(pile, pile->a[pile->asize - 1], 1));
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
	int	k;

	nb = 0;
	i = -1;
printf("Biggsort : %d   Smallsort : %d\n\n", biggestsorted(pile, 0), smallestsorted(pile, 0));
	//pivot = pivotb(pile);
	pivot = mediumpivot(pile, 1);
	k = biggestsorted(pile, 1);
if (pile->bsize < 15)
	petittrib(pile);	// TESTER PETIT TRI ***
printf("FIRST Pivot2 : %d || K : %d\n", pivot, k);
//getchar();
	while (k != pile->b[0] && pile->bsize && !issorted(pile, 1))
	{
printf("Pivot2 : %d || K : %d\n", pivot, k);
getchar();
printtab(pile);
		if (pile->b[0] == pivot)
		{
			nb += 2;
			pusha(pile);
			rotatea(pile);
		}
		else if (pile->b[0] > pivot)
		{
			if (issorted(pile, 1) && pile->b[0] > smallest(pile, 0))
				return (nb);
			nb++;
			pusha(pile);
			printtab(pile);
		}
		else if (pile->b[0] < pivot)//le->b[pile->bsize - 1])
		{
			nb++;
			rotateb(pile);
		}
		nb += swapornot(pile);
	}

/*	if (!issorted(pile, 1) && pile->b[0] == k)
	{
		if (pile->b[0] > pivot)
		{
			nb++;
			pusha(pile);
		}
	}*/
	if (pile->a[pile->asize - 1] == pivot)
	{
		nb++;
		revrotatea(pile);
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
if (!issorted(pile, 0) && pile->asize < 15)
	petittria(pile);

pivot = mediumpivot(pile, 0);
k = biggestsorted(pile, 0);

printf("FIRST Pivot : %d || K : %d\n", pivot, k);

	/* tant que k != a[0] ou que 0 est sorted, quicksort*/
	while (k != pile->a[0] && !(issorted(pile, 0)))
	{
printf("Pivot : %d || K : %d\n", pivot, k);
		printtab(pile);
		if (pile->a[0] < pivot)
		{
				nb++;
				pushb(pile);
				printtab(pile);
		}
		else if (pile->a[0] > pivot)
		{
			nb++;
			sens ? rotatea(pile) : revrotatea(pile);
		}
		else if (pile->a[0] == pivot)
		{
			nb += 2;
			pushb(pile);
			revrotateb(pile);
		}
		nb += swapornot(pile);
	}
	sens = sens ? 0 : 1;

		/* Deplacer en haut le pivot qui doit se trouver au top de B*/
	if (pile->b[pile->bsize - 1] == pivot)
	{
		nb++;
		revrotateb(pile);
	}
		/* Si k == pivot, cas particulier */
	/*if (!issorted(pile, 0) && pile->a[0] == k &&)
	{
		pushb(pile);
		nb++;
	}*/
		/* Replacer biggest(0) au top de A*/
	while (biggest(pile, 0) != pile->a[pile->asize - 1])
	{
		nb++;
		nb += swapornot(pile);
		if (rang(pile, 0, biggest(pile, 0)) > pile->asize / 2)
			revrotatea(pile);
		else
			rotatea(pile);
	}
	

	printtab(pile);
	/* Gestion recursivite*/
	while (!issorted(pile, 0) || !issorted(pile, 1))
	{
		printtab(pile);
		printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
		//ici pile->a est trie parfait
		nb += issorted(pile, 0) ? 0 : quicksort(pile, pivota(pile), 1);
/*		while (pile->b[0] == biggest(pile, 1) && pile->bsize)
		{
			nb++;
			pusha(pile);
		}*/
		nb += !issorted(pile, 1) ? quicksort2(pile) : 0;
		//ici pile->a est trie pafait et pile->b pret a etre trie
		printtab(pile);
		printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
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

int		swapornot(piles *pile)
{
	if ((pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1]))
	{
		if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
			swapab(pile);
		else if (pile->a[0] > pile->a[1])
			swapa(pile);
		else if (pile->b[0] < pile->b[1])
			swapb(pile);
		return (1);
	}
	return (0);
}
