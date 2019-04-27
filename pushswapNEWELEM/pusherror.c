#include "pushswap.h"

int	pusherror(char **str, int argc, int mode)
{
	int	i;
	int	j;

	i = mode == 1 ? 2 : 1;
	while (i < argc)
	{
		j = 0;
		while (str[i][j])
		{
			if ((strmaxint(str[i])) || (str[i][j] == '-' && str[i][j + 1] && str[i][j + 1] == '-'))
				return (1);
			while (str[i][j] && str[i][j] == ' ')
				j++;
			if (str[i][j] && str[i][j] != '-' && (str[i][j] < '0' || str[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	doublonerror(piles *pile)
{
	int	i;
	int	j;

	i = -1;
	while (++i < pile->asize)
	{
		j = i;
		while (++j < pile->asize)
			if (pile->a[i] == pile->a[j])
				return (1);
	}
	return (0);
}
/*
	j = i + 1;
	if (mode == 0)
	{
		while (i < argc)
		{
			j = i;
//if ((ft_strcmp(str[i], str[j]) == 0) || (str[j][0] == '0' && ft_strcmp(str[i], str[j + 1])))
			while (++j < argc && str[i] && str[j])
			{
				if (ft_atoi(str[i]) == ft_atoi(str[j]))
					return (1);
			}
			i++;
		}
	}
	else
		if (doublonerror2(str))
			return (1);
	return (0);
}*/

int	doublonerror2(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (str[2][i])
	{
		while (str[2][j])
		{
			while (str[2][j] && str[2][j] != ' ')
				j++;
			if (str[2][j] == ' ')
				j++;
			if (str[2][i] && str[2][j] && ft_atoi(&str[2][i]) == ft_atoi(&str[2][j]))
				return (1);
		}
		while (str[2][i] && str[2][i] != ' ')
			i++;
		if (str[2][i] == ' ')
			i++;
		j = i;
	}
	return (0);
}
