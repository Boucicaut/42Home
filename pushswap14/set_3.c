#include "pushswap.h"

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
	int	i;
	int	tmp;

printf("rr\n");
	tmp = pile->a[0];
	i = 0;
	while (++i < pile->asize)
	{
		pile->a[i - 1] = pile->a[i];
	}
	pile->a[i - 1] = tmp;

	tmp = pile->b[0];
	i = 0;
	while (++i < pile->bsize)
	{
		pile->b[i - 1] = pile->b[i];
	}
	pile->b[i - 1] = tmp;
	return (0);
}
