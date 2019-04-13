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
	printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
//getchar();
	if (!issorted(pile, 1) && pile->bsize < 25)
		nb += petittrib(pile);
	if (!issorted(pile, 1))
		canbesorted(pile, 0);
	pivot = pivotb(pile);
printf("Pivot2 : %d\n", pivot);
	while (pivot != pile->b[0] && pile->bsize && !(issorted(pile, 1)))
	{
printtab(pile);
printf("Pivot2 : %d\n", pivot);
//getchar();
		if ((pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1]) && !issorted(pile, 1))
		{
			if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
				swapab(pile);
			else if (pile->a[0] > pile->a[1])
				swapa(pile);
			else if (pile->b[0] < pile->b[1])
				swapb(pile);
			nb++;
		}
		if (pile->b[0] > pivot && !issorted(pile, 1))
		{
			if (issorted(pile, 1))// && pile->b[0] < smallest(pile, 0))
				return (nb);
			nb++;
			pusha(pile);
			printtab(pile);
//getchar();
		}
		if (pile->b[0] < pivot && !issorted(pile, 1))
		{
			nb++;
			if (pile->a[0] > pivot && !issorted(pile, 0))
			{
	//			getchar();
				rotateab(pile);
			}
			else
				rotateb(pile);
		}
}
printtab(pile);
	return (nb);
}

int		quicksort(piles *pile, int pivot)
{
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
printf("Pivot : %d\n", pivot);
//getchar();
if (!issorted(pile, 0) && pile->asize < 25) // ????????
	nb += petittria(pile);
	while (pivot != pile->a[0] && !issorted(pile, 0))
	{
printf("Pivot : %d\n", pivot);
		if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
			swapab(pile);
		if (pile->a[0] < pivot)
		{
			if (!(issorted(pile, 0)))
			{
				nb++;
				pushb(pile);
				printtab(pile);
//getchar();
			}
		}
		if (pile->a[0] > pivot && !issorted(pile, 0))
		{
			nb++;
			if (pile->b[0] < pile->b[pile->bsize - 1])
				rotateab(pile);
			else
				rotatea(pile);
		}
		if ((pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1]) && !(issorted(pile, 0)))
		{
			if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
				swapab(pile);
			else if (pile->a[0] > pile->a[1])
				swapa(pile);
			else if (pile->b[0] < pile->b[1])
				swapb(pile);
			nb++;
		}
		printtab(pile);
	//getchar();
	}
while (!issorted(pile, 0) || !issorted(pile, 1))
{
	printtab(pile);
	printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
	nb += issorted(pile, 0) ? 0 : quicksort(pile, pivota(pile));
	nb += pile->bsize ? quicksort2(pile) : 0;
//ici pile->a est trie parfait
while (pile->b[0] == biggest(pile, 1) && pile->bsize)
{
	nb++;
	pusha(pile);
}
//ici pile->a est trie pafait et pile->b pret a etre trie
printtab(pile);
//getchar();
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
	//if (pile->a[0] != biggest(pile, 1))
	//	return (biggest(pile, 0));
	while (i-- > 0)
	{
printf("i %d   j %d   bigb  %d     pilea[i] %d\n", i, j, bigb, pile->a[i]);
//getchar();
		if (j < pile->a[i])
		{
			//return (j);
			printf("ICI ON PREFERE %d a %d\n", pile->a[i], j);
// ESSAYER MEME AVEC i-- //
// A VOIR SI ON PEUT FAIRE UN TRUC ENTRE ROTATE ET REVROTATE
// OPTIMISER LES DOUBLES SWAP ET DOUBLE ROTATE POUR LE TRI, LES FAIRE EN M TPS
// CHECKER QUE SI I-- OU I ON NE PASSE PAS SMALLEST DANS L'AFFAIRE
			//getchar();
			return (pile->a[i]);
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
		if (j > pile->b[i])
		{
			//while (j != pile->b[i])
			//	j = pile->b[i--];
			printf("ICI ON PREFERE %d a %d OU %d ?\n", pile->b[i], j, pile->b[i - 2]);
			//getchar();
			return (pile->b[i]);
		}
		j = pile->b[i];
printf("smaa %d   j %d\n", smaa, j);
	}
	return (pile->b[pile->bsize - 1]);
}

int		petittria(piles *pile)
{
	int	big;
	int	i;
	int	nb;

	nb = 0;
	i = pile->asize - 1;
	big = biggest(pile, 0);
	while (!issorted(pile, 0))
	{
printtab(pile);
//getchar();
		if (pile->a[0] == smallest(pile, 0))
		{
			pushb(pile);
			nb++;
		}
		if (!issorted(pile, 0) && pile->a[0] > pile->a[1])
		{
			if (pile->b[0] < pile->b[1])
				swapab(pile);
			else
				swapa(pile);
			nb++;
		}
		else if (!issorted(pile, 0))
		{
			nb++;
			if (rang(pile, 0, smallest(pile, 0)) < pile->asize / 2)
				rotatea(pile);
			else
				revrotatea(pile);
printtab(pile);
//getchar();
		}
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
		if (!issorted(pile, 1) && pile->b[0] < pile->b[1])
		{
			if (pile->a[0] > pile->a[1])
				swapab(pile);
			else
				swapb(pile);
			nb++;
		}
		else if (!issorted(pile, 1))
		{
			nb++;
			if (rang(pile, 1, smallest(pile, 1)) < pile->bsize / 2)
				rotateb(pile);
			else
				revrotateb(pile);
		}
	}
printtab(pile);
	return (nb);	
}

int		canbesorted(piles *pile, int w)
{
	int	i;
	int	nb;

	w = 1111111111;
	nb = 0;
	i = 0;
	while (i < pile->bsize && pile->b[i] != biggest(pile, 1))
		i++;
	if (!(i < 20 || i + 20 > pile->bsize))
		return (0);
	//getchar();
	if (i < 20)
	{
		while (pile->b[0] != biggest(pile, 1))
		{
			nb++;
			rotateb(pile);
		}
		pusha(pile);
		return (nb + 1);
	}
	else if (i + 20 > pile->bsize)
	{
		while (pile->b[0] != biggest(pile, 1))
		{
			nb++;
			revrotateb(pile);
		}
		pusha(pile);
		return (nb + 1);
	}
	return (nb);
}
