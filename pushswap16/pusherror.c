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
			if ((mode == 0 && strmaxint(str[i])) || (mode == 1 && j > 0 && str[i][j - 1] != '-' && strmaxint(&str[i][j])) || (mode == 1 && j == 0 && strmaxint(&str[i][j])))
				return (1);
			if ((str[i][j] != ' ' && str[i][j] != '-' && (str[i][j] < '0' || str[i][j] > '9')) || (str[i][j] == '-' && str[i][j + 1] && str[i][j + 1] == '-'))
				return (1);
			if (str[i][j] == '-' && (!str[i][j + 1] || !ft_isdigit(str[i][j + 1])))
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
		while (str[2][i] && (str[2][i] == ' ' || (str[2][i] == '-' && str[2][i + 1] && str[2][i + 1] == '0')))
			i++;
		//j = str[2][i + 1] ? i + 1 : i;
		j = i + ft_qtenb(ft_atoi(&str[2][i]), 'd', 10, 12);
		while (str[2][j] && i < j)// && str[2][j + 1] && str[2][j + 2])
		{
			while (str[2][j] && str[2][j] == ' ')
				j++;
			if (str[2][j] && j > i && ft_atoi(&str[2][j]) == ft_atoi(&str[2][i]))
				return (1);
			if (str[2][j])
			{
				j += ft_qtenb(ft_atoi(&str[2][j]), 'd', 10, 12);
			}
		}
		i += ft_qtenb(ft_atoi(&str[2][i]), 'd', 10, 12);
	}
	return (0);
}
