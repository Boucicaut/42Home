/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:53:30 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/11 18:06:08 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	if (n == 0)
		return (ft_strdup("0"));
	i = 1 + (n > 0 ? bignbdigits(n / 10) : bignbdigits(-(n / 10)));
	nb = ft_strnew(i + 20);
	i--;
	if (n < 0)
	{
		nb[i--] = ((-(n % 10)) + '0');
		n = n - (n % 10);
		n /= 10;
		n = -n;
	}
	while (n > 0)
	{
		nb[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (nb);
}
