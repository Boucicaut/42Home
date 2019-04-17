#include "pushswap.h"

int	main(int argc, char **argv)
{
	piles	*pile;
	int		i;

	i = 0;
	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-i")))
		return (0);
	i = (argc == 3 && !ft_strcmp("-i", argv[1])) ? 1 : 0;
	if (pusherror(argv, argc, i))
	{
		ft_printf("ErrorPS\n");
		return (1);
	}
	if (ft_strcmp(argv[1], "-i") == 0)
		pile = inittabs(argc, argv, 0);
	else
		pile = inittabs(argc, argv, 1);
	gestionrecursive(pile);
	free(pile->a);
	free(pile->b);
	free(pile);
	return (0);
}

int	gestionrecursive(piles *pile)
{
	while (!issorted(pile, 0) || !issorted(pile, 1))
	{
		if (pile->asize < 10)
			sortshortlist(pile);
		while (issorted(pile, 0) == 0)
			quicksort(pile, mediumpivot(pile, 0));
		if (!issorted(pile, 0) || !issorted(pile, 1))
			quicksort2(pile, mediumpivot(pile, 1));
		intermediaire(pile);
		swapornot(pile, 1);
	}
	while (pile->bsize)
	{
		swapornot(pile, 1);
		pusha(pile, 1);
	}
	return (0);
}

int		intermediaire(piles *pile)
{
	while (issorted(pile, 0) && ((pile->bsize && pile->b[0] == biggest(pile, 1)) || (pile->bsize > 1 && pile->b[1] == biggest(pile, 1))))
	{
		swapornot(pile, 1);
		if (pile->b[0] == biggest(pile, 1))
			pusha(pile, 1);
	}
	return (0);
}
