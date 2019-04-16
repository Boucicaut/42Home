#include "pushswap.h"

int	main(int argc, char **argv)
{
	piles	*pile;
	int		i;
	int		j;

	i = 0;
	j = 0;
		/* SI ON ENVOIE AUCUN NOMBRE */
	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-i")))
		return (0);
	i = (argc == 3 && !ft_strcmp("-i", argv[1])) ? 1 : 0;
		/* TEST DES CAS D'ERREURS */ /* PARSING SUR LES ARGUMENTS NOMBRE */
	if (pusherror(argv, argc, i))
	{
		ft_printf("ErrorPS\n");
		return (1);
	}
	if (strcmp(argv[1], "-i") == 0)
		pile = inittabs(argc, argv, 0);
	else
		pile = inittabs(argc, argv, 1);
//getchar();
//printtab(pile);
	//printf("----- %d ----\n", gestionrecursive(pile));

	j = gestionrecursive(pile);
//printtab(pile);
	if (!issorted(pile, 0))
		ft_printf("KO !!!!!! KOKOKOKOKOKOK\nKOKOKOKOKOKO\nKOKOKOKOKOKOKO\n");
//printf("\n%d )\n", j);
	free(pile);
	return (0);
}

int	gestionrecursive(piles *pile)
{
	int	nb;

	nb = 0;
	/* Gestion recursivite*/
	while (!issorted(pile, 0) || !issorted(pile, 1))
	{
		if (pile->asize < 10)
			nb += sortshortlist(pile);
		while (issorted(pile, 0) == 0)
			nb += quicksort(pile, mediumpivot(pile, 0));
		if (!issorted(pile, 0) || !issorted(pile, 1))
			nb += quicksort2(pile);
		nb += intermediaire(pile);
//printtab(pile);
		nb += swapornot(pile, 1);
//printf("BiggestSorted :   %d -- %d\n", biggestsorted(pile, 0), biggestsorted(pile, 1));
//printf("Rang          :   %d -- %d\n", rang(pile, 0,biggestsorted(pile, 0)), rang(pile,1,biggestsorted(pile, 1)));
	}
//getchar();
	while (pile->bsize)
	{
		nb += swapornot(pile, 1);
		nb++;
		pusha(pile, 1);
	}
	return (nb);
}

int		intermediaire(piles *pile)
{
	int	nb;

	nb = 0;
	while (issorted(pile, 0) && ((pile->bsize && pile->b[0] == biggest(pile, 1)) || (pile->bsize > 1 && pile->b[1] == biggest(pile, 1))))
	{
		nb += swapornot(pile, 1);
		if (pile->b[0] == biggest(pile, 1))
		{
			pusha(pile, 1);
			nb++;
		}
	}
	return (nb);
}
/**********************************************************/
int		quicksort2(piles *pile)
{
	int	pivot;
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	//pivot = pivotb(pile);
	pivot = mediumpivot(pile, 1);
	if (pile->bsize < 40 && pile->asize + pile->bsize < 200)
		nb += petittrib(pile);
//printf("||||    %d, %d   \n", biggestsorted(pile, 0), biggestsorted(pile, 1));
//printtab(pile);
//printf("PivotB : %d\n", pivot);
//getchar();
	while (biggest(pile, 1) >= pivot && pile->bsize && !issorted(pile, 1))
	{
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] == pivot)
		{
			pusha(pile, 1);
			nb++;
			if (biggest(pile, 1) > pivot)
			{
				if (pile->b[0] < pivot)
					rotateab(pile, 1);
				else
					rotatea(pile, 1);
				nb++;
			}
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] > pivot)
		{
			nb++;
			pusha(pile, 1);
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] < pivot)
		{
			nb++;
			rotateb(pile, 1); // opti ?
		}
		nb += swapornot(pile, 1);
	}
//printtab(pile);
	if (pivot == pile->a[pile->asize - 1])
	{
		nb++;
		revrotatea(pile, 1); // opti ?
	}
	return (nb);
}

