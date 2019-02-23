#include "ft_ls.h"

/*	listes (-l)
		- noms, blocks, permission, ext attributes, usrid, grpid, size, modified time, last access time */

t_dir	*newelemdir(char *name, t_dir *previous, t_dir *next)
{
	t_dir	*new;

	if (!(new = (t_dir*)malloc(sizeof(t_dir))))
	{
		printf("ft_ls: malloc: %s\n", strerror(errno));
		return (NULL);
	}
	new->dirname = ft_strdup(name);
	new->next = next;
	new->previous = previous;
	getinfodir(new);
	return (new);
}

t_file	*newelemfile(char *file, char optl)
{
	t_file	*new;

	if (!(new = (t_file*)malloc(sizeof(t_file))))
	{
		printf("ft_ls: malloc: %s\n", strerror(errno));
		return (0);
	}
	new->name = ft_strdup(file);
	new->next = NULL;
	//getinfo(
(void)optl;
	return (new);
}

void	freeelemdir(t_dir	*dir)
{
	t_dir	*curr;

	while (dir)
	{
		curr = dir;
		dir = dir->next;
		if (curr->file)
			freeelemfile(curr->file);
		if (curr->dirname)
			free(curr->dirname);
		if (curr->info)
			freeelemfile(curr->info);
		free(curr);
	}
}

void	freeelemfile(t_file	*file)
{
	t_file	*curr;

	while (file)
	{
		curr = file;
		file = file->next;
		free(curr);
	}
}
