#include "ft_ls.h"

char	*cumulativeoptions(char **str)
{
	str[0][a] = str[0][f] == '1' ? '1' : str[0][a];
	str[0][u] = str[0][t] == '1' ? '1' : str[0][u];
	str[0][t] = str[0][f] == '1' ? '1' : str[0][t];
	str[0][u] = str[0][f] == '1' ? '1' : str[0][u];
	str[0][r] = str[0][f] == '1' ? '1' : str[0][r];
	str[0][h] = str[0][l] == '1' ? '1' : str[0][h];
	return (*str);
}

char	*getoptions(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	str = ft_strdup("0000000000");
	while (i < argc && argv[i][0] == '-')
	{
		j = -1;
		while (argv[i][++j])
		{
			str[a] = argv[i][j] == 'a' ? '1' : str[a];
			str[c] = argv[i][j] == 'c' ? '1' : str[c];
			str[f] = argv[i][j] == 'f' ? '1' : str[f];
			str[g] = argv[i][j] == 'g' ? '1' : str[g];
			str[h] = argv[i][j] == 'h' ? '1' : str[h];
			str[l] = argv[i][j] == 'l' ? '1' : str[l];
			str[r] = argv[i][j] == 'r' ? '1' : str[r];
			str[R] = argv[i][j] == 'R' ? '1' : str[R];
			str[t] = argv[i][j] == 't' ? '1' : str[t];
			str[u] = argv[i][j] == 'u' ? '1' : str[u];
		}
		i++;
	}
	str = cumulativeoptions(&str);
	return (str);
}

t_dir	*argsdirectories(int argc, char **argv)
{
	int		i;
	t_dir	*dir;
	t_dir	*curr;

	i = 1;
	while (i < argc && argv[i][0] == '-')
		i++;
	if (i == argc)
		return (newelemdir(".", NULL, NULL));
	dir = newelemdir(argv[i], NULL, NULL);
	curr = dir->next;
	while (++i < argc)
	{
		curr = newelemdir(argv[i], curr, NULL);
		curr = curr->next;
	}
	return (dir);
}
