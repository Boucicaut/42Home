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
//printf("ss\n");
	swapb(pile);
	swapa(pile);
	return (0);
}
int	pusha(piles *pile)
{
	int	tmp;
/*pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.*/
printf("pa\n");
	if (pile->bsize < 1)
		return (1);
	tmp = pile->b[0];
	increaserank(pile, 0);
	reducerank(pile, 1);
	pile->a[0] = tmp;
	return (0);
}
int	pushb(piles *pile)
{
	int	tmp;
/*pb : push b - prend le premier élément au sommet de a et le met sur b. Ne fait
rien si a est vide.*/
printf("pb\n");
	if (pile->asize < 1)
		return (1);
	tmp = pile->a[0];
	increaserank(pile, 1);
	reducerank(pile, 0);
	pile->b[0] = tmp;
	return (0);
}
int	revrotatea(piles *pile)
{
	int	tmp;
	int	i;
/*rra : reverse rotate a - décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.*/
printf("rra\n");
	tmp = pile->a[pile->asize - 1];
	i = pile->asize - 1;
	while (i-- > 0)
		pile->a[i + 1] = pile->a[i];
	pile->a[0] = tmp;
	return (1);
}
int	revrotateb(piles *pile)
{
	int	tmp;
	int	i;
/*rrb : reverse rotate b - décale d’une position vers le bas tous les élements dela pile b. Le dernier élément devient le premier.*/
printf("rrb\n");
	tmp = pile->b[pile->bsize - 1];
	i = pile->bsize - 1;
	while (i-- > 0)
		pile->b[i + 1] = pile->b[i];
	pile->b[0] = tmp;
	return (1);
}
int	revrotateab(piles *pile)
{
/*rrr : rra et rrb en même temps.*/
//printf("rrr\n");
	revrotatea(pile);
	revrotateb(pile);
	return (0);
}
int	rotatea(piles *pile)
{
	int	tmp;
	int	i;
/*ra : rotate a - décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.*/
printf("ra\n");
	tmp = pile->a[0];
	i = 0;
	while (++i < pile->asize)
	{
		pile->a[i - 1] = pile->a[i];
	}
	pile->a[i - 1] = tmp;
	return (1);
}
int	rotateb(piles *pile)
{
	int	tmp;
	int	i;
/*rb : rotate b - décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.*/
printf("rb\n");
	tmp = pile->b[0];
	i = 0;
	while (++i < pile->bsize)
	{
		pile->b[i - 1] = pile->b[i];
	}
	pile->b[i - 1] = tmp;
	return (1);
}
int	rotateab(piles *pile)
{
/*rr : ra et rb en même temps.*/
printf("rr\n");
	rotatea(pile);
	rotateb(pile);
	return (0);
}

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
		while (i++ < pile->bsize)
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

int		biggestafter(piles *pile, int w, int pivot)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (w == 0)
	{
		j = pile->a[0];
		while (i++ < pile->asize)
		{
			if (pile->a[i] != pivot)
				j = j < pile->a[i] ? pile->a[i] : j;
		}
	}
	else if (w == 1)
	{
		j = pile->b[0];
		while (i++ < pile->bsize)
		{
			if (pile->b[i] != pivot)
				j = j < pile->b[i] ? pile->b[i] : j;
		}
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

int		biggestsorted(piles *pile, int w)
{
	int	i;
	int	j;

	i = pile->a[pile->asize - 1];
	j = 0;
	if (w == 0)
	{
		j = pile->a[pile->asize - 1];
		while (i-- < 0 && j < pile->a[i] && j < biggest(pile, 1))
			j = pile->a[i];
	}
	else if (w == 1)
	{
		i = 0;
		j = pile->b[0];
		while (i++ < pile->bsize && j > pile->b[i] && j < smallest(pile, 0))
			j = pile->b[i];
	}
	return (j);
}

int		rangbiggest(piles *pile, int w)
{
	int	big;
	int	i;

	i = -1;
	big = w == 1 ? biggest(pile, 1) : biggest(pile, 0);
	if (w == 0)
	{
		while (i++ < pile->asize)
			if (pile->a[i] == big)
				return (i);
	}
	else if (w == 1)
	{
		while (++i < pile->bsize)
			if (pile->b[i] == big)
				return (i);
	}
	return (i);
}
