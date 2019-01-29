/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qtenb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:14:33 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/14 18:22:04 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbdecimal(double vl, int max, int id, int base)
{
	int			iz;
	long int	nb;

	iz = 0;
	nb = (long int)(vl * ft_tento(10, max));
	while (nb % 10 == 0)
	{
		iz++;
		nb = nb / base;
	}
	return (max - id - iz);
}

int		nbdecimaldigits(double vl, int max, int id, int base)
{
	int			i;
	double		nine;
	double		one;
	int			iz;
	double		vl2;

	i = 0;
	one = 0.0000000000001;
	nine = 0.9999999999999;
	iz = 0;
	while (i < 16)
	{
		vl2 = vl;
		vl = vl - (long long int)vl; /* plutot que lignes au dessus */
		if (i + id >= max || vl > nine || vl < one)
			return (iz);
		iz++;
		i++;
		vl = vl2 * base;
		nine = nine * 10 - 9;
		one = one * 10;
	}
	vl2 = vl;
	vl = vl - (int)(vl / 10) * 10;
	return (iz);
}

int		nbdigits(double vl, int base)
{
	int		id;
	double	max;

	max = 0.9;
	id = 0;
	while (vl > max)
	{
		vl = vl / base;
		id++;
		max = max / 10 + 0.9;
	}
	return (id > 0 ? id : 1);
}

int		ft_qtenb(double vl, char mode, int base, int max)
{
	int	i;
	int	id;
	int	neg;

	if (vl == 0 && mode == 'd') // si vl == 0 et mode == 'd' renvoie une qte de 1, sinon ca renvoyait 2
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
