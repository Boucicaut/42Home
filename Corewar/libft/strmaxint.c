/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmaxint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:51:18 by hlombard          #+#    #+#             */
/*   Updated: 2019/06/06 17:52:22 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strmaxint(char *str)
{
	if (ft_strlen(str) > 11)
		return (1);
	if (ft_atoll(str) < (long)-2147483648)
		return (1);
	if (ft_atoll(str) > (long)2147483647)
		return (1);
	return (0);
}
