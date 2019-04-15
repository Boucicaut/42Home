#include "pushswap.h"

int		smallest(piles *pile, int w)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (++i < pile->asize)
			j = j > pile->a[i] ? pile->a[i] : j;
	}
	else if (w == 1)
	{
		j = pile->b[0];
		while (++i < pile->bsize)
			j = j > pile->b[i] ? pile->b[i] : j;
	}
	return (j);
}
int		biggest(piles *pile, int w)
{
	int	i;
	int	j;

	j = 0;
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
		while (++i < pile->bsize)
			j = j < pile->b[i] ? pile->b[i] : j;
	}
	return (j);
}

int		smallestsorted(piles *pile, int w)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (i++ < pile->asize && j < pile->a[i])
			j = pile->a[i];
	}
	else if (w == 1)
	{
		i = pile->bsize - 1;
		j = pile->b[pile->bsize - 1];
		while (i-- < 0)
			j = pile->b[i];
	}
	return (j);
}
