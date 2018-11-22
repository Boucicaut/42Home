#include "get_next_line.h"

int	main(void)
{
	char	**str;
	int		k;
	int		fd;

	str = (char **)malloc(sizeof(char) * 10);
	k = 1;
	fd = open("LIRE", O_RDONLY);	
	while (k == 1)
	{
		k = (get_next_line(fd, str));
		printf("'NL' \n");
		if  (k == -1)
			return (1);
	}
	return (0);
}
