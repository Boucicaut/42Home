/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoadouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:14:58 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/14 20:39:54 by bviollet         ###   ########.fr       */
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

	i = size;
	if (str[size - 1] == '.')
		size--;
	i--;
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

#include <stdio.h>
char	*ft_itoadouble(long double nb, int z, int max)
{
	char		*str;
	int			i;
	int			d;
	int			iz;

	iz = ft_qtenb((double)nb, 'z', 10, max);
	d = ft_qtebignb(nb, 10);
//printf("\nMalloc a %d + %d + 2 = %d\n",d,z, d + z + 2);
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
