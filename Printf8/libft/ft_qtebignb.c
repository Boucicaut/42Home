/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qtebignb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:12:08 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/10 19:40:48 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	bignbdigits(long double vl, int base)
{
	int	id;

	id = 0;
	while (vl > (long double)0.9999999999999999)
	{
		vl = vl / base;
		id++;
	}
	return (id > 0 ? id : 1);
}

int	ft_qtebignb(long double vl, int base)
{
	int	id;
	int	neg;
	int	iz;

	iz = 0;
	neg = vl > 0 ? 0 : 1;
	vl = vl > 0 ? vl : -vl;
	id = bignbdigits(vl, base);
	vl = vl - vl;
	return (id + neg);
}
