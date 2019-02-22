#include "ft_ls.h"

/*	0 no dir || 1 : dir without per || 2 : dir with per */
int		isadirectory(char *file, char *path)
{
	struct stat	st;
	DIR			*dir;
	char		*str;

	str = ft_strnew(ft_strlen(file) + ft_strlen(path) + 2);
	if (path && path[(int)ft_strlen(path) - 1] != '/')
	{
		str = ft_strcat(str, path);
		str = ft_strcat(str, "/");
		str = ft_strcat(str, file);
	}
	else
	{
		str = ft_strcat(str, path);
		str = ft_strcat(str, file);
	}
printf("Str : %s ||file : %s, path : %s\n", str, file, path);
	if (stat(str, &st) >= 0)
		if ((S_IFMT & st.st_mode) == S_IFDIR)
		{
printf("\tis a dir\n");
			if ((dir = opendir(path)))
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
	t_dir			*nextptr;

	curr = first;
	nextptr = curr->next;
	if ((dir = opendir(curr->dirname)))
	{
		if (curr->dirname[ft_strlen(curr->dirname) - 1] != '/')
			path = ft_strcat(curr->dirname, "/");
printf("\trecur, dirname : %s | path : %s\n", curr->dirname, path);
		while ((flow = readdir(dir)))
		{
			if (ft_strcmp(flow->d_name, ".") && ft_strcmp(flow->d_name, "..") && isadirectory(flow->d_name, path) == 2)
			{
printf("\t\trecur, PATHH(2) : %s\n", path);
printf("\t\trecur, flow(2) : %s\n", flow->d_name);
				curr->next = newelemdir(ft_strcat(path, flow->d_name), curr, nextptr);
printf("NEWELEM, dirname : %s\n", curr->next->dirname);
if (nextptr)
	printf("NEWELEM, nextptr : %s\n", nextptr->dirname);
	
				curr = curr->next;
printf("Call recursive with dirname : %s\n", curr->dirname);
				recursivedir(curr, curr->dirname);
				while (curr->next != nextptr)
					curr= curr->next;
	/* ici voir si curr = curr->next while curr->next != nextptr??*/
			}
		}
		closedir(dir);
	}
printf("Exit\n");
}

void	sortargsdir(t_dir *dir)
{
	t_dir	*curr;
	t_dir	*tmp;
	char	*str;

	while (dir && dir->next)
	{
		curr = dir->next;
		while (curr)
		{
			if ((dir->dirname[0] != '/' && dir->dirname[0] != '~' &&
				dir->dirname[0] != '.')
			&& (curr->dirname[0] == '/' || curr->dirname[0] == '~' ||
				dir->dirname[0] == '.'))
			{
				str = dir->dirname;
				dir->dirname = curr->dirname;
				curr->dirname = str;
			}
			curr = curr->next;
		}
		dir = dir->next;
	}
}
