/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qtebignb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:12:08 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/14 20:24:04 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
int	bignbdigits(long double vl, int base)	// ici long long int avant
{
	int	id;

	id = 0;
	while (vl > 0.999999)
	{
		vl = vl / base;
		id++;
//printf("Current id : %d and Nb : %Lf\n", id, vl);
	}
	return (id > 0 ? id : 1);
}

int	ft_qtebignb(long double vl, int base) // CHANGEMENT du 14/01, avant en long long int !!!
{
	int	id;
	int	neg;
	int	iz;

	iz = 0;
	neg = vl > 0 ? 0 : 1;
	vl = vl > 0 ? vl : -vl;
	id = bignbdigits(vl, base); // vl etait caste en long long int ici
	/*while (vl > 200000000)
		vl -= 200000000;*/
	vl = vl - vl;				// vl... idem
	return (id + neg);
}
