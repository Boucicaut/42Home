/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:31:49 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/26 17:31:39 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		*qtenbfors(int *qtenb, char c, int *lim)
{
	if (c != 's' || !lim[7])
		return (qtenb);
	else
		qtenb[1] -= 12;
	return (qtenb);
}	

int		skipifcolor(char *str, int i)
{
	if (ft_strncmp(str + i, "{black}", 7) == 0)
		return (i + 7);
	if (ft_strncmp(str + i, "{red}", 5) == 0)
		return (i + 5);
	if (ft_strncmp(str + i, "{green}", 7) == 0)
		return (i + 7);
	if (ft_strncmp(str + i, "{yellow}", 8) == 0)
		return (i + 8);
	if (ft_strncmp(str + i, "{blue}", 6) == 0)
		return (i + 6);
	if (ft_strncmp(str + i, "{pink}", 6) == 0)
		return (i + 6);
	if (ft_strncmp(str + i, "{cyan}", 6) == 0)
		return (i + 6);
	if (ft_strncmp(str + i, "{white}", 7) == 0)
		return (i + 7);
	if (ft_strncmp(str + i, "{default}", 9) == 0)
		return (i + 9);
	if (ft_strncmp(str + i, "{eoc}", 5) == 0)
		return (i + 5);
	return (i);
}

char	*selectcolor(char *str)
{
	if (ft_strncmp(str, "black}", 6) == 0)
		return (ft_strdup(CBLA));
	if (ft_strncmp(str, "red}", 4) == 0)
		return (ft_strdup(CRED));
	if (ft_strncmp(str, "green}", 6) == 0)
		return (ft_strdup(CGRE));
	if (ft_strncmp(str, "yellow}", 7) == 0)
		return (ft_strdup(CYEL));
	if (ft_strncmp(str, "blue}", 5) == 0)
		return (ft_strdup(CBLU));
	if (ft_strncmp(str, "pink}", 5) == 0)
		return (ft_strdup(CPIN));
	if (ft_strncmp(str, "cyan}", 5) == 0)
		return (ft_strdup(CCYA));
	if (ft_strncmp(str, "white}", 6) == 0)
		return (ft_strdup(CWHI));
	if ((ft_strncmp(str, "default}", 8) == 0) ||
ft_strncmp(str, "eoc}", 4) == 0)
		return (ft_strdup(CDEF));
//printf("Strncmp fail\n\n");
	return (ft_strdup("\0"));
}

char	*getcolor(char *res, char *str, int i, int *lim)
{
	char	*color;
	char	*res2;

	color = NULL;
	while (str[i] && str[i] != '%')
		i--;
	if (str[i - 1] == '}')
	{
		while (str[i] && str[i] != '{')
			i--;
		if (str[i++] == '{')
		{
			if (!(res2 = ft_strnew(ft_strlen(res) + 13)))
				return (NULL);
			color = selectcolor(str + i);
			res2 = ft_strcat(res2, color);
			res2 = ft_strcat(res2, res);
			res2 = ft_strcat(res2, CDEF);
			lim[7] = 1;
			free(color);
			free(res);
			return (res2);
		}
	}
	return (res);
}	

int		coloreds(int *lim, char *res)
{
	int	len;
	int	printed;

	printed = 0;
	len = (int)ft_strlen(res) - 9;
//printf("Colored shit, lim0 : %d, lim1 : %d, len : %d\n", lim[0], lim[1], len);
	while (!lim[4] && lim[0] > len)
	{
		printed++;
		lim[0]--;
		ft_putchar(' ');
	}
	if (lim[1] > len)
		res[lim[1] + 6] = '\0';
	ft_putstr(res);
	while (lim[4] && lim[0] > len)
	{
		printed++;
		lim[0]--;
		ft_putchar(' ');
	}
	return (printed + len);
}
