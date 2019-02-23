#include "ft_ls.h"

/*	0 no dir || 1 : dir without per || 2 : dir with per */

char	*formatpathfile(char *path, char *file, char *res)
{
	int		i;
	int		j;

	free(res);
	res = ft_strnew(256);
printf("\tpath %s\n", path);
printf("\tfile %s\n", file);
printf("\tres %s\n", res);
	j = 0;
	while (res[j])
		res[j++] = '\0';
	i = ft_strlen(path) - 1;
	ft_strcpy(res, path);
	res[i + 1] = res[i] == '/' ? '\0' : '/';
	ft_strcat(res, file);
	j = ft_strlen(res) - 1;
	if (res[j - 1] == '/')
	{
		while (res[j] == '/')
			res[j--] = '\0';
	}
printf("fin res %s\n", res);
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

void	recursivedir(t_dir *first, t_dir *nextptr)
{
	DIR				*dir;
	struct dirent	*flow;
	char			*path;
	t_dir			*curr;

	path = ft_strnew(256);
	curr = first;
	if ((dir = opendir(curr->dirname)))
	{
printf("RRecur, dirname : %s | path : %s\n", curr->dirname, path);
		while ((flow = readdir(dir)))
		{
printf("\t\t\tFormat : curr %s, flow : %s\n", curr->dirname, flow->d_name);
			path = formatpathfile(curr->dirname, flow->d_name, path);
printf("path : %s\n", path);
			if (ft_strcmp(flow->d_name, ".") && ft_strcmp(flow->d_name, "..") && isadirectory(path) == 2)
			{
				//path = formatpathfile(curr->dirname, flow->d_name, path);
printf("\tNewelem valid path : %s\n", path);
				curr->next = newelemdir(path, curr, nextptr);
printf("!!!! : %s\n", curr->next->dirname);
				recursivedir(curr->next, nextptr);
		printf("Path aaaaafter : %s|| Cuurr : %s\n", path, curr->dirname);
				while (curr->next != nextptr)
					curr = curr->next;
			}
		}
		curr->next = nextptr;
		closedir(dir);
	}
printf("Exit\n");
printf("\n--------------\n");
while (curr->previous)
	curr = curr->previous;
while (curr->next)
{
	printf("curr dirname : %s\n", curr->dirname);
	curr = curr->next;
}
printf("\n--------------\n");
free(path);
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
