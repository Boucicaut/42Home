/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:51:57 by hlombard          #+#    #+#             */
/*   Updated: 2019/06/06 17:51:59 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, int cursize, int newsize)
{
	void *tmp;

	if (!(tmp = malloc(newsize)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(tmp, ptr, cursize);
		free(ptr);
	}
	return (tmp);
}
