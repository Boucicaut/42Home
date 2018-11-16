/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:27:33 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/15 18:20:20 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	int		sst;
	char	*str;

	j = 0;
	sst = 0;
	while ((s[sst] == ' ') || (s[sst] == '\n') || (s[sst] == '\t'))
		sst++;
	i = ft_strlen(s);
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t') || (s[i] == '\0'))
		i--;
	if (i <= 0)
	{
		if ((str = (malloc(sizeof(char) * 1))) == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if ((str = (malloc(sizeof(char) * (i - sst + 2)))) == NULL)
		return (NULL);
	while (sst <= i)
		str[j++] = s[sst++];
	str[j] = '\0';
	return (str);
}
