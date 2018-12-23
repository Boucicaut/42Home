/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:36:47 by bviollet          #+#    #+#             */
/*   Updated: 2018/12/07 13:37:03 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestr(char **ptr, int nb)
{
	int		i;

	i = 0;
	if (ptr != NULL)
	{
		while ((ptr[i] != NULL) && (i < nb))
		{
			if (ptr[i][0] != '\0' || ptr[i][0] != ' ')
				free(ptr[i]);
			i++;
		}
		free(ptr);
	}
	return ;
}
