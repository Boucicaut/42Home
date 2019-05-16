/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:41:57 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/10 19:41:58 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strchrcol(char **str, int i, int j, int find)
{
	while (str[i])
	{
		if (str[i][j] == find)
			return (str[i][j]);
		i++;
	}
	return (0);
}
