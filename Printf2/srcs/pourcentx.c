/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:50:02 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/17 19:41:42 by bviollet         ###   ########.fr       */
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

void	pourcentxnoel(va_list args, char *str, int *lim, int *i)
{
	long int			nb;
	char				*res;
	int					j;
	int					x;

	j = *i;
	x = 0;
	if (str[j] == '#')
	{
		j = j + 1;
		x = 1;
	}
	j += lim[2] + lim[3] + lim[4] + lim[5]; // si le truc du - et + en meme tps bug
	nb = va_arg(args, long int);
	nb = nb > 4294967294 || nb < -4294967295 ? 0 : nb;
	nb = nb < 0 ? 4294967295 + nb : nb;
//printf("Nb : %ld\n", nb);
	res = ft_strcmp(ft_convertbase(nb, 16), "00") == 0 ? ft_strdup("0") : ft_convertbase(nb, 16);
//printf("Res : %s\n", res);
//	j++;
	while (str[j] && (str[j] != 'X' && str[j] != 'x') &&
(ft_isdigit(str[j]) || str[j] == '.' || str[j] == 'l' || str[j] == 'h'))
		j++;
//printf("Str[%d] : %s\n", j, &str[j]);
	if (str[j] == 'x')
		hexatolower(res);
	hexaprintall(ft_qtenb(nb, 'd', 16, 16), x, lim, res);
}

void	pourcentxll(va_list args, char *str, int *lim, int *i)
{
	long long int		nb;
	char				*res;
	int					j;
	int					x;

	j = *i;
	x = 0;
	if (str[j] == '#')
	{
		j = j + 1;
		x = 1;
	}
	nb = va_arg(args, long long int);
	res = ft_convertbase(nb, 16);
//	j++;
	while (str[j] && (str[j] != 'X' && str[j] != 'x') &&
(ft_isdigit(str[j]) || str[j] == '.' || str[j] == 'l' || str[j] == 'h'))
		j++;
	if (str[j] == 'x')
		hexatolower(res);
	hexaprintall(ft_qtebignb(nb, 16), x, lim, res);
}

char	*checkzero(char *str)
{
	int		j;
	char 	*res;

	j = 0;
	if (str[j] != '0')
		return (str);
	res = ft_strnew(ft_strlen(str));
	while (str[j])
	{
		res[j] = str[j + 1];
		j++;
	}
	res[j] = '\0';
	free(str);
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

//printf("Nb : %d || RESSS : %s\n", (int)nb, res);
	res = checkzero(res);// a cause de convertbase et de qtenb utilise il peut mettre un 0 en trop au debut
	while (str[j] && str[j] != 'x' && str[j] != 'X')
		j++;
	str[j] == 'x' ? hexatolower(res) : 0;
	//lim[6] == 1 && *res != '0' ? lim[0] -= 2 : 0; // Si 0x on reduit lim[0] ATTENTION a priori pas lim[1]
	//lim[1] = lim[1] > (int)ft_strlen(res) ? lim[1] : ft_strlen(res);
	*res == '0' ? lim[6] = 0 : 0;
//printf("\nOk!1, lim4 : %d, lim1 : %d, lim0 : %d\n", lim[4], lim[1], lim[0]);
	printed += doshittythings(lim, res, 0, str[j]);
	//ft_putstr(res);
//printf("\nOk!2, lim4 : %d, lim1 : %d, lim0 : %d\n", lim[4], lim[1], lim[0]);
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
