#include "get_next_line.h"

char	*depassement(char **line, int i, int j)
{
	int		diff;
	char	*buf;
	char	*ptr;

	diff = BUFF_SIZE - j;
	j++;
	/* j = 1er byte post \0 */
	if ((buf = malloc((sizeof(char) * diff))) == NULL)
		return (NULL);
	bzero(buf, diff);
	ptr = memccpy(buf, line[i][j], '\n', diff);
	return (buffer);
}
/* GET NEXT LINE WITH MALLOC */
int	get_next_line(const int fd, char **line)
{
	static int	i = -1;
	int			j;
	static char	*buf = NULL;

	j = 0;
	i++;
	if (buf != NULL)
	{	
		if ((line[i] = (char*)malloc(sizeof(char) * BUFF_SIZE * 2 + 1)) == NULL)
			return (-1);
		memccpy(line[i], buf, '\n', 
	}
	else
		if ((line[i] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
			return (-1);
	if ((read(fd, line[i], BUFF_SIZE)) > 0)
	{
		while (line[i][j] != '\n')
		{
			if ((j + 1) == BUFF_SIZE)
				line[i][j] = '\0';		
			j++;
		}
		if (line[i][j] == '\n')
			line[i][j] = '\0';

		while (j < BUFF_SIZE)
		{
			i++;
			buf = depassement(line, i, j);
			if (memchr(buf, 10,  (BUFF_SIZE - j)) == NULL)
		}

		printf("i = %d, %s", i, line[i]);
		return (1);	
	}

	free(line);
	close(fd);
	return (0);
}
