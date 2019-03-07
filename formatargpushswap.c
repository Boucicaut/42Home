#include "pushswap.h"

int	*formatargpushswap(char *arg)
{
	int		*forarg;
	int		i;

	i = -1;
	if (!(forarg = (int*)malloc(sizeof(((int)ft_strlen(arg) + 1) / 2))))
		return (NULL);
	forarg = ft_strnew(((int)ft_strlen(arg) + 1) / 2);
	while (arg[++i])
	{
		if (arg[i] != ' ')
			forarg[i] = ft_atoi(arg[i]);
	}
	return (forarg);
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	len;

	len = (int)ft_strlen((argv[1] + 1)/ 2);
	i = -1;
	tab = formatargpushswap(argv[1]);
	while (i++ < len)
		printf("%d\n", tab[i]);
	return (0);
}
