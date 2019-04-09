#include "pushswap.h"
#include <string.h>

int		countstr(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i++] = ' ')
			k++;
	}
	return (k);
}

char	*deldoublon(char *str)
{
	int	i;
	int	j;
	int	len;

	len = strlen(str);
	while (str[i])
	{
		if (i < len - 6 && !strncmp(str + i, "ra", 2) && !strncmp(str + i, "

	}
	return (str);
}

char	*strrealloc(char *str, char *new)
{
	int		size;
	char	*tmp;

	size = (int)(strlen(str) + strlen(new));
	tmp = (char *)malloc(sizeof(char) * (size + 2));
	tmp = strcpy(tmp, str);
	free(str);
	if (strlen(tmp))
		tmp = strcat(tmp, " ");
	tmp = strcat(tmp, new);
	return (tmp);
}

int	main(int argc, char **argv)
{
	piles	*pile;
	char	*ins;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pile = inittabs(argc, argv, 1);
	ins = malloc(sizeof(char) * (10));
	issorted(pile, 0);


	ins = gestionrecursive(pile, ins);
	printf("%s\n", ins);
	free(ins);
	free(pile);
	return (0);
}

char	*gestionrecursive(piles *pile, char *ins)
{
	int	nb;

	nb = 0;
	/* Gestion recursivite*/
	while (!issorted(pile, 0) || !issorted(pile, 1))
	{
		while (issorted(pile, 0) == 0)
			ins = quicksort(pile, mediumpivot(pile, 0), ins);
		if (!issorted(pile, 0) || !issorted(pile, 1))
			ins = quicksort2(pile, ins);
		ins = intermediaire(pile, ins);
printf("BiggestSorted :   %d -- %d\n", biggestsorted(pile, 0), biggestsorted(pile, 1));
printf("Rang          :   %d -- %d\n", rang(pile, 0,biggestsorted(pile, 0)), rang(pile,1,biggestsorted(pile, 1)));
//getchar();
	}
	while (pile->bsize)
	{
		nb++;
		ins = strrealloc(ins, "pa");
		pusha(pile);
	}
	return (ins);
}

char	*intermediaire(piles *pile, char *ins)
{
	int	nb;

	nb = 0;
	while (issorted(pile, 0) && ((pile->bsize && pile->b[0] == biggest(pile, 1)) || (pile->bsize > 1 && pile->b[1] == biggest(pile, 1))))
	{
		ins = swapornot(pile, 1, ins);
		if (pile->b[1] == biggest(pile, 1))
		{
			ins = swapornot(pile, 1, ins);
			nb++;
		}
		if (pile->b[0] == biggest(pile, 1))
		{
			ins = strrealloc(ins, "pa");
			pusha(pile);
			nb++;
		}
	}
	return (ins);
}
/**********************************************************/
char	*quicksort2(piles *pile, char *ins)
{
	int	pivot;
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	//pivot = pivotb(pile);
	pivot = mediumpivot(pile, 1);
	if (pile->bsize < 40 && pile->asize + pile->bsize < 200)
		ins = petittrib(pile, ins);
	if (pile->bsize < 10)// && pile->asize + pile->bsize < 200)
		ins = petittrib(pile, ins);
	while (biggest(pile, 1) > pivot && pile->bsize && !issorted(pile, 1))
	{
printf("PivotB : %d\n", pivot);
//getchar();
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] == pivot)
		{
			nb += 2;
			ins = strrealloc(ins, "pa");
			pusha(pile);
			if (pile->b[0] < pivot)
			{
				ins = strrealloc(ins, "rrr");
				rotateab(pile);
			}
			else
			{
				ins = strrealloc(ins, "ra");
				rotatea(pile);
			}
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] > pivot)
		{
			nb++;
			ins = strrealloc(ins, "pa");
			pusha(pile);
		}
		if (!issorted(pile, 1) && biggest(pile, 1) >= pivot && pile->b[0] < pivot)
		{
			nb++;
			ins = strrealloc(ins, "rb");
			rotateb(pile);
		}
		ins = swapornot(pile, 1, ins);
	}
	if (pivot == pile->a[pile->asize - 1])
	{
		nb++;
		revrotatea(pile);
		ins = strrealloc(ins, "rra");
	}
	return (ins);
}

