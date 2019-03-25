#include <pushswap.h>

int		validargs(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		i++;
	}
	i = -1;
	while (++i < argc)
	{
		j = (int)ft_strlen(argv[i]);
		if (j > 10)
			return (0);
		if ((j > 0 && argv[i][0] > '2' && argv[i][2] <= '9') || (\
			j > 1 && argv[i][1] > '1' && argv[i][2] <= '9') || (\
			j > 2 && argv[i][2] > '4' && argv[i][2] <= '9') || (\
			j > 3 && argv[i][3] > '7' && argv[i][2] <= '9') || (\
			j > 4 && argv[i][4] > '4' && argv[i][2] <= '9') || (\
			j > 5 && argv[i][5] > '8' && argv[i][2] <= '9') || (\
			j > 6 && argv[i][6] > '3' && argv[i][2] <= '9') || (\
			j > 7 && argv[i][7] > '6' && argv[i][2] <= '9') || (\
			j > 8 && argv[i][8] > '4' && argv[i][2] <= '9') || (\
			j > 9 && argv[i][9] > '7' && argv[i][2] <= '9'))
			return (0);
	}
	return (1);
}

int		checkifallvalid(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Ok");
		return (0);
	}
	if (!validargs(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	piles	*pile;
	char	**ins;

	if (!checkifallvalid(argc, argv))
		return (0);
	if (!ft_strcmp(argv[1], "-i"))
		pile = inittabs(argc, argv, 1);
	else
		pile = inittabs(argc, argv, 0);

	if (issorted(pile, 0) && pile->b == 0)
		ft_printf("Ok");
	else
		ft_printf("Ko");

	i = 0;
	ins[0] = ft_strnew(3);
	char	*tmp;
	while (getnextline(1, tmp))
	while (read(1, ins[i], 3))
	{
		i++;
		ins[i] = ft_strnew(3);
	}
/*to be continued*/	
	return (0);
}
