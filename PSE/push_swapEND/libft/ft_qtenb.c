/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qtenb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:14:33 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/13 16:45:04 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbdecimaldigits(long double vl, int max, int id, int base)
{
	int			i;
	double		nine;
	double		one;
	int			iz;
	double		vl2;

	i = 0;
	one = 0.000000000000001;
	nine = 0.999999999999999;
	iz = 0;
	while (i < 16)
	{
		vl2 = vl;
		vl = vl - (long long int)vl;
		if (i + id >= max || vl > nine || vl < one)
			return (iz);
		iz++;
		i++;
		vl = vl2 * base;
		nine = nine * 10 - 9;
		one = one * 10;
	}
	return (iz);
}

int		nbdigits(long int vl, int base)
{
	int			id;

	id = 0;
	while (vl > 0)
	{
		vl = vl / base;
		id++;
	}
	return (id > 0 ? id : 1);
}

int		ft_qtenb(long double vl, char mode, int base, int max)
{
	int	i;
	int	id;
	int	neg;

	if (vl == 0 && mode == 'd')
		return (1);
	neg = vl > 0 ? 0 : 1;
	vl = vl > 0 ? vl : -vl;
	id = 0;
	i = 0;
	id = nbdigits(vl, base);
	if (mode == 'z')
		return (nbdecimaldigits(vl, max, id, base));
	if (mode == 'f')
		return (neg + id + nbdecimaldigits(vl, max, id, base));
	return (neg + id);
}
