#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int i;
	int nb;
	int res;

	res = 1;
	nb = 0;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			res = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
		if ((str[i] < '0') || (str[i] > '9'))
		{
			return (nb * res);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_atoi(argv[1]));
	printf("%d", atoi(argv[1]));
	return (0);
}
