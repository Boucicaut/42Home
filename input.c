/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:51:43 by bviollet          #+#    #+#             */
/*   Updated: 2018/12/10 18:52:17 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			free(str[i]);
			str[i] = malloc(sizeof(char) * 5);
			ft_bzero(str[i], 5);
		}
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
	return (input2(line));
}
