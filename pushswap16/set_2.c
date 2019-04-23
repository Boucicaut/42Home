#include "pushswap.h"

int	pusha(piles *pile, int print)
{
	int	tmp;
	if (pile->bsize < 1)
		return (1);
	if (print)
		ft_printf("pa\n");
	tmp = pile->b[0];
	increaserank(pile, 0);
	reducerank(pile, 1);
	pile->a[0] = tmp;
	return (0);
}

int	pushb(piles *pile, int print)
{
	int	tmp;
	if (pile->asize < 1)
		return (1);
	if (print)
		ft_printf("pb\n");
	tmp = pile->a[0];
	increaserank(pile, 1);
	reducerank(pile, 0);
	pile->b[0] = tmp;
	return (0);
}

int	revrotatea(piles *pile, int print)
{
	int	tmp;
	int	i;

	if (pile->asize < 2)
		return (0);
	if (print)
	if (print)
		ft_printf("rra\n");
	tmp = pile->a[pile->asize - 1];
	i = pile->asize - 1;
	while (i-- > 0)
		pile->a[i + 1] = pile->a[i];
	pile->a[0] = tmp;
	return (1);
}

int	revrotateb(piles *pile, int print)
{
	int	tmp;
	int	i;

	if (pile->bsize < 2)
		return (0);
	if (print)
		ft_printf("rrb\n");
	tmp = pile->b[pile->bsize - 1];
	i = pile->bsize - 1;
	while (i-- > 0)
		pile->b[i + 1] = pile->b[i];
	pile->b[0] = tmp;
	return (1);
}

int	revrotateab(piles *pile, int print)
{
	if (print)
		ft_printf("rrr\n");
	revrotatea(pile, 0);
	revrotateb(pile, 0);
	return (0);
}