int		quicksort(piles *pile, int pivot)
{
	int	nb;

	nb = 0;
	pivot = mediumpivot(pile, 0);
	if (pile->asize < 25 && pile->asize + pile->bsize < 200)
	{
		//getchar();
		nb += petittria(pile);
	}
	else if (pile->asize < 10)// && pile->asize + pile->bsize < 200)
		nb += petittria(pile);
	while (!issorted(pile, 0) && smallest(pile, 0) <= pivot)
	{
//printtab(pile);
//printf("PivotA : %d\n", pivot);
//getchar();
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] == pivot)
		{
			pushb(pile, 1);
			nb++;
			if (smallest(pile, 0) < pivot) // eviter les doublons rb et rrb
			{
				nb++;
				if (pile->a[0] > pivot) // ICI A CHECKER POUR OPTI ROTAteab
					rotateab(pile, 1);
				else
					rotateb(pile, 1);
			}
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] < pivot)
		{
			nb++;
			pushb(pile, 1);
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] > pivot)
		{
			nb++;
			rotatea(pile, 1);
		}
	}
	if (pile->b[pile->bsize - 1] == pivot)
	{
		nb += swapornot(pile, 1);
		revrotateb(pile, 1);
		nb++;
	}
	while (pile->a[pile->asize - 1] != biggest(pile, 0))
	{
		/*if (rang(pile, 0, biggest(pile, 0)) <= pile->asize / 2)
			rotatea(pile);
		else
			revrotatea(pile);*/
		if (rang(pile, 0, biggest(pile, 0)) < pile->asize / 2)
		{
			if (pile->b[0] < pile->b[1])
				rotateab(pile, 1);
			else
				rotatea(pile, 1);
		}
		else
		{
			if (pile->b[pile->bsize - 1] > pile->b[0])
				revrotateab(pile, 1);
			else
				revrotatea(pile, 1);
		}
		nb++;
	}
	return (nb);
}

int		petittria(piles *pile)
{
	int	i;
	int	nb;

	nb = 0;
	i = pile->asize - 1;
	while (!issorted(pile, 0))
	{
//printtab(pile);
//printf("Tri A\n");
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] == smallest(pile, 0))
		{
			pushb(pile, 1);
			nb++;
		}
		if (!issorted(pile, 0))
		{
			nb++;
			if (rang(pile, 0, smallest(pile, 0)) < pile->asize / 2)
			{
				if (pile->b[0] < pile->b[1])
					rotateab(pile, 1);
				else
					rotatea(pile, 1);
			}
			else
			{
				if (pile->b[pile->bsize - 1] > pile->b[0])
					revrotateab(pile, 1);
				else
					revrotatea(pile, 1);
			}
		}
	}
//getchar();
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
//printtab(pile);
//printf("Tri B\n");
//getchar();
		if (rang(pile, 1, biggest(pile, 1)) < pile->bsize / 2)
			rotateb(pile, 1);
		else
			revrotateb(pile, 1);
		nb++;
	}
	pusha(pile, 1);
	nb++;
	return (nb);
}

int		sortshortlist(piles *pile)
{
	int	pivot;
	int	nb;

	nb = 0;
	if (pile->a[0] == biggest(pile, 0) && pile->a[pile->asize - 1] == biggestafter(pile, 0, biggest(pile, 0)))
	{
		rotatea(pile, 1);
		nb++;
	}
	while (!issorted(pile, 0))
	{
//printtab(pile);
//getchar();
		pivot = mediumpivot(pile, 0);
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] < pivot)
		{
			nb++;
			pushb(pile, 1);
		}
		nb += swapornot(pile, 1);
		if (!issorted(pile, 0) && pile->a[0] > pile->a[pile->asize - 1])
		{
			nb++;
			revrotatea(pile, 1);
		}
		else if (!issorted(pile, 0))
		{
			rotatea(pile, 1);
			nb++;
		}
	}
	while (pile->bsize)
	{
		nb++;
		pusha(pile, 1);
		nb += swapornot(pile, 1);
	}
	return (nb);
}
