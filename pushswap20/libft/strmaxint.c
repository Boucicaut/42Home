#include "libft.h"

int	strmaxint(char *str)
{
	if (ft_strlenspace(str) < 10 || (str[0] == '-' && ft_strlenspace(str) < 11))
		return (0);
//ft_printf("In : %c %c %c %c %c %c \n", str[0], str[1], str[2], str[3], str[4], str[5]);
	if ((str[0] != '-' && ((str[0] && str[0] > '2' && str[0] <= '9') ||
		(str[1] && str[1] > '1' && str[1] <= '9') ||
		(str[2] && str[2] > '4' && str[2] <= '9') ||
		(str[3] && str[3] > '7' && str[3] <= '9') ||
		(str[4] && str[4] > '4' && str[4] <= '9') ||
		(str[5] && str[5] > '8' && str[5] <= '9') ||
		(str[6] && str[6] > '3' && str[6] <= '9') ||
		(str[7] && str[7] > '6' && str[7] <= '9') ||
		(str[8] && str[8] > '4' && str[8] <= '9') ||
		(str[9] && str[9] > '7' && str[9] <= '9'))) ||
	((str[0] && str[0] == '-') &&
		((str[1] && str[1] > '2' && str[1] <= '9') ||
		(str[2] && str[2] > '1' && str[2] <= '9') ||
		(str[3] && str[3] > '4' && str[3] <= '9') ||
		(str[4] && str[4] > '7' && str[4] <= '9') ||
		(str[5] && str[5] > '4' && str[5] <= '9') ||
		(str[6] && str[6] > '8' && str[6] <= '9') ||
		(str[7] && str[7] > '3' && str[7] <= '9') ||
		(str[8] && str[8] > '6' && str[8] <= '9') ||
		(str[9] && str[9] > '4' && str[9] <= '9') ||
		(str[10] && str[10] > '8' && str[10] <= '9'))))
		return (1);
//ft_printf("EndMAXINT\n");
	return (0);
}

int		ft_strlenspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}
