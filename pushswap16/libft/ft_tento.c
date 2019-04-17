/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tento.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:13:57 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/09 18:14:04 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_tento(int nb, int i)
{
	long double	res;

	res = 1;
	while (i-- > 0)
		res = res * nb;
	return (res);
}

long double	ft_tentoneg(int nb, int i)
{
	long double	res;

	res = 1;
	while (i-- > 0)
		res = res / nb;
	return (res);
}
