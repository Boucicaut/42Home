/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:45:39 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/04 15:03:04 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		*setuplim(char *str, int *i, va_list args)
{
	int			*lim;

	if (!(lim = malloc(sizeof(int) * 2)))
		return (NULL);
	lim = setflag(str, i, lim);
	if (str[*i] == '*')
		lim[0] = va_arg(args, int);
	if (str[*i] && ft_isdigit(str[*i]))
		lim[0] = ft_atoi(&str[*i]);
	while (str[*i] && str[*i] != 'f')
	{
		if (str[*i] == '.')
		{
			*i = *i + 1;
			if (str[*i] == '*')
				break ;
			lim[1] = ft_atoi(&str[*i]);
		}
		*i = *i + 1;
	}
	if (str[*i] == '*')
		lim[1] = va_arg(args, int);
	if (lim[1] == 0)
		lim[1] = 6;
	return (lim);
}

void	fpall(int *lim, char *res, int d, int z)
{
	int			j;

	z = z > 0 ? z : 6;
	j = d;
	lim[1] = lim[1] > 0 ? lim[1] : 6;
	if (lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
	while (j++ + (lim[1]) + lim[5] < lim[0])
		lim[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	while (lim[1]-- > z)
		ft_putchar('0');
	if (!lim[4])
	{
		lim[5] == 1 ? ft_putchar(' ') : 0;
		lim[3] == 1 && *res != '-' > 0 ? ft_putchar('+') : 0;
		ft_putstr(res);
	}
}

int		islongornot(char *str, int i, char c)
{
	while (str[i])
	{
		if (ft_issamealpha(str[i], c))
			return (0);
		if (ft_issamealpha(str[i], 'l'))
			return (1);
		i++;
	}
	return (0);
}

int		pourcentf(va_list args, char *str, int *lim, int *i)
{
	int			j;
	long double	nb;
	char		*res;
	int			neg;
	int			printed;

	printed = 0;
	j = *i;
	while (str[*i] != '.' && str[*i] != '%')
		*i = *i - 1;
	lim[1] = lim[1] == 0 && str[*i] != '.' ? 6 : lim[1];
	lim[6] = str[*i] == '.' && str[*i + 1] == '0' ? lim[6] : 0;
	nb = islongornot(str, j, 'f') ? va_arg(args, long double) : va_arg(args, double);
//printf("Nb : %f || %Lf\n", (double)nb, nb);
	neg = nb < 0 ? 1 : 0;
	nb = neg == 1 ? -nb : nb;
//printf("\nLim : %d %d %d %d %d %d %d\n", lim[0], lim[1],lim[2],lim[3],lim[4],lim[5],lim[6]);
	res = ft_itoadouble(nb, lim[1], 50);
	if (res[(int)ft_strlen(res) - 1] == '.')
	   	res[(int)ft_strlen(res) - 1] = '\0'; 
//printf("Nb : %Lf DoubleNB : %f   +**+*++**+*+*+\n||   Res : %s\n",nb,(double)nb, res);
//printf("Before ROUNDED Res : %s\n",res);
//printf("Nbbb : %.15Lf || Z : %d\n", nb, ft_qtenb(nb, 'z', 10, 36));
	roundit(res, lim[1], ft_qtenb(nb, 'z', 10, 16), ft_qtenb(nb, 'd', 10, 20));
//printf("After roundit : %s\n", res);
//printf("Afte ROUNDED Res : %s\n",res);

	//lim[0] -= lim[0] && (lim[3] || lim[5] || neg) ? 1 : 0;
	//lim[0] -= lim[6] ? 1 : 0;

/*
	while (!lim[4] && lim[0]-- > (int)ft_strlen(res))
	{
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
		printed++;
	}

	if (lim[3] || lim[5] || neg)
		printed++;
	lim[3] && !neg ? ft_putchar('+') : 0;
	lim[5] ? ft_putchar(' ') : 0;
	neg ? ft_putchar('-') : 0;
	
	ft_putstr(res);
	if (lim[6])
		ft_putchar('.');
	
	while (lim[4] && lim[0]-- > (int)ft_strlen(res))
	{
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
		printed++;
	}

	printed += ft_strlen(res);*/
//printf("F before shit : %s\n", res);
	printed = doshittythings(lim, res, neg, 'f');
	free(res);
	free(lim);
	return (printed);

	/*while (str[*i] && (str[*i] != 'l' && str[*i] != 'L' && str[*i] != 'f'))
		*i = *i + 1;
	if (str[*i] == 'l' || str[*i] == 'L')
	{
		*i = j;
		pourcentfl(args, str, lim, i);
	}
	else
	{
		*i = j;
		pourcentfnl(args, str, lim, i);
	}*/
}
