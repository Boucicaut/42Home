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

int		ft_nextline(char **str, char **line, int nbbytes)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
//ft_printf("newline,  str[fd] %s\n", *str);
	while (str && *str && (*str)[len] && (*str)[len] != '\n')// && str[fd][len] != '\0')
		len++;
//ft_printf("Len : %d | nbbytes %d \n", len, nbbytes);
	if ((*str)[len] == '\n')// && len > 0)  // len > 0 bug sur only \n 
	{
		*line = ft_strnew(len + 1);
		ft_memcpy(*line, *str, sizeof(char) * len);
		tmp = *str;
		*str = ft_strdup((*str) + (len + 1));
		free(tmp);
//ft_printf("\tLine : %s\n", *line);
//ft_printf("\tStr[fd] before return 1 : |%s|\n", *str);
		return (1);
	}
	else if (nbbytes == BUFF_SIZE)
	{
//		ft_printf("Callback\n");
		return (get_next_line(line, str));
	}
	return (0);
}

int		get_next_line(char **line, char **str)
{
	char		buf[BUFF_SIZE + 1];
	int			nbbytes;
	char		*tmp;

	tmp = NULL;
	while ((nbbytes = read(0, buf, BUFF_SIZE)) > 0)
	{
//ft_printf("nbytes : %d\n", nbbytes);
//ft_printf("read : %s\n", buf);
		buf[nbbytes] = '\0';
		if (*str != NULL)
		{
			tmp = *str;
			*str = ft_strjoin(*str, buf);
			free(tmp);
		}
		else
			*str = ft_strdup(buf);
//ft_printf("Str[fd] : %s|\n", str);
		if (ft_strchr(*str, '\n') || ft_strchr(*str, '\0'))
			break ;
	}
//ft_printf("nbytes : %d\n", nbbytes);
	if ((nbbytes == 0 && (*str == NULL)) || (*str[0] == '\0' && 1 >= (int)ft_strlen(*str)))
	{
//free(*line);
//ft_printf("Enddd\n");
		return (0);
	}
	return (ft_nextline(str, line, nbbytes));
}
