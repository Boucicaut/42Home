#include "pushswap.h"

int	printtab(piles *pile)
{
	int	i;
	int	j;

	j = pile->bsize - 1;
	i = pile->asize - 1;
	ft_printf("\t\t    |A|\t\t\t|B|\n");
	while (i >= 0 || j >= 0)
	{
		if (j >= 0 && i >= 0)
			ft_printf("\t[%2d] :\t ||  %2d  ||\t\t||  %2d  ||\n", i, pile->a[i], pile->b[j]);
		else if (i >= 0)
			ft_printf("\t[%2d] :\t ||  %2d  ||\n", i, pile->a[i]);
		else if (j >= 0)
			ft_printf("\t[%2d] :\t\t\t\t||  %2d  ||\n", j, pile->b[j]);
		i--;
		j--;
	}
	return (0);
}

piles	*inittabs(int argc, char **argv, int mode)
{
	int	i;
	int	j;
	piles	*pile;

	if (!(pile = (piles*)malloc(sizeof(piles))))
		exit (1);
	j = 0;
	i = -1;
	if (mode == 1)
	{
		pile->a = (int*)malloc(sizeof(int) * argc);
		pile->b = (int*)malloc(sizeof(int) * argc);
		pile->a = memset(pile->a, 0, (sizeof(int) * argc));
		pile->b = memset(pile->b, 0, (sizeof(int) * argc));
		pile->asize = argc - 1;
		pile->bsize = 0;
		while (++i + 1 < argc)
			pile->a[i] = atoi(argv[i + 1]);
	}
	else if (argc > 2)
		inittabs2(argv, pile);
	return (pile);
}

piles	*inittabs2(char **argv, piles *pile)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (++i < (int)ft_strlen(argv[2]))
		if (argv[2][i] != ' ' && i > 0 && argv[2][i - 1] == ' ')
			j++;
	j += j > 0 ? 1 : 0;
	pile->a = (int*)malloc(sizeof(int) * j);
	pile->b = (int*)malloc(sizeof(int) * j);
	pile->a = memset(pile->a, 0, (sizeof(int) * j));
	pile->b = memset(pile->b, 0, (sizeof(int) * j));
	pile->asize = j;
	pile->bsize = 0;
	i = 0;
	j = 0;
	while (argv[2][i])
	{
		if (argv[2][i] == ' ')
			i++;
		else
		{
			pile->a[j] = ft_atoi(&(argv[2][i]));
			i += ft_qtenb(pile->a[j++], 'd', 10, 10);
		}
	}
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
