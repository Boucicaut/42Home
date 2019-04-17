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
		if (doublonerror2(str))
			return (1);
	return (0);
}

int	doublonerror2(char **str)
{
	int	i;
	int	j;

	i = 0;
	str[2][(int)ft_strlen(str[2]) - 1] = str[2][(int)ft_strlen(str[2]) - 1] == ' ' ? '\0' : str[2][(int)ft_strlen(str[2]) - 1];
	j = str[2][i + 1] ? i + 1 : i;
	while (str[2][i] && i != j)// && str[2][j] && str[2][j + 1])
	{
		while (str[2][i] && str[2][i] == ' ')
			i++;
		j = str[2][i + 1] ? i + 1 : i;
		while (str[2][j] && i < j)// && str[2][j + 1] && str[2][j + 2])
		{
			while (str[2][j] && str[2][j] == ' ')
				j++;
//ft_printf("I(%d) %d, J(%d) %d\n",i, ft_atoi(&str[2][i]), j, ft_atoi(&str[2][j]));
			if (str[2][j] && j > i && ft_atoi(&str[2][j]) == ft_atoi(&str[2][i]))
				return (1);
			if (str[2][j])
				j += ft_qtenb(ft_atoi(&str[2][j]), 'd', 10, 12);
		}
		i += ft_qtenb(ft_atoi(&str[2][i]), 'd', 10, 12);
	}
	return (0);
}

/*int	doublonerror2(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (str[2][i] && str[2][j + 1] && str[2][j + 2])
	{
		while (str[2][i] && str[2][i] == ' ')
			i++;
		j = i + 1;
		while (str[2][j] && str[2][j + 1] && str[2][j + 2])
		{
			while (str[2][j] && str[2][j] == ' ')
				j++;
			if (str[2][j] && j > i + 1 && ft_atoi(&str[2][j]) == ft_atoi(&str[2][i]))
				return (1);
			j += ft_qtenb(ft_atoi(&str[2][j]), 'd', 10, 12);
		}
		i += ft_qtenb(ft_atoi(&str[2][i]), 'd', 10, 12);
	}
	return (0);
}*/
