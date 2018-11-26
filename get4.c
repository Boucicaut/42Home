#include "get_next_line.h"
#include "../Libft/libft.h"
#include <stdio.h>

	/* pour le multi fd, try un tab de depassement et stocker l'excedent dans depass[fd] */

int	get_next_line(const int fd, char **line)
{
	static char		*depassement = NULL;
	char			*buf;
	int				i;
	char			*buf2;

	i = 0;
	/* GESTION DU BUFFER AVEC DEPASSEMENT OU PAS + malloc + concat */
	if (depassement)
	{
		printf("?? : %s \n", depassement);
		if (!(buf = ft_strdup(depassement)))
			return (-1);
		printf("strlen(buf) = %d\n", (int)strlen(buf));
		buf2 = (buf + strlen(buf));
		printf("buf2 = %s\n", buf2);
		printf("!! %s\n", buf);
		/* pas de '\0', deja mis par strjoin */
	}
	else
	{
		if (!(buf = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		buf2 = buf;
		/*if (buf = malloc(sizeof(char) * BUFF_SIZE + 1))
			return (-1);*/
		/*buf[BUFF_SIZE] = '\0';	init \0 partout */
	}
/* utilisation de buf pour read et buf2 pour cpy car si concat*/
	if (read(fd, buf2, BUFF_SIZE) > 0)
	{
		while ((buf[i]) && (buf[i] != '\n'))
			i++;
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			i++;
			printf("!! buf = %s\n", buf);
			printf("%d = I ()\n", i);
			if (!line[0])
			{
				write(1, "w", 1);
				free (line[0]);
			}
			line[0] = ft_strsub(buf, 0, i);
		write(1, "Z", 1);
			line[0][i] = '\0';
		}
		printf("STRLEN BUF de i %zu\n", strlen(&buf[i]));
		printf("%zu - (i)%d -- ", ft_strlen(&(*(buf + i))), i);
		printf("buf[i] : %c\n", buf[i]);

		if (!depassement) /* ligne rajoute hier soir*/
			if (!(depassement = malloc(sizeof(char) * 60))) /* chg 60 */
				return (-1);
		depassement = (char *)ft_memcpy(depassement, &buf[i], ((BUFF_SIZE - (i - 1))));
		/*ft_strsub(buf, i, (BUFF_SIZE - i));*/
		/*depassement = ft_strcpy(depassement, &buf[i]);*/

		printf("buf = %s\n", buf);
		printf("line = %s\n", line[0]);
		printf("depa = %s\n", depassement);
		free (buf);
		return (1);
	}
	printf("SHORT WAY, FINAL");
	line[0] = ft_strsub(buf, buf[0], ft_strlen(buf));
	printf("buf = %s\n", buf);
	printf("line = %s\n", line[0]);
	printf("depa = %s\n", depassement);
	free (buf);
	free (depassement);
	return (0);
}

/*
si buf == \n
	buf2 = &(\n) de buf
	*line = buf jusqua buf2
	depassement = buf2 avec length (BUFF_SIZE - (buf2 - buf))
	free (buf) (buf2)

	si depassement != NULL;
		
	
si buf != \n
	malloc (depassement)
	read(fd, buf, BUFF_SIZE)
*/
