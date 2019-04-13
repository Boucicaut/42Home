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
		/* TEST DES CAS D'ERREURS */ /* PARSING SUR LES ARGUMENTS NOMBRE */
	if ((argc == 3 && ft_strcmp(argv[1], "-i")) || pusherror(argv, argc))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (strcmp(argv[1], "-i") == 0)
		pile = inittabs(argc, argv, 0);
	else
		pile = inittabs(argc, argv, 1);
//getchar();
	//printf("----- %d ----\n", gestionrecursive(pile));
	gestionrecursive(pile);
	if (issorted(pile, 0))
		printf("ISSORTED OK\n");
printtab(pile);
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
		while (issorted(pile, 0) == 0)
			nb += quicksort(pile, mediumpivot(pile, 0));
		if (!issorted(pile, 0) || !issorted(pile, 1))
			nb += quicksort2(pile);
		//nb += intermediaire(pile);
//printtab(pile);
//printf("BiggestSorted :   %d -- %d\n", biggestsorted(pile, 0), biggestsorted(pile, 1));
//printf("Rang          :   %d -- %d\n", rang(pile, 0,biggestsorted(pile, 0)), rang(pile,1,biggestsorted(pile, 1)));
	}
	while (pile->bsize)
	{
		nb += swapornot(pile, 1);
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
		nb += swapornot(pile, 1);
		if (pile->b[0] == biggest(pile, 1))
		{
			pusha(pile);
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
//printtab(pile);
//printf("PivotB : %d\n", pivot);
//getchar();
	while (biggest(pile, 1) >= pivot && pile->bsize && !issorted(pile, 1))
	{
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] == pivot)
		{
			pusha(pile);
			nb++;
			if (biggest(pile, 1) > pivot)
			{
				if (pile->b[0] < pivot)
					rotateab(pile);
				else
					rotatea(pile);
				nb++;
			}
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
//printtab(pile);
	if (pivot == pile->a[pile->asize - 1])
	{
		nb++;
		revrotatea(pile);
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
			pushb(pile);
			nb++;
			if (smallest(pile, 0) < pivot) // eviter les doublons rb et rrb
			{
				nb++;
				if (pile->a[0] > pivot) // ICI A CHECKER POUR OPTI ROTAteab
					rotateab(pile);
				else
					rotateb(pile);
			}
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
	}
	if (pile->b[pile->bsize - 1] == pivot)
	{
		nb += swapornot(pile, 1);
		revrotateb(pile);
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
				rotateab(pile);
			else
				rotatea(pile);
		}
		else
		{
			if (pile->b[pile->bsize - 1] > pile->b[0])
				revrotateab(pile);
			else
				revrotatea(pile);
		}
		nb++;
	}
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

	//printtab(pile);
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
//printtab(pile);
//printf("Tri A\n");
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
			{
				if (pile->b[0] < pile->b[1])
					rotateab(pile);
				else
					rotatea(pile);
			}
			else
			{
				if (pile->b[pile->bsize - 1] > pile->b[0])
					revrotateab(pile);
				else
					revrotatea(pile);
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
			rotateb(pile);
		else
			revrotateb(pile);
		nb++;
	}
	pusha(pile);
	nb++;
	return (nb);
}

int		swapornot(piles *pile, int i)
{
	if ((pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1]))
	{
		if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
		{
			swapab(pile);
		}
		else if (i && pile->a[0] > pile->a[1])
		{
			swapa(pile);
		}
		else if (i && pile->b[0] < pile->b[1])
		{
			swapb(pile);
		}
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
			if (pile->asize + pile->bsize < 200)
				bigsort = (rang(pile, 0, biggestsorted(pile, 0)) / 1.8); // 100
			else
				bigsort = (rang(pile, 0, biggestsorted(pile, 0)) / 1.2); // 500
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
			if (pile->asize + pile->bsize < 200)
				bigsort = (rang(pile, 1, biggestsorted(pile, 1)) / 1.8); // 100
			else
				bigsort = (rang(pile, 1, biggestsorted(pile, 1)) / 2); // 500
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
