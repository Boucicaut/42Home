/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:37:27 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/16 16:27:07 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				diff;
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	diff = 0;
	if (n == 0)
		return (0);
	while (((*(str1 + i) == *(str2 + i))) && (i < n))
		i++;
	if ((i == n) && (str1[i - 1] == str2[i - 1]))
		return (0);
	return (*(str1 + i) - *(str2 + i));
}
