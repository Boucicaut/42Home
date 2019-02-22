#include "ft_ls.h"

/*	listes (-l)
		- noms, blocks, permission, ext attributes, usrid, grpid, size, modified time, last access time */

t_dir	*newelemdir(char *name, t_dir *previous, t_dir *next)
{
	t_dir	*new;

	if (!(new = (t_dir*)malloc(sizeof(t_dir))))
	{	
		ft_printf("ft_ls: malloc: %s\n", strerror(errno));
		return (NULL);
	}
	new->next = next;
	new->previous = previous;
	new->dirname = ft_strdup(name);
printf("new->dirname : %s\n", new->dirname);
	return (new);
}

t_file	*newelemfile(char *file, char optl)
{
	t_file	*new;

	if (!(new = (t_file*)malloc(sizeof(t_file))))
	{
		ft_printf("ft_ls: malloc: %s\n", strerror(errno));
		return (0);
	}
	new->name = ft_strdup(file);
	new->next = NULL;
	//getinfo(
	return (new);
}
