/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoadouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:14:58 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/23 19:04:13 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printsave(char *str, int save, int i)
{
	str[i] = save % 10 + '0';
	save = save / 10;
}

void	putdoublechar(long double n, char *str, int size, int max)
{
	long double	save;
	int			i;

	i = size > 0 ? size - 1 : 0;
	if (n < 1)
		printsave(str, 10, i);

	while (n >= 1)
	{
		save = n;
		while (save > 200000000000000)
			save = save - 20000000000000;
		while (save > 2147483647)
			save = save - 2000000000;
		printsave(str, (int)save % 10, i);
		i--;
		n = n / 10;
	}
	(void)max;
}

char	*itoadoublezero(long double nb, int z)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(z + 3);
	str[i++] = '0';
	str[i++] = z ? '.' : '\0';
	while (z + 2 > i)
	{
		nb = nb * 10;
		str[i++] = (int)nb % 10 + '0';
		nb = nb - (int)nb;
	}
	return (str);
}

char	*ft_itoadouble(long double nb, int z, int max)
{
	char		*str;
	int			i;
	int			d;
	int			iz;

	if (nb <= 0)
		return (itoadoublezero(nb, z));
	iz = ft_qtenb((double)nb, 'z', 10, max);
	d = ft_qtebignb(nb, 10);
	str = malloc(sizeof(char) * d + z + 2);
	str[z + d + 1] = '\0';
	str[d] = '.';
	i = d + 1;
	putdoublechar(nb, str, ft_qtebignb(nb, 10), 9);
	//while (nb > 2147483647)			/* gerer n pour enlever left dot part */
	//	nb = nb - 2000000000.;
	nb = nb - (long long int)nb;
	while (i < z + d + 1)
	{
		nb = nb * 10;
		str[i] = (int)nb + '0';
		nb = nb - (int)nb;
		i++;
	}
	return (str);
}
