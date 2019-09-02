/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:39:26 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/21 16:58:56 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	if ((c >= 65) && (c <= 122))
		if ((c >= 97) || (c <= 90))
			return (1);
	return (0);
}