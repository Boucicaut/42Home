#include "ft_ls.h"

/*	0 no dir || 1 : dir without per || 2 : dir with per */

void	swapdirname(t_dir *dir, t_dir *curr)
{
	char	*str;

	str = dir->dirname;
	dir->dirname = curr->dirname;
	curr->dirname = str;
}

void	sortargsdir(t_dir *dir, char *str)
{
	t_dir	*curr;
	t_dir	*tmp;

	if (str[t] == '1')
		;
	while (dir && dir->next)
	{
		curr = dir->next;
		while (curr)
		{
			if (isadirectory(dir->dirname) == 0) // si dir envoye en arg est faux ou sans permission
			{
				printf("ft_ls: %s: %s\n", dir->dirname, strerror(errno));
				dir->dirname[0] = '\0';
			}
			if (ft_strcmp(dir->dirname, ".") && !(ft_strcmp(curr->dirname, ".")))
				swapdirname(dir, curr);
			else if ((dir->dirname[0] != '/' && dir->dirname[0] != '~' &&
				dir->dirname[0] != '.')
			&& (curr->dirname[0] == '/' || curr->dirname[0] == '~' ||
				dir->dirname[0] == '.'))
				swapdirname(dir, curr);
			curr = curr->next;
		}
		dir = dir->next;
	}
(void)tmp;
}
