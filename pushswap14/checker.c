#include "pushswap.h"

int	main(int argc, char **argv)
{
	piles	*pile;
	char	*ins;
	int		i;

	ins = ft_strnew(5);
	/* SI ON ENVOIE AUCUN NOMBRE */
	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-i")))
		return (0);
	i = (argc == 3 && !ft_strcmp("-i", argv[1])) ? 1 : 0;
	/* TEST DES CAS D'ERREURS */ /* PARSING SUR LES ARGUMENTS NOMBRE */
	if ((argc == 3 && ft_strcmp(argv[1], "-i")) || pusherror(argv, argc, i))
	{
		ft_printf("ErrorC\n");
		return (0);
	}
	if (strcmp(argv[1], "-i") == 0)
		pile = inittabs(argc, argv, 0);
	else
		pile = inittabs(argc, argv, 1);
	while (get_next_line(0, &ins))
	{
		if (!ft_strcmp("pa", ins))
			pusha(pile);
		else if (!ft_strcmp("pb", ins))
			pushb(pile);
		else if (!ft_strcmp("sa", ins))
			swapa(pile);
		else if (!ft_strcmp("sb", ins))
			swapb(pile);
		else if (!ft_strcmp("ss", ins))
			swapab(pile);
		else if (!ft_strcmp("ra", ins))
			rotatea(pile);
		else if (!ft_strcmp("rb", ins))
			rotateb(pile);
		else if (!ft_strcmp("rr", ins))
			rotateab(pile);
		else if (!ft_strcmp("rra", ins))
			revrotatea(pile);
		else if (!ft_strcmp("rrb", ins))
			revrotateb(pile);
		else if (!ft_strcmp("rrr", ins))
			revrotateab(pile);
		else
		{
			ft_putstr_fd("ErrorCC\n", 2);
			return (0);
		}
	}
	if (issorted(pile, 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(pile);
	free(ins);
	return (1);
}
