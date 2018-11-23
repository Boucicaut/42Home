#include "get_next_line.h"
#include "../Libft/libft.h"

int	get_next_line(const int fd, char **line)
{
	static char		*depassement = NULL;
	char			*buf;
	char			*buf2;
	int				i;

	i = 0;
	/* GESTION DU BUFFER AVEC DEPASSEMENT OU PAS + malloc + concat */
	if (depassement != NULL)
	{
		if (((buf = ft_strjoin(buf, depassement)) == NULL))
			return (-1);
		buf[BUFF_SIZE + ft_strlen(depassement)] = '\0'; 
	}
	else
	{	
		if ((buf = malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
			return (-1);
		buf[BUFF_SIZE] = '\0'; 
	}
/*												*/
/* utilisation de buf pour read et buf2 pour cpy car si concat*/
	buf2 = buf;
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		while ((buf[i] != '\n') && (buf[i] != '\0'))
			i++;
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			*line = ft_strsub(buf2, *buf2, i);
			i++;
		}
		depassement = ft_memmove(depassement, &buf[i], (ft_strlen(buf) - i));
		return (1);
	}
	*line = ft_strsub(buf2, *buf2, ft_strlen(buf2));
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
