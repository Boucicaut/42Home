/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:34:03 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/28 21:25:23 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static char	*ft_error(int fd, char **line, char *str[100])
{
	if ((fd < 0) || (!line))
		return (NULL);
	if (!str[fd])
		if (!(str[fd] = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (NULL);
	return (str[fd]);
}

static char	**ft_fillline(char **line, char *str, int *i)
{
	*i = 0;
	while ((str[*i]) && (str[*i] != '\n'))
		*i = *i + 1;
	if (*i == 0)
		return (NULL);
		//*line = ft_strdup("");
	else
		*line = ft_strsub(str, 0, *i);
	return (line);
}

static char	*ft_read(const int fd, char *str)
{
	int			nbbytes;
	char		buf[BUFF_SIZE + 1];

	while ((nbbytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nbbytes] = '\0';
		//printf("Buf : %s\n", buf);
		str = ft_strjoin(str, buf);
	}
	if (nbbytes < 0)
		return (NULL);
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[100];
	int			i;

	if (!(str[fd] = ft_error(fd, line, str)))
		return (-1);
	if (*str[fd])
		*line = ft_strcpy(*line, str[fd]);
	if (!(str[fd] = ft_read(fd, str[fd])))
	{
		return (-1);
	}
	//printf("Str : %s\n", str[fd]);
	i = 0;
	if (str[fd][i])
	{
		if (!(line = ft_fillline(line, str[fd], &i)))
			return (0);
		if (i != 0)
			str[fd] = ((str[fd]) + i + 1);
		//printf("Line : %s\n", *line);
		return (1);
	}
	*line = ft_strdup("");
	return (0);
}
