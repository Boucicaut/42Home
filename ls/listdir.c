#include "ft_ls.h"

/*	listes (-l)
		- noms, blocks, permission, ext attributes, usrid, grpid, size, modified time, last access time */

int ft_listrec(char *file)
{
	DIR 			*dir;
	struct dirent	*flow;
	char			*save;
	struct stat		info;

	save = ft_strnew(256);
printf("\nDir : %s\n", file);
	save = ft_strncpy(save, file, 256);
    if (!(dir = opendir(file)))
	{
		printf("Erreur ouverture dir %s\n", file);
		return (0);
	}
    else
	{
		while ((flow = readdir(dir)))
		{
       		if (flow->d_name[0] != '.')
			{
				printf("%s\t", flow->d_name);
				stat(flow->d_name, &info);
				if ((S_IFMT & info.st_mode) == S_IFDIR)
				{
printf("NEWDIR\n");
					printf("%s:\n", flow->d_name);
					ft_listrec(flow->d_name);
				}
			}
		}
		closedir(dir);
	}
free(save);
return (0);
}

int ft_list(char *file)
{
	DIR *dir;
	struct dirent *flow;

printf("File : %s\n", file);
    if (!(dir = opendir(file)))
		printf("Erreur ouverture dir %s\n", file);
    else
	{
		while ((flow = readdir(dir)))
		{
       		if (flow->d_name[0] != '.')
				;
			printf("%s\t", flow->d_name);
			//printf("%d\n", flow->t_ino
		}
	}
closedir(dir);
return (0);
}

char* formatdate(char* str, time_t val)
{
	strftime(str, 36, "%d.%m.%Y %H:%M:%S", localtime(&val));
	return str;
}

int	ft_inspect(char *file)
{
	struct stat 	st;
	//struct timespec *time;
//printf("Sizeof Struct stat : %zu, passwd : %zu, group : %zu\n", sizeof(struct stat), sizeof(struct passwd), sizeof(struct group));
	//if (!(st = (struct stat)malloc(sizeof(struct stat))))
	//	return (0);
//	if (!(time = malloc(sizeof(struct timespec))))
//		return (0);
	if (stat(file, &st) == -1)		// stat(), file info, lstat() about symbolic link
	{
		perror("Stat: file error");
		printf("Erreur : %s\n", strerror(errno));
		return (0);
	}
	else if ((S_IFMT & st.st_mode) == S_IFDIR && !(opendir(file)))
	{
		printf("ft_ls: %s: %s\n", file, strerror(errno)); //dir without permission
		return (0);
	}
	else
	{
		printf("Filename : %s\n", file);
		printf("Device inode : %d\n", st.st_dev);
		printf("Inode's number : %llu\n", st.st_ino);
/*			MODE			*/
		printf("Mode : %d\n", st.st_mode);
		printf("ModeDIR : %d\n", S_IFDIR);
	if ((S_IFMT & st.st_mode) == S_IFDIR)
	{
		printf("Directory\n");
    	if (!(opendir(file)))
		{
			printf("Abort\n");
			printf("ft_ls: %s: %s\n", file, strerror(errno));
			return (0);
		}
	}
	if ((S_IFMT & st.st_mode) == S_IFREG)
		printf("Regular\n");
/*			Uid Gid			*/
struct passwd	*uname;
struct group	*ugroup;
		printf("User ID owner : %u\n", st.st_uid);
uname = getpwuid(st.st_uid);
printf("User name : %s\n", uname->pw_name);
		printf("Group ID owner : %u\n", st.st_gid);
ugroup = getgrgid(st.st_gid);
printf("Group name : %s\n", ugroup->gr_name);
		printf("File size : %lld\n", st.st_size);
/*			Permission		*/
		printf("Permission : %u\t", st.st_mode);
	st.st_mode & S_IRUSR ? printf("r") : printf("-");
	st.st_mode & S_IWUSR ? printf("w") : printf("-");
	st.st_mode & S_IXUSR ? printf("x") : printf("-");
	st.st_mode & S_IRGRP ? printf("r") : printf("-");
	st.st_mode & S_IWGRP ? printf("w") : printf("-");
	st.st_mode & S_IXGRP ? printf("x") : printf("-");
	st.st_mode & S_IROTH ? printf("r") : printf("-");
	st.st_mode & S_IWOTH ? printf("w") : printf("-");
	st.st_mode & S_IXOTH ? printf("x") : printf("-");
			printf("\n");
/*			Blocks, for total -l			*/
		printf("Nb blocks : %lld\n", st.st_blocks);

//time = &st->st_mtimespec;
		//printf("Time : %d\n", time->mknod);

/*			FORMAT DATE				*/
char str[100] = "\0";
		printf("FormTime : %s\n", formatdate(str, st.st_mtime));
		printf("CTime : %s\n", ctime(&st.st_mtime));
		printf("Time : %ld\n", st.st_mtime);

/*			Readlink() get path of symlink	absolute, or readlinkat	*/
char str2[101] = "\0";
		if (readlink("sym", str2, 100) != -1)
			printf("Syn : %s\n", str2);

/*			Get Xattr info, extented attributes		*/
	char	buf[100];
	char	value[100];
		if (listxattr(file, buf, 100, 0)) // XATTR_NOFOLLOW
		{
			getxattr(file, buf, value, 100, 0, 0);
			printf("\nExtAttri : %s - %s\n", buf, value);
		}
	}
	return (0);
}

/*char	*cumulativeoptions(char *str)
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

t_dir	*newelemdir(char *name, t_dir *previous)
{
	t_dir	*new;

	if (!(new = (t_dir*)malloc(sizeof(t_dir))))
	{	
		ft_printf("ft_ls: malloc: %s\n", strerror(errno));
		return (0);
	}
	new->next = NULL;
	new->previous = previous ? previous : NULL;
	new->dirname = ft_strdup(name);
	return (new);
}

t_dir	*argsdirectories(int argc, char **argv, char optl)
{
	int		i;
	t_dir	*dir;
	t_dir	*curr;

	dir = newelemdir("\0", NULL);
	curr = dir;
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-' && dir->dirname[0])
		{
			while (curr && curr->next)
				curr = curr->next;
			curr->next = newelemdir(argv[i], curr);
		}
		else if (argv[i][0] != '-')
		{
			free(dir->dirname);
			dir->dirname = ft_strdup(argv[i]);
		}
	}
	if (!(dir->dirname))
		dir->dirname = ft_strdup(".");
	return (dir);
}*/

int	main(int argc, char **argv)
{
	char	*str;
	t_dir	*dir;

	char	*path;
	str = getoptions(argc, argv);
	dir = argsdirectories(argc, argv, str[l]);
	sortargsdir(dir);
	path = ft_strnew(256);
	path = ft_strcpy(path, dir->dirname);
	if (str[R] == '1')
		recursivedir(dir, path, dir->next);
printf("\nList rec :\n");
while (dir)
{
	ft_printf("Dirname : %s\n", dir->dirname);
	dir = dir->next;
}
	//else
	//	fulfilldir(dir);
printf("\n");

	printf("Options : %s\n", str);
	printf("%20s\n", "acfghlrRtu");
/*
	char *file = strdup(argv[2]);
	ft_list(file);
					printf("\n\n");
	ft_inspect(argv[2]);
printf("\n");
	//ft_listrec(argv[1]);
free(file);*/
	return (0);
}
