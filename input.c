#include "fillit.h"

char	**input2(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		if (*str[i] == '\0')
		{
			ft_putchar('Q');
			ft_putnbr(i);
			ft_putchar('\n');
			free(str[i]);
			str[i] = malloc(sizeof(char) * 5);
			ft_bzero(str[i], 5);
		}
		ft_putstr("Z : ");
		ft_putchar(str[i][4]);
		ft_putstr("|\n");
		i++;
	}
	return (str);
}

char	**input(int fd)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**line;
	int		j;

	tmp = NULL;
	if (!(line = malloc(sizeof(char) * 300)))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		j = 0;
		tmp = str;
		if (tmp)
		{
			line[i] = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
	line[i] = NULL;
	return (input2(line));	/* AUCUN LEAKS, CHECK LE 6/12 */
}
