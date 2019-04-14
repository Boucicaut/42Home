#include "pushswap.h"

int	pusherror(char **str, int argc)
{
	int	i;
	int	j;

	if (argc == 3)
		i = 2;
	else
		i = 1;
	j = 0;
	while (i < argc)
	{
		/* CHECK VALIDE NB, DIGIT et < INT_MAX */
		while (str[i][j])
		{
			if (strmaxint(str[i]))
				return (1);
			if (str[i][j] != ' ' && str[i][j] != '-' && (str[i][j] < '0' || str[i][j] > '9'))
				return (1);
			j++;
		}
		j = i;
		/* CHECK DOUBLONS */
		while (++j < argc)
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
		j = 0;
		i++;
	}
	return (0);
}
