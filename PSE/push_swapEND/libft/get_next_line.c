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
	while (str && str[fd] && str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (ft_strchr(str[fd] + len, '\n'))
		while (str[fd][len] != '\n')
			len++;
	if (str && str[fd] && str[fd][len] && ((str[fd][len] == '\n') || (str[fd][len] == '\0')))
	{
		if (str[fd][0] != '\n' && str[fd][len] && str[fd][len] == '\n')
		{
			ft_printf("strnew \n");
			*line = ft_strnew((int)ft_strlen(str[fd]) - (int)ft_strlen((char*)ft_strchr(str[fd], '\n')));
		}
		else if (str[fd][len] && (str[fd][len] == '\0'))
		{
ft_printf("00l\n");
			*line = ft_strdup("a");
			return (1);
		}
ft_printf("nnl\n");
		//*line = ft_strnew((int)ft_strlen(str[fd]) - (int)ft_strlen((char*)ft_strchr(str[fd], '\0')));
		//if (!(nbbytes == 1 && str[fd][0] == '\n'))
			ft_memcpy(*line, str[fd], nbbytes);
		tmp = str[fd];
		str[fd] = ft_strdup(str[fd] + len + 1);
		free(tmp);
	}
	else
	{
		if (nbbytes == BUFF_SIZE)
			return (get_next_line(fd, line));
		//*line = ft_strdup("shit");
//free(*line);
		//ft_strdel(&str[fd]);
	}
		ft_strdel(&str[fd]);
	return (1);
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
