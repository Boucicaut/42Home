#include "pushswap.h"

int	main(int argc, char **argv)
{
	piles	*pile;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pile = inittabs(argc, argv, 1);

int	pivot = 0;
int	nb = 0;
	//nb += quicksort(pile, pile->a[pile->asize - 1]);
while (!issorted(pile, 0) || !issorted(pile, 0))
{
	printtab(pile);
	printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
<<<<<<< HEAD
	pivot = biggest(pile, 0) == pivot ? pile->a[(pile->asize / 2) - 1] : pivot;
	pivot = pile->a[pile->asize / 2];
	pivot = pivota(pile);
	printf("Pivot A : %d\n", pivot);
	while (pile->a[0] == smallest(pile, 0) && pile->asize && !issorted(pile, 0))
	{
		pushb(pile);
		nb++;
	}
	while (!issorted(pile, 0) && pile->a[0] != pivot)
	{
		//getchar();
		printtab(pile);
		nb += quicksort(pile, pivot);
		//nb += quicksort(pile, randompivot(pile, 0));
	}
	while (pile->b[0] == biggest(pile, 1) && pile->bsize && issorted(pile, 0))
	{
		pusha(pile);
		nb++;
	}
	pivot = biggest(pile, 1) == pivot ? pile->b[(pile->bsize / 2) - 1] : pivot;
	pivot = pivotb(pile);
	pivot = pile->b[pile->bsize - 1];
	pivot = pile->b[pile->bsize / 2];
	pivot = pivotb(pile);
=======
	pivot = pile->a[pile->asize / 2];
	pivot = biggest(pile, 0) == pivot ? pile->a[(pile->asize / 2) - 1] : pivot;
pivot = pivota(pile);
		printf("Pivot A : %d\n", pivot);
	while (!issorted(pile, 0) && pile->a[0] != pivot)
	{
		printtab(pile);
		//getchar();
		nb += quicksort(pile, pivot);
		//nb += quicksort(pile, randompivot(pile, 0));
	}
	pivot = pile->b[pile->bsize / 2];
	pivot = biggest(pile, 1) == pivot ? pile->b[(pile->bsize / 2) - 1] : pivot;
pivot = pivotb(pile);
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
	while (!issorted(pile, 1) && pile->b[0] != pivot)
	{
		printtab(pile);
		nb += quicksort3(pile, pivot);
//tmp = pile->b[pile->bsize - 1];
	}
printf("---- %d ----\n", nb);
}
	while (pile->bsize)
	{
		nb++;
		pusha(pile);
	}
	printtab(pile);
printf("______------- %d ------_______\n", nb);
	free(pile);
	return (0);
}

int	mediumpivot(piles *pile, int w) // a faire
//choisir trois valeurs random et prendre la medium
{
	int	i;
	int	j;

	i = 0;
	j = pile->a[0];
	if (w == 1)
	{
		j = j < 0 ? -j : j;
		while (j-- > 0)
		{
			i++;
			if (i + 1 >= pile->asize)
				i = 0;
		}
		return (pile->a[i]);
	}
	if (w == 1)
	{
		j = pile->b[0];
		j = j < 0 ? -j : j;
		while (j-- > 0)
		{
			i++;
			if (i + 1 == pile->bsize)
				i = 0;
		}
		return (pile->b[i]);
	}
	return (0);
}

