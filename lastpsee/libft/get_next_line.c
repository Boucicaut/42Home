/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:41:34 by bviollet          #+#    #+#             */
/*   Updated: 2019/05/18 16:26:42 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nextline(char **str, char **line, int fd, int nbbytes)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str && str[fd] && str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str && str[fd] && str[fd][len] && str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		ft_strdel(&str[fd]);
	}
	else if (str && str[fd] && str[fd][len] && str[fd][len] == '\0')
	{
		if (nbbytes == BUFF_SIZE)
			return (get_next_line(fd, line, 0));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line, int i)
{
	static char	*str[200];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			nbbytes;

	if (fd < 0)
		return (-1);
	str[fd] = NULL;
	while ((nbbytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (buf[0] == '\0')
			break ;
		buf[nbbytes] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n') || i++ > 10)
			break ;
	}
	return (gnl(nbbytes, str, fd, line));
}

int		gnl(int nbbytes, char *str[200], int fd, char **line)
{
	if (nbbytes < 0)
		return (-1);
	else if ((nbbytes == 0 && !str[fd]) || (str[fd] && str[fd][0] == '\0'))
	{
ft_printf("End 0\n");
		ft_strdel(&str[fd]);
		return (0);
	}
	return (ft_nextline(str, line, fd, nbbytes));
}
