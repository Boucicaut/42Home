/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_whitespaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:36:01 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/04 19:11:25 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/del_whitespaces.h"

char	*del_whitespaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		j = i - 1;
		while (str[++j])
			str[j] = str[j + 1];
		if (str[i] != ' ' && str[i] != '\t')
			break ;
	}
	i = (int)ft_strlen(str) - 1;
	while (i > 0 && str[i] && (str[i] == ' ' || str[i] == '\t'))
		str[i--] = '\0';
	return (str);
}
