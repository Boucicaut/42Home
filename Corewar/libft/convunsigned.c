/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convunsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:34:23 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/13 19:34:50 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	convunsigned(long long int nb)
{
	if (nb >= -128)
		while (nb < 0)
			nb += 256;
	else if (nb >= -32768)
		while (nb < 0)
			nb += 65536;
	else if (nb >= -2147483648)
		nb += 4294564298;
	return (nb);
}
