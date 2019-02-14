/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runthrough.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:12:29 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/09 18:24:51 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	runthrough(char **ptr, void (*f)(char **ptr, int i, int j))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			while (ptr[i][j])
			{
				f(ptr, i, j);
				j++;
			}
			i++;
			j = 0;
		}
	}
}
