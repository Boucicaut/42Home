/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:50:02 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/09 18:32:17 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	hexatolower(char *res)
{
	int					j;

	j = 0;
	while (res[j])
	{
		res[j] = ft_tolower(res[j]);
		j++;
	}
}

void	hexaprintall(int j, int x, int *lim, char *res)
{
	int					jj;

//printf("Lim : %d %d %d %d %d %d\n", lim[0], lim[1], lim[2], lim[3], lim[4], lim[5]);
	jj = j;
	lim[1] = lim[1] > 0 ? lim[1] : jj;
	if (lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
	while (j++ + (lim[1] - jj) + lim[5] < lim[0] + (x * 2))
		lim[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	if (x == 1)
		ft_putstr("0x");
	while (lim[1]-- > jj)
		ft_putchar('0');
	if (!lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' > 0 ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
}

char	*checkzero(char *str)
{
	int		j;
	char 	*res;
	char	*tmp;

	tmp = str;
	j = 0;
	if (str[j] && str[j] != '0')
		return (str);
	res = ft_strnew(ft_strlen(str));
	while (str[j])
	{
		res[j] = str[j + 1];
		j++;
	}
	res[j] = '\0';
	free(tmp);
	return (res);
}

int		pourcentx(va_list args, char *str, int *lim, int *i)
{
	int							j;
	unsigned long long int		nb;
	char						*res;
	int							printed;

	j = *i;
	printed = 0;
/* IDENTIFIER ICI SI LE NB EST BUGUE AVEC LE CAST (EXEMPLE TEST ALL) */
	nb = islongornot(str, *i, 'x') ? va_arg(args, unsigned long long int) : va_arg(args, unsigned int); // ou long
//printf("Nb(int) : %d || Nb %llu", (int)nb, nb);

	res = ft_convertbase(nb, 16);

//printf("Str[i] : %c, lim[6] : %d\n", str[*i], lim[6]);
//printf("Res : %s\n", res);
	res = checkzero(res);// a cause de convertbase et de qtenb utilise il peut mettre un 0 en trop au debut
	res[0] && res[0] == '0' ? lim[6] = 0 : 0;
	while (str[j] && str[j] != 'x' && str[j] != 'X')
		j++;
	str[j] == 'x' ? hexatolower(res) : 0;
	*i = j;
	//lim[6] == 1 && *res != '0' ? lim[0] -= 2 : 0; // Si 0x on reduit lim[0] ATTENTION a priori pas lim[1]
	//lim[1] = lim[1] > (int)ft_strlen(res) ? lim[1] : ft_strlen(res);
	while (str[j] != '%')
	{
		if (str[j--] == '.')
		{
			printed = 1;
			lim[2] = 0;
		}
	}
	if (printed && res[0] == '0')
		res[0] = '\0';
//printf("Str[i] : %c, lim[6] : %d\n", str[*i], lim[6]);
	printed = doshittythings(lim, res, 0, str[*i]);
	//ft_putstr(res);
//printf("\nOk!2, lim4 : %d, lim1 : %d, lim0 : %d\n", lim[4], lim[1], lim[0]);
	free(lim);
	free(res);
	return (printed);
/*
	while (str[*i] == '.' || str[*i] == '*' || (ft_isdigit(str[*i])))
		*i = *i + 1;
	if (str[*i] == 'l')
	{
//		*i = str[*i + 1] == 'l' ? *i + 1 : *i;
		*i = j;
		pourcentxll(args, str, lim, i);
	}
	else
	{
//		*i = str[*i + 1] == 'l' ? *i + 1 : *i;
		*i = j;
		pourcentxnoel(args, str, lim, i);
	}
	*/
}
