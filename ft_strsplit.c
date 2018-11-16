/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:17:00 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/16 16:03:04 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbmot(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i - 1] != c) && (i != 0))
			j++;
		i++;
		if ((s[i] == '\0') && (s[i - 1] != c))
			j++;
	}
	return (j);
}

static char		**lgmot(const char *s, char c, char **str, int j)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while ((s[i] != c) && (s[i++] != '\0'))
		{
			j++;
		}
		if (i != 0)
			if ((s[i] == c) || (s[i] == '\0'))
			{
				if ((str[k++] = (char *)malloc(sizeof(char) * j + 1)) == NULL)
					return (0);
			}
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
	}
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	char	**str;
	int		j;
	int		k;

	j = nbmot(s, c);
	if ((str = (char **)malloc(sizeof(char*) * (j + 1))) == NULL)
		return (NULL);
	str[j] = 0;
	str = lgmot(s, c, str, j);
	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		k = 0;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			str[j][k++] = s[i++];
		}
		if (i != 0)
			str[j++][k] = '\0';
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
	}
	return (str);
}
