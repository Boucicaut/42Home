/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:41:34 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/27 18:02:57 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nextline(char **str, char **line, int fd, int nbbytes)
{
	char	*tmp;
	int		len;

	len = 0;
ft_printf("newline\n");
	while (str && str[fd] && str[fd][len] != '\n')// && str[fd][len] != '\0')
		len++;
	if (len > 0)
	{
	*line = ft_strnew(len);
	ft_memcpy(*line, str[fd], nbbytes);
	tmp = str[fd];
	str[fd] = ft_strdup(str[fd] + len + 1);
	free(tmp);
ft_printf("\tLine : %s\n", *line);
	return (1);
	}
	else if (nbbytes == BUFF_SIZE)// && str[fd] && !(str[fd][len] == '\0' || str[fd][len] == '\n'))
		return (get_next_line(fd, line));
ft_printf("ret 0\n");
	ft_strdel(&str[fd]);
	str[fd] = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[200];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			nbbytes;

	if ((fd < 0))// || (!line))
		return (-1);
	while ((nbbytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
ft_printf("nbytes : %d\n", nbbytes);
ft_printf("read : %s\n", buf);
		buf[nbbytes] = '\0';
		if (str[fd] != NULL)
		{
			tmp = str[fd];
			str[fd] = ft_strjoin(str[fd], buf);
			free(tmp);
		}
		else
			str[fd] = ft_strdup(buf);
ft_printf("Str[fd] : %s|\n", str[fd]);
		if (ft_strchr(buf, '\n') || ft_strchr(buf, '\0'))
			break ;
	}
ft_printf("nbytes : %d\n", nbbytes);
	if ((nbbytes == 0 && (str[fd] == NULL)) || (str[fd][0] == '\0' && 1 >= (int)ft_strlen(str[fd])))
	{
//free(*line);
ft_printf("Enddd\n");
		ft_strdel(&str[fd]);
		return (0);
	}
	return (ft_nextline(str, line, fd, nbbytes));
}
