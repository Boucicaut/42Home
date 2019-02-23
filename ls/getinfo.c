#include "ft_ls.h"

/*	0 no dir || 1 : dir without per || 2 : dir with per */

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

void	getinfofile(t_file *file)
{
	;
	if (file)
		;
}

void	getinfodir(t_dir *dir)
{
	;
	if (dir)
		;
}
