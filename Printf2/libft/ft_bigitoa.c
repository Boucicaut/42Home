/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:53:30 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/17 17:52:35 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*bigpositive(long long int n, char *nb)
{
	int				i;
	long long int	n2;

	i = 0;
	while (n > 0)
	{
		n2 = n;
		while (n2 > 10)
			n2 /= 10;
		nb[i++] = (n2 % 10) + '0';
		while (n2 < n)
			n2 *= 10;
		if (n2 > n)
			n2 /= 10;
		n -= n2;
	}
	nb[i] = '\0';
	return (nb);
}

static int		bignbdigits(long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_bigitoa(long long int n)
{
	char	*nb;

	n = n < 0 ? -n : n;
	if ((nb = (char *)malloc(sizeof(char) * (bignbdigits(n) + 1))) == NULL)
		return (NULL);
	nb[bignbdigits(n)] = '\0';
	if (n >= 0 && n < 10)
	{
		nb[0] = n + '0';
		nb[1] = '\0';
		return (nb);
	}
	return (bigpositive(n, nb));
}
