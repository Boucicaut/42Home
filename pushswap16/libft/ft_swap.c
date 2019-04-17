/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:36:56 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/22 18:36:58 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *s, void *s2, int size)
{
	void	*tmp;

	if (!(tmp = malloc(sizeof(int))))
		return ;
	if (size == (int)sizeof(int))
	{
		*(int*)tmp = *(int*)s;
		*(int*)s = *(int*)s2;
		*(int*)s2 = *(int*)tmp;
	}
	else if (size == (char)sizeof(char))
	{
		*(char*)tmp = *(char*)s;
		*(char*)s = *(char*)s2;
		*(char*)s2 = *(char*)tmp;
	}
	free(tmp);
}
