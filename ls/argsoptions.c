#include "ft_ls.h"

char	*cumulativeoptions(char *str)
{
	str[a] = str[f] == '1' ? '1' : str[a];
	str[u] = str[t] == '1' ? '0' : str[u];
	str[t] = str[f] == '1' ? '0' : str[t];
	str[u] = str[f] == '1' ? '0' : str[u];
	str[r] = str[f] == '1' ? '0' : str[r];
	str[h] = str[l] == '0' ? '0' : str[h];
	return (str);
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
	return (cumulativeoptions(str));
}

t_dir	*argsdirectories(int argc, char **argv, char optl)
{
	int		i;
	t_dir	*dir;
	t_dir	*curr;

	dir = newelemdir("\0", NULL, NULL);
	curr = dir;
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-' && dir->dirname[0])
		{
			while (curr && curr->next)
				curr = curr->next;
			curr->next = newelemdir(argv[i], curr, NULL);
		}
		else if (argv[i][0] != '-')
		{
			free(dir->dirname);
			dir->dirname = ft_strdup(argv[i]);
		}
	}
	if (!(dir->dirname))
		dir->dirname = ft_strcpy(dir->dirname, ".");
	return (dir);
}
