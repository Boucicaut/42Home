/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexatoupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:59:12 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/10 18:01:21 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	hexatoupper(char *res, char mode)
{
	int	j;

	j = 0;
	while (res[j])
	{
		res[j] = mode == 'u' ? ft_toupper(res[j]) : ft_tolower(res[j]);
		j++;
	}
}
