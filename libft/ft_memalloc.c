/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:40:59 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/10 19:41:02 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = malloc(size)))
		return (NULL);
	while (i < size)
	{
		((char*)ptr)[i] = 0;
		i += sizeof(char);
	}
	return (ptr);
}
