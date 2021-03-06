#include "pushswap.h"

int	reducerank(piles *pile, int w)
{
	int	i;

	i = 0;
	if (w == 0)
	{
		while (++i < pile->asize)
			pile->a[i - 1] = pile->a[i];
		pile->asize--;
	}
	else if (w == 1)
	{
		while (i++ < pile->bsize)
			pile->b[i - 1] = pile->b[i];
		pile->bsize--;
	}
	return (0);
}

int	increaserank(piles *pile, int w)
{
	int	i;

	i = 0;
	if (w == 0)
	{
		i = pile->asize;
		while (i-- > 0)
			pile->a[i + 1] = pile->a[i];
		pile->asize++;
	}
	else if (w == 1)
	{
		i = pile->bsize;
		while (i-- > 0)
			pile->b[i + 1] = pile->b[i];
		pile->bsize++;
	}
	return (0);
}

int	swapb(piles *pile)
{
	int	tmp;
/*sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.*/
printf("sb\n");
	if (pile->bsize < 2)
		return (1);
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	return (0);
}
int	swapa(piles *pile)
{
	int	tmp;
/*sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.*/
printf("sa\n");
	if (pile->asize < 2)
		return (1);
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
	return (0);
}
int	swapab(piles *pile)
{
/*ss : sa et sb en même temps.*/
	int	tmp;
printf("ss\n");
	if (pile->asize < 2)
		return (1);
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;

	if (pile->bsize < 2)
		return (1);
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	return (0);
}
