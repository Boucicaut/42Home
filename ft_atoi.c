/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:52 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/14 17:52:28 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	k;

	i = 0;
	k = 0;
	res = 1;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			res = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		k = (k * 10) + (str[i] - '0');
		i++;
	}
	return (k * res);
}
