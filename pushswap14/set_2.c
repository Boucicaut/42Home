#include "pushswap.h"

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
	int	i;
	int	tmp;
/*rrr : rra et rrb en même temps.*/
printf("rrr\n");
	tmp = pile->a[pile->asize - 1];
	i = pile->asize - 1;
	while (i-- > 0)
		pile->a[i + 1] = pile->a[i];
	pile->a[0] = tmp;


	tmp = pile->b[pile->bsize - 1];
	i = pile->bsize - 1;
	while (i-- > 0)
		pile->b[i + 1] = pile->b[i];
	pile->b[0] = tmp;
	return (0);
}
