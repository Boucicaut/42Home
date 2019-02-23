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

void	recursivedir(char *dirpath, char *option)
{
	DIR				*dir;
	struct dirent	*flow;
	t_dir			*curr;
	char			*filepath

	/* NVELLE LL */
	curr = newelemdir(path, NULL, NULL);
	filepath = ft_strnew(256);
	if ((dir = opendir(curr->dirname)))
	{
printf("RRecur, dirname : %s | path : %s\n", curr->dirname, path);
		while ((flow = readdir(dir)))
		{
printf("\t\t\tFormat : curr %s, flow : %s\n", curr->dirname, flow->d_name);
			filepath = formatpathfile(curr->dirname, flow->d_name, path);
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
