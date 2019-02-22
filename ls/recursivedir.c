#include "ft_ls.h"

/*	0 no dir || 1 : dir without per || 2 : dir with per */

char	*formatpathfile(char *path, char *file, char *res)
{
	int		i;
	int		j;

	j = 0;
	while (res[j])
		res[j++] = '\0';
printf("j %d\n", j);
	i = ft_strlen(path) - 1;
printf("i %d\n", i);
	ft_strcpy(res, path);
	res[i + 1] = res[i] == '/' ? '\0' : '/';
	ft_strcat(res, file);
	j = ft_strlen(res) - 1;
	if (res[j - 1] == '/')
	{
		while (res[j - 1] == '/')
			res[j--] = '\0';
	}
	res[j + 1] = '\0';
printf("res %s\n", res);
	return (res);
}

int		isadirectory(char *str)
{
	struct stat	st;
	DIR			*dir;

printf("isadir ? %s\n", str);
	if (stat(str, &st) >= 0)
		if ((S_IFMT & st.st_mode) == S_IFDIR)
		{
printf("\tis a dir\n");
			if ((dir = opendir(str)))
			{
printf("\t\tis permissioned\n");
				closedir(dir);
				return (2);
			}
			else
			{
				closedir(dir);
				return (1);
			}
		}
printf("\tnot a dir\n");
	return (0);
}

void	recursivedir(t_dir *first, char *path, t_dir *nextptr)
{
	DIR				*dir;
	struct dirent	*flow;
	t_dir			*curr;

	curr = first;
	if ((dir = opendir(curr->dirname)))
	{
printf("RRecur, dirname : %s | path : %s\n", curr->dirname, path);
		while ((flow = readdir(dir)))
		{
printf("\t\t\tFormat : curr %s, flow : %s\n", curr->dirname, flow->d_name);
printf("TESTFORMAT : %s\n", formatpathfile(curr->dirname, flow->d_name, path));
			if (ft_strcmp(flow->d_name, ".") && ft_strcmp(flow->d_name, "..") && isadirectory(formatpathfile(curr->dirname, flow->d_name, path)) == 2)
			{
				//path = formatpathfile(curr->dirname, flow->d_name, path);
printf("\tNewelem valid path : %s\n", path);
				curr->next = newelemdir(formatpathfile(curr->dirname, flow->d_name, path), curr, nextptr);
printf("!!!! : %s\n", curr->next->dirname);
				recursivedir(curr->next, curr->next->dirname, nextptr);
			}
		}
		curr->next = nextptr;
		closedir(dir);
	}
printf("Exit\n");
}

void	swapdirname(t_dir *dir, t_dir *curr)
{
	char	*str;

	str = dir->dirname;
	dir->dirname = curr->dirname;
	curr->dirname = str;
}

void	sortargsdir(t_dir *dir)
{
	t_dir	*curr;
	t_dir	*tmp;

	while (dir && dir->next)
	{
		curr = dir->next;
		while (curr)
		{
			if (isadirectory(dir->dirname) == 0) // si dir envoye en arg est faux ou sans permission
			{
				ft_printf("ft_ls: %s: %s\n", dir->dirname, strerror(errno));
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
}
