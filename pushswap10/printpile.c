#include "pushswap.h"

int	printtab(piles *pile)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
//printf("Size :\t\t\t\t\t\t a %d  b %d\n", pile->asize, pile->bsize);
	printf("\t\t    |A|\t\t\t|B|\n");
	while (i < pile->asize || j < pile->bsize)
	{
		if (j < pile->bsize && i < pile->asize)
	printf("\t[%2d] :\t ||  %2d  ||\t\t||  %2d  ||\n", i, pile->a[i], pile->b[i]);
		else if (i < pile->asize)
	printf("\t[%2d] :\t ||  %2d  ||\n", i, pile->a[i]);
		else if (j < pile->bsize)
	printf("\t[%2d] :\t\t\t\t||  %2d  ||\n", i, pile->b[i]);
		i++;
		j++;
	}
	return (0);
}

int	printtabslowmo(piles *pile)
{
	char	*aa;
	char	*bb;
	int		i;

	aa = malloc(sizeof(char) * 100); //ft_strnew
	bb = malloc(sizeof(char) * 100); //ft_strnew
	i = 0;
printf("\n________________________________________________________\n");
	while (i < pile->asize || i < pile->bsize)
	{
	memset(aa, '\0', 100);
	memset(bb, '\0', 100);
		memset(aa, '#', (2 * pile->a[i]));
		memset(bb, '#', (2 * pile->b[i]));
		if (i < pile->bsize && i < pile->asize)
		{
			memset(aa + (2 * pile->a[i]), ' ', (20 - (2 * pile->a[i])));
			memset(bb + (2 * pile->b[i]), ' ', (20 - (2 * pile->b[i])));
			printf("\t[%2d] : %s %s\n", i, aa, bb);
		}
		else if (i < pile->asize)
		{
			memset(aa + (2 * pile->a[i]), ' ', (20 - (2 * pile->a[i])));
			printf("\t[%2d] : %s %s\n", i, aa, bb);
		}
		else if (i < pile->asize)
		{
			memset(bb + (2 * pile->b[i]), ' ', (20 - (2 * pile->b[i])));
			printf("\t[%2d] : %s %s\n", i, aa, bb);
		}
		i++;
	}
printf("________________________________________________________\n");
	free(aa);	
	free(bb);	
	return (0);
}

piles	*inittabs(int argc, char **argv, int mode)
{
	int	i;
	piles	*pile;

	pile = (piles*)malloc(sizeof(piles));
	pile->a = (int*)malloc(sizeof(int) * argc);
	pile->b = (int*)malloc(sizeof(int) * argc);
	pile->a = memset(pile->a, 0, (sizeof(int) * argc));
	pile->b = memset(pile->b, 0, (sizeof(int) * argc));
	pile->asize = argc - 1;
	pile->bsize = 0;
	i = -1;
	if (mode == 1)
		while (++i + 1 < argc)
			pile->a[i] = atoi(argv[i + 1]);
	else
		pile->a = formatargpushswap(argv[i]);
	return (pile);
}

int		issorted(piles *pile, int w)
{
	int	i;
	int	j;

	i = -1;
	if (w == 0)
	{
		j = pile->a[0];
		while (++i < pile->asize)
		{
			if (j > pile->a[i])
				return (0);
			j = pile->a[i];
		}
	}
	else if (w == 1)
	{
		j = pile->b[0];
		while (++i < pile->bsize)
		{
			if (j < pile->b[i])
				return (0);
			j = pile->b[i];
		}

	}
	return (1);
}
