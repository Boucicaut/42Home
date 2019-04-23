#include "pushswap.h"

int	main(int argc, char **argv)
{
	piles	*pile;
	char	*ins;

	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-i")))
		return (0);
	if (pusherror(argv, argc, ((argc == 3 && !ft_strcmp("-i", argv[1])) ? 1 : 0)))
	{
		ft_printf("Error\n");
		return (1);
	}
	pile = !ft_strcmp(argv[1], "-i") ? inittabs(argc, argv, 0) : inittabs(argc, argv, 1);
	ins = ft_strnew(5);
	while (get_next_line(0, &ins))
		if (checkerope(ins, pile))
			return (1);
	if (issorted(pile, 0) && pile->bsize == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freechecker(ins, pile);
	return (0);
}

int	checkerope(char *ins, piles *pile)
{
	if (!ft_strcmp("pa", ins))
		pusha(pile, 0);
	else if (!ft_strcmp("pb", ins))
		pushb(pile, 0);
	else if (!ft_strcmp("sa", ins))
		swapa(pile, 0);
	else if (!ft_strcmp("sb", ins))
		swapb(pile, 0);
	else if (!ft_strcmp("ss", ins))
		swapab(pile, 0);
	else if (!ft_strcmp("ra", ins))
		rotatea(pile, 0);
	else if (!ft_strcmp("rb", ins))
		rotateb(pile, 0);
	else if (!ft_strcmp("rr", ins))
		rotateab(pile, 0);
	else
		return (checkerope2(ins, pile));
	return (0);
}

int	checkerope2(char *ins, piles *pile)
{
	if (!ft_strcmp("rra", ins))
		revrotatea(pile, 0);
	else if (!ft_strcmp("rrb", ins))
		revrotateb(pile, 0);
	else if (!ft_strcmp("rrr", ins))
		revrotateab(pile, 0);
	else
	{
		ft_putstr_fd("Error\n", 2);
		freechecker(ins, pile);
		return (1);
	}
	return (0);
}

int	freechecker(char *ins, piles *pile)
{
	free(ins);
	free(pile->a);
	free(pile->b);
	free(pile);
	return (0);
}
