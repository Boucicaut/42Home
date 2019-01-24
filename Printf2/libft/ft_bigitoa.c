/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:53:30 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/23 21:41:13 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
/*static char		*bigpositive(long long int n, char *nb)
{
	int				i;
	long long int	n2;
	int				j;
	int				zero;

	i = 0;
	while (n > 0)
	{
		zero = 0;
		j = 0;
		n2 = n;
		while (n2 >= 10)
		{
			if (n2 < 100 && n2 % 10 == 0)
				zero = 1;
			j++;
			n2 /= 10;
		}
		//j -= j > 0 ? 1 : 0;
		//n2 *= 10;
		nb[i++] = (n2 % 10) + '0';
		zero ? nb[i++] = '0' : 0;
		n2 *= ft_tento(10, j);
//		while (n2 < n)
//		{
//			printf("N2 : %lld || N : %lld\n", n2, n);
//			n2 *= 10;
//		}
//		if (n2 > n)
//			n2 /= 10;
		n -= n2;
	}
	nb[i] = '\0';
	return (nb);
}
*/
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
	int		i;

	i = 1 + (n > 0 ? bignbdigits(n / 10) : bignbdigits(-(n / 10)));
//printf("Start i : %d\n", i);
	nb = ft_strnew(i + 20);
	i--;
	if (n < 0)
	{
//printf("I : %d || n10 : %d\n", i, (int)(n % 10));
		nb[i--] = ((-(n % 10)) + '0');
		n = n - (n % 10);
		n /= 10;
		n = -n;
	}
//printf("N : %lld\n", n);
	while (n > 0)
	{
		nb[i--] = (n % 10) + '0';
		n /= 10;
//printf("i : %d || Nbchar : %s\n",i, &(nb[i + 1]));
	}

	return (nb);
}
/*
char			*ft_bigitoa(long long int n)
{
	char	*nb;

	if (n == -9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	n = n < 0 ? -n : n;
	nb = ft_strnew(bignbdigits(n));
	nb[bignbdigits(n)] = '\0';
	if (n >= 0 && n < 10)
	{
		nb[0] = n + '0';
		nb[1] = '\0';
		return (nb);
	}
	return (bigpositive(n, nb));
}*/
