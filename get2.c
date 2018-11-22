#include "get_next_line.h"

char	**ft_cpBufLine(int i, char **line, char **buf)
{
	int	j;

	j = 0;
	while (buf[i] != NULL)
		memcpy(line[i], buf[j], BUFF_SIZE);
		i++;

}

int		ft_isspace(char *buf)
{
	int	j;

	while ((j > BUFF_SIZE) && (buf[j] != '\n'))
		j++;
	if (buf[j] == '\n')
		return (1);
	else
		return (0);
}

int		ft_rebuf(char **buf)
{
	char	**buf;
	int		i;

	i = 0;	
	while (ft_isspace(buf) == 0)
	{
		if ((buf[i] = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
			return (-1); // RETURN ?
		if ((read(fd, buf[i], BUFF_SIZE)) == NULL)
			return (-1);
		memcpy(BUFF_SIZE)
	i++;

	check si \n ...		


	}
	return (i);
}

int		ft_nbmallocline(char **buf)
{
	int	j;

	j = 0;
	while ((buf[j] != '\n') && (j < BUFF_SIZE))
		j++;
	if (buf[j] == '\n')
		buf[j] = '\0';
	else
		j = j + ft_rebuf();
	return (j);	
}

int	get_next_line(const int fd, char **line)
{
	static int	i = -1;
	int			j;
	char		**buf;
	int			tailleMalloc;

	j = 0;
	i++;

	tailleMalloc = ft_nbmallocline(buf);

	if ((line[i] = malloc(sizeof(char) * tailleMalloc)) == NULL)
		return (-1);
	
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