/**********************************************************/
int		quicksort3(piles *pile, int pivot)
{
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	printf("Sorted? %d %d\n", issorted(pile, 0), issorted(pile, 1));
//getchar();
	if (!issorted(pile, 1) && pile->bsize < 5)
		nb += petittrib(pile);
	if (!issorted(pile, 1))
		canbesortedb(pile);
	//pivot = pivotb(pile);
printf("Pivot2 : %d\n", pivot);
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
<<<<<<< HEAD
		if (pile->b[0] > pivot && !issorted(pile, 1))
=======
		else if (pile->b[0] > pivot && !issorted(pile, 1))
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
		{
			if (issorted(pile, 1))// && pile->b[0] < smallest(pile, 0))
				return (nb);
			nb++;
			pusha(pile);
		}
<<<<<<< HEAD
		if (pile->b[0] < pivot && !issorted(pile, 1))
=======
		else if (pile->b[0] < pivot && !issorted(pile, 1))
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
		{
			nb++;
			if (pile->a[0] > pivot && !issorted(pile, 0))
			{
				rotateab(pile);
			}
			else
				rotateb(pile);
<<<<<<< HEAD
		}
=======
}
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
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
//if (!issorted(pile, 0) && pile->asize < 15) // ????????
//	nb += petittria(pile);
//if (!issorted(pile, 0))
//	canbesorteda(pile);
<<<<<<< HEAD
		if (pile->a[0] < pivot)
		{
			//if (!(issorted(pile, 0)))
		//	{
=======
		if ((pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1]))
		{
			if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
				swapab(pile);
			else if (pile->a[0] > pile->a[1])
				swapa(pile);
			else if (pile->b[0] < pile->b[1])
				swapb(pile);
			nb++;
		}
		else if (pile->a[0] < pivot)
		{
			if (!(issorted(pile, 0)))
			{
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
				nb++;
				pushb(pile);
printtab(pile);
//getchar();
<<<<<<< HEAD
		//	}
		}
		if (pile->a[0] > pivot && !issorted(pile, 0))
=======
			}
		}
		else if (pile->a[0] > pivot && !issorted(pile, 0))
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
		{
			nb++;
			if (pile->b[0] < pile->b[pile->bsize - 1])
				rotateab(pile);
			else
				rotatea(pile);
		}
<<<<<<< HEAD
		if ((pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1]))
		{
			if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
				swapab(pile);
			else if (pile->a[0] > pile->a[1])
				swapa(pile);
			else if (pile->b[0] < pile->b[1])
				swapb(pile);
			nb++;
		}
=======
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
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
<<<<<<< HEAD
	i = pile->asize - 1;
	while (i-- > 0)
	{
	printf("i %d, j %d < pileI %d\n", i, j, pile->a[i]);
getchar();
=======
	i = pile->asize;
	//if (pile->a[0] != biggest(pile, 1))
	//	return (biggest(pile, 0));
	while (i-- > 0)
	{
//getchar();
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
		if (j < pile->a[i])
		{
			//return (j);
// ESSAYER MEME AVEC i-- //
// A VOIR SI ON PEUT FAIRE UN TRUC ENTRE ROTATE ET REVROTATE
// OPTIMISER LES DOUBLES SWAP ET DOUBLE ROTATE POUR LE TRI, LES FAIRE EN M TPS
// CHECKER QUE SI I-- OU I ON NE PASSE PAS SMALLEST DANS L'AFFAIRE
			//getchar();
<<<<<<< HEAD
			if (pile->a[i] != biggest(pile, 0))
				return (j);
				//return (pile->a[i]);
=======
			if (pile->a[i] == biggest(pile, 0))
				return (pile->a[i + 1]);
			return (pile->a[i]);
>>>>>>> 97640848482fd93b328a96300295ab46a61469b8
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
			//getchar();
			return (pile->b[i]);
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
//getchar();
		if (!issorted(pile, 0) && pile->a[0] > pile->a[1])
		{
			if (pile->b[0] < pile->b[1])
				swapab(pile);
			else
				swapa(pile);
			nb++;
		}
		else if (!issorted(pile, 0) && pile->a[0] == smallest(pile, 0))
		{
			pushb(pile);
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

int		canbesortedb(piles *pile)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (i < pile->bsize && pile->b[i] != biggest(pile, 1))
		i++;
	if (!(i < 5 || i + 5 > pile->bsize))
		return (0);
printf("i : %d\n", i);
	//getchar();
	if (i < 5)
	{
		while (pile->b[0] != biggest(pile, 1))
		{
			nb++;
			rotateb(pile);
		}
		pusha(pile);
		return (nb + 1);
	}
	else if (i + 5 > pile->bsize)
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
int		canbesorteda(piles *pile)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (i < pile->asize && pile->a[i] != smallest(pile, 0))
		i++;
	if (!(i < 5 || i + 5 > pile->asize))
		return (0);
	//getchar();
	if (i < 5)
	{
		while (pile->a[0] != smallest(pile, 0))
		{
			nb++;
			rotatea(pile);
		}
		pushb(pile);
		return (nb + 1);
	}
	else if (i + 5 > pile->asize)
	{
		while (pile->a[0] != smallest(pile, 0))
		{
			nb++;
			revrotatea(pile);
		}
		pushb(pile);
		return (nb + 1);
	}
	return (nb);
}
