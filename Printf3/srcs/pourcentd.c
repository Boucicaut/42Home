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

char	*getcolor(char *str, int i)
{
	char	*color;
	int		k;

	k = 0;
	color = NULL;
	while (str[i] && str[i] != '{' && str[i] != '%')
		i--;
	if (str[i++] == '{')
	{
		while (str[i] != allcolors(k++))
			;								// use k to compare with all colors
		color = selectcolor(k);

		color = strincpy(color, str, 9);
		return (color);
	}
	return (NULL)
}	

int		pourcents(va_list args, char *str, int *lim, int *i)
{
	char	*s;
	int		printed;
	int		qte;
	int		j;

	//idee, faire un char *color, color = getcolor(str, *i), et strcat de s et color
	//si couleur ON, probleme de strlen donc lim[7] = 1 et soustraire 8 pour la qte
	j = 0;
	s = (char*)va_arg(args, int*);
	s = s ? ft_strdup(s) : ft_strdup("(null)");
	qte = (int)ft_strlen(s);
	lim[1] = lim[1] == 0 ? qte : lim[1];
	while (lim[1] < (int)ft_strlen(s))
		s[--qte] = '\0';
	qte = (int)ft_strlen(s);
	lim[1] = lim[1] > qte ? qte : lim[1];
	lim[0] = lim[0] > lim[1] ? lim[0] : lim[1];

	s = getcolor(str, *i, lim);

	printed = doshittythings(lim, s, lim[7], 's');
	free(lim);
	free(s);
	(void)str[*i];
	return (printed);
}

int		pourcentc(va_list args, char *str, int *lim, int *i)
{
	char	c;
	char	*res;

	c = (char)va_arg(args, int);
	res = ft_strnew(3);
	if (c)
	{
		res[0] = c;
		res[1] = '\0';
	}
	else
	{
		res[0] = '^';
		res[1] = '@';
		res[2] = '\0';
	}
	while (!lim[4] && lim[0]-- > 1)
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
	ft_putstr(res);
	while (lim[4] && lim[0]-- > 1)
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
	free(lim);
	free(res);
	(void)str[*i];
	return (lim[0] ? lim[0] : 1);
}

char	*delminus(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew((int)ft_strlen(str));
	if (str[0] && str[0] != '-')
	{
		free(tmp);
		return (str);
	}
	while (str[i + 1])
	{
		tmp[i] = str[i + 1];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

int		pourcentd2(char *str, char *res, int *lim, int i)
{
	int	printed;

	res = delminus(res);
	while (str[i] && str[i] != '.' && str[i] != '%')
		i = i - 1;
	if (str[i] == '.' && !lim[1] && *res == '0')
		res[0] = '\0';
	printed = doshittythings(lim, res, lim[7], 'd');
	free(res);
	free(lim);
	return (printed);
}

int		pourcentd(va_list args, char *str, int *lim, int *i)
{
	long long int	nb;
	char			*res;

	if (!(islongornot(str, *i - 1, 'd')))
	{
		nb = va_arg(args, int);
		lim[7] = nb >= 0 ? 0 : 1;
		res = ft_itoa(nb);
	}
	else
	{
		nb = va_arg(args, long long int);
		lim[7] = nb > 0 ? 0 : 1;
		res = ft_bigitoa(nb);
	}
	if (str[*i] == 'h')
	{
		nb = str[*i + 1] == 'h' ? converttosignedchar(nb, 2) : converttosignedchar(nb, 1);
		lim[7] = nb < 0 ? 1 : 0;
		nb = lim[7] ? -nb : nb;
		free(res);
		res = ft_itoa(nb);
	}
	return (pourcentd2(str, res, lim, *i));
}
