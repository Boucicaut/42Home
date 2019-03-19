#include "pushswap.h"
#include <string.h>
#include <stdlib.h>

int	*formatargpushswap(char *arg)
{
	int		*forarg;
	int		i;

printf("%s\n", arg);
	i = -1;
	if (!(forarg = (int*)malloc(sizeof(((int)strlen(arg) + 1) / 2))))
		return (NULL);
	while (arg[++i])
	{
		if (arg[i] != ' ')
			forarg[i] = atoi(&arg[i]);
	}
i = -1;
while (++i < (int)strlen(arg))
	printf("%d ", forarg[i]);
	return (forarg);
}

/*
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
}*/