char	*quicksort(piles *pile, int pivot, char *ins)
{
	int	nb;

	nb = 0;
	pivot = mediumpivot(pile, 0);
	if (pile->asize < 40 && pile->asize + pile->bsize < 200)
	{
		//getchar();
		ins = petittria(pile, ins);
	}
	else if (pile->asize < 10)// && pile->asize + pile->bsize < 200)
		ins = petittria(pile, ins);
	while (!issorted(pile, 0) && smallest(pile, 0) <= pivot)
	{
printf("PivotA : %d\n", pivot);
//getchar();
		ins = swapornot(pile, 1, ins);
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] == pivot)
		{
			nb += 2;
			pushb(pile);
			rotateb(pile);
			ins = strrealloc(ins, "pb");
			ins = strrealloc(ins, "rb");
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] < pivot)
		{
			nb++;
			pushb(pile);
			ins = strrealloc(ins, "pb");
		}
		if (!issorted(pile, 0) && smallest(pile, 0) <= pivot && pile->a[0] > pivot)
		{
			nb++;
			rotatea(pile);
			ins = strrealloc(ins, "ra");
		}
	}
	if (pile->b[pile->bsize - 1] == pivot)
	{
		ins = swapornot(pile, 1, ins);
		revrotateb(pile);
		ins = strrealloc(ins, "rrb");
		nb++;
	}
	while (pile->a[pile->asize - 1] != biggest(pile, 0))
	{
		if (rang(pile, 0, biggest(pile, 0)) <= pile->asize / 2)
		{
			rotatea(pile);
			ins = strrealloc(ins, "ra");
		}
		else
		{
			revrotatea(pile);
			ins = strrealloc(ins, "rra");
		}
		nb++;
	}
	ins = swapornot(pile, 1, ins);
	return (ins);
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

char	*petittria(piles *pile, char *ins)
{
	int	i;
	int	nb;

	nb = 0;
	i = pile->asize - 1;
	while (!issorted(pile, 0))
	{
getchar();
		ins = swapornot(pile, 1, ins);
		if (!issorted(pile, 0) && pile->a[0] == smallest(pile, 0))
		{
			pushb(pile);
			ins = strrealloc(ins, "pb");
			nb++;
		}
		if (!issorted(pile, 0))
		{
			nb++;
			if (rang(pile, 0, smallest(pile, 0)) < pile->asize / 2)
			{
				ins = strrealloc(ins, "ra");
				rotatea(pile);
			}
			else
			{
				ins = strrealloc(ins, "rra");
				revrotatea(pile);
			}
		}
	}
	return (ins);
}

char	*petittrib(piles *pile, char *ins)
{
	int	i;
	int	nb;

	nb = 0;
	i = pile->bsize - 1;
	while (pile->b[0] != biggest(pile, 1))
	{
getchar();
		if (rang(pile, 1, biggest(pile, 1)) < pile->bsize / 2)
		{
			rotateb(pile);
			ins = strrealloc(ins, "rb");
		}
		else
		{
			ins = strrealloc(ins, "rrb");
			revrotateb(pile);
		}
		nb++;
	}
	pusha(pile);
	ins = strrealloc(ins, "pa");
	return (ins);
}

char	*swapornot(piles *pile, int i, char *ins)
{
	if ((pile->a[0] > pile->a[1] || pile->b[0] < pile->b[1]))
	{
		if (pile->a[0] > pile->a[1] && pile->b[0] < pile->b[1])
		{
			ins = strrealloc(ins, "ss");
			swapab(pile);
		}
		else if (i && pile->a[0] > pile->a[1])
		{
			ins = strrealloc(ins, "sa");
			swapa(pile);
		}
		else if (i && pile->b[0] < pile->b[1])
		{
			ins = strrealloc(ins, "sb");
			swapb(pile);
		}
	}
	return (ins);
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
