#include "pushswap.h"

int	main(int argc, char **argv)
{
	piles	*pile;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-i")))
		return (0);
	i = (argc == 3 && !ft_strcmp("-i", argv[1])) ? 1 : 0;
	if (pusherror(argv, argc, i))
	{
		ft_printf("ErrorPS\n");
		return (1);
	}
	if (strcmp(argv[1], "-i") == 0)
		pile = inittabs(argc, argv, 0);
	else
		pile = inittabs(argc, argv, 1);

	j = gestionrecursive(pile);
	if (!issorted(pile, 0))
		ft_printf("KO !!!!!! KOKOKOKOKOKOK\nKOKOKOKOKOKO\nKOKOKOKOKOKOKO\n");
	free(pile);
	return (0);
}

int	gestionrecursive(piles *pile)
{
	int	nb;

	nb = 0;
	while (!issorted(pile, 0) || !issorted(pile, 1))
	{
		if (pile->asize < 10)
			nb += sortshortlist(pile);
		while (issorted(pile, 0) == 0)
			nb += quicksort(pile, mediumpivot(pile, 0));
		if (!issorted(pile, 0) || !issorted(pile, 1))
			nb += quicksort2(pile, mediumpivot(pile, 1));
		nb += intermediaire(pile);
		nb += swapornot(pile, 1);
	}
	while (pile->bsize)
	{
		nb += swapornot(pile, 1);
		nb++;
		pusha(pile, 1);
	}
	return (nb);
}

int		intermediaire(piles *pile)
{
	int	nb;

	nb = 0;
	while (issorted(pile, 0) && ((pile->bsize && pile->b[0] == biggest(pile, 1)) || (pile->bsize > 1 && pile->b[1] == biggest(pile, 1))))
	{
		nb += swapornot(pile, 1);
		if (pile->b[0] == biggest(pile, 1))
		{
			pusha(pile, 1);
			nb++;
		}
	}
	return (nb);
}
