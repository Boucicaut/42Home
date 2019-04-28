#include "pushswap.h"

int	reducerank(t_piles *pile, int w)
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

int	increaserank(t_piles *pile, int w)
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

int	swapb(t_piles *pile, int print)
{
	int	tmp;
	if (pile->bsize < 2)
		return (1);
	if (print)
		ft_printf("sb\n");
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	return (0);
}

int	swapa(t_piles *pile, int print)
{
	int	tmp;
	if (pile->asize < 2)
		return (1);
	if (print)
		ft_printf("sa\n");
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
	return (0);
}

int	swapab(t_piles *pile, int print)
{
	if (print)
		ft_printf("ss\n");
	swapa(pile, 0);
	swapb(pile, 0);
	return (0);
}
