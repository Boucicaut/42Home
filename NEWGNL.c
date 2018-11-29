/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpedro <kpedro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2014/11/20 13:23:19 by kpedro            #+#    #+#             */
/*   Updated: 2014/12/03 19:24:34 by kpedro           ###   ########.fr       */
=======
/*   Created: 2018/11/28 15:34:03 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/28 21:25:23 by bviollet         ###   ########.fr       */
>>>>>>> c0c54c3b7956aebceda55694475d78814fd0fded
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_strlen2(char *s)
{
<<<<<<< HEAD
	int		c;
=======
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
>>>>>>> c0c54c3b7956aebceda55694475d78814fd0fded

	c = 0;
	while (s[c])
	{
<<<<<<< HEAD
		if (s[c] == '\n')
			return (c);
		c++;
=======
		buf[nbbytes] = '\0';
		//printf("Buf : %s\n", buf);
		str = ft_strjoin(str, buf);
>>>>>>> c0c54c3b7956aebceda55694475d78814fd0fded
	}
	return (c);
}

int			get_next_line(int const fd, char **line)
{
	static char	*mem = 0;
	char		buff[BUFF_SIZE + 1];
	int			ret;
	int			i;

<<<<<<< HEAD
	while (!ft_strchr(mem, '\n'))
=======
	if (!(str[fd] = ft_error(fd, line, str)))
		return (-1);
	if (*str[fd])
		*line = ft_strcpy(*line, str[fd]);
	if (!(str[fd] = ft_read(fd, str[fd])))
>>>>>>> c0c54c3b7956aebceda55694475d78814fd0fded
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		mem = ft_strjoin(mem, buff);
		if (ret == 0 && !ft_strchr(mem, '\n'))
		{
			*line = mem;
			return (0);
		}
	}
<<<<<<< HEAD
	i = ft_strlen2(mem);
	if (mem[0] != '\n')
		*line = ft_strsub(mem, 0, i);
	else
		*line = ft_strsub(mem, 1, i);
	mem = mem + i + 1;
	return (1);
=======
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
>>>>>>> c0c54c3b7956aebceda55694475d78814fd0fded
}
