#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <sys/xattr.h>
#include "../libft/libft.h"

/*	listes (-l)
		- noms, blocks, permission, ext attributes, usrid, grpid, size, modified time, last access time */

enum	option	{a, c, f, g, h, l, r, R, t, u};

typedef struct		s_file {
	char			*name;
	uid_t			uid;
	gid_t			gid;
	mode_t			mode;
	time_t			latime;
	time_t			motime;
	blkcnt_t		blocks;
	struct s_file	*next;
}				t_file;

typedef struct		s_dir {
	char			*dirname;
	struct s_file	*info;
	struct s_file	*file;
	struct s_dir	*next;
	struct s_dir	*previous;
	char			permission;	// 1 si ok
}					t_dir;

/*struct				s_treedir {
	char			dirname[256];
	struct s_treedir	*left;
	struct s_treedir	*right;
	struct s_file	file;
}					t_treedir;*/

char	*formatpathfile(char *path, char *file, char *res);
int		isadirectory(char *str);
void	recursivedir(t_dir *first, char *path, t_dir *nextptr);
void	sortargsdir(t_dir *dir);
int ft_listrec(char *file);
int ft_list(char *file);
char* formatdate(char* str, time_t val);
int	ft_inspect(char *file);
char	*cumulativeoptions(char *str);
char	*getoptions(int argc, char **argv);
t_dir	*newelemdir(char *name, t_dir *previous, t_dir *next);
t_dir	*argsdirectories(int argc, char **argv, char optl);
