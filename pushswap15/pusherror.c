#include "pushswap.h"

int	pusherror(char **str, int argc, int mode)
{
	int	i;
	int	j;

	if (mode == 1)
		i = 2;
	else
		i = 1;
	while (i < argc)
	{
		/* CHECK VALIDE NB, DIGIT et < INT_MAX */
		j = 0;
		while (str[i][j])
		{
			if (strmaxint(str[i]))
				return (1);
			if ((str[i][j] != ' ' && str[i][j] != '-' && (str[i][j] < '0' || str[i][j] > '9')) || (str[i][j] == '-' && str[i][j + 1] && str[i][j + 1] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	if (doublonerror(str, argc, mode))
		return (1);
	return (0);
}

int	doublonerror(char **str, int argc, int mode)
{
	int	i;
	int	j;

	/* CHECK DOUBLONS */
	i = 1;
	j = i + 1;
	if (mode == 0)
	{
		while (i < argc)
		{
			j = i;
			while (++j < argc)
				if (ft_strcmp(str[i], str[j]) == 0)
					return (1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (str[2][i])
		{
			while (str[2][i] && str[2][i] == ' ')
				i++;
			j = i + 1;
			while (str[2][j])
			{
				while (str[2][j] && str[2][j] == ' ')
					j++;
				if (str[2][j] && j > i + 1 && ft_atoi(&str[2][j]) == ft_atoi(&str[2][i]))
					return (1);
				j += ft_qtenb(ft_atoi(&str[2][j]), 'd', 10, 12);
			}
			i += ft_qtenb(ft_atoi(&str[2][i]), 'd', 10, 12);
		}
	}
	return (0);
}
