/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:30:54 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/15 14:35:27 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, int start, size_t len)
{
	int		i;
	char	*str;

	str = NULL;
	if (s && (int)len >= 0)
	{
		if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		i = -1;
		while (++i < (int)len)
			str[i] = s[start++];
		str[i] = '\0';
	}
	return (str);
}
