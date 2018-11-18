/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:03:50 by ademenet          #+#    #+#             */
/*   Updated: 2015/12/16 15:27:42 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbwords(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			i++;
		}
		else if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (i);
}

static int		ft_strlim(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	int		nbword;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nbword = ft_nbwords((char *)s, c);
	tab = (char **)malloc((nbword + 1) * sizeof(char*));
	i = 0;
	if (tab == NULL)
		return (NULL);
	while (nbword-- > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((char *)s, 0, ft_strlim((char *)s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_strlim((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
