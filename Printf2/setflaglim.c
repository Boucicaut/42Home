/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflaglim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:52:07 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/16 19:37:12 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		doshittythings(int *lim, int qtenb, int neg, char c)
{
	int	printed;
//printf("Lim %d %d %d %d %d %d %d \n", lim[0], lim[1], lim[2], lim[3], lim[4], lim[5], lim[6]);
//printf("\nqte : %d || lim : %d %d %d %d %d %d %d\n", qtenb, lim[0], lim[1], lim[2], lim[3], lim[4], lim[5], lim[6]);
	printed = 0;
	qtenb += neg == 1 ? 1 : 0;
	lim[0] -= neg == 0 && lim[3] == 1 ? 1 : 0;
	lim[1] = lim[1] > qtenb ? lim[1] + neg : qtenb;

	lim[5] == 1 && neg == 0 ? ft_putchar(' '), printed++, lim[0]-- : 0; // printed ici ? 

	while (lim[4] == 0 && lim[0]-- > lim[1])
	{
		printed++;
		lim[2] == 1 ? ft_putchar('0') : ft_putchar(' ');
	}

	neg == 1 ? ft_putchar('-'), printed++ : 0;
	lim[3] == 1 && neg == 0 ? ft_putchar('+'), printed++ : 0;	// '+' sign

	if (lim[6] == 1)
	{	
		c == 'o' ? ft_putchar('0'), printed++ : 0;
		ft_issamealpha(c, 'x') ? printed += 2 : 0;
		c == 'x' ? ft_putstr("0x") : c == 'X' ? ft_putstr("0X") : 0;
	}
	while (lim[1]-- > qtenb)
	{
		printed++;
		ft_putchar('0');
	}
	return (printed);
}

int		*setflag(char *str, int *i, int *tab)
{
	//printf("Str : %s\n", &str[*i]);
	*i -= 1;
	while (str[*i] && str[*i] != '*' &&
str[*i] != '.' && (!(ft_isalnum(str[*i])) || str[*i] == '0'))
	{
		*i += 1;
		str[*i] == '0' /*&& !ft_isdigit(str[*i + 1])*/ ? tab[2] = 1, *i += 1 : 0;
		str[*i] == '+' ? tab[3] = 1, *i += 1 : 0;
		str[*i] == '-' ? tab[4] = 1, *i += 1 : 0;
		str[*i] == ' ' ? tab[5] = 1, *i += 1 : 0;
		str[*i] == '#' ? tab[6] = 1, *i += 1 : 0;
	}
/*	tab [2] == '0' || tab[3] == '+' || tab[4] == '-' || tab[5] == ' '*/
	tab[5] = tab[5] == 1 && tab[3] == 1 ? 0 : tab[5];
	tab[2] = tab[4] == 1 && tab[2] == 1 ? 0 : tab[2]; // Prends le dessus ? Flag '0' ou '-' ??
//printf("\nTab : %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
	return (tab);
}

int		*setlim(char *str, int *i, va_list args)
{
	int	*tab;

	if (!(tab = (int*)malloc(sizeof(int) * 7)))
		return (NULL);
	ft_bzero(tab, sizeof(int) * 7);
	tab = setflag(str, i, tab);
//printf("\nAfter-Flag Tab : %d %d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
//printf("\nStr : %s\n", str + *i); // on se situe sur le 1er %
	if (str[*i] == '*')
	{
		tab[0] = va_arg(args, int);
		*i += 1;
	}
	else
	{
		tab[0] = ft_atoi(&str[*i]);
		tab[0] != 0 ? *i += ft_qtenb(tab[0], 'd', 10, 10) : 0;
//printf("Tab[0] : %d et Qte : %d\n", tab[0], ft_qtenb(tab[0], 'd', 10, 10));
	}
	if (str[*i] == '.')
		*i += 1;
	if (str[*i] == '*')
	{	
		tab[1] = va_arg(args, int);
		*i += 1;
	}
	else
	{
		tab[1] = ft_atoi(&str[*i]);
		tab[1] != 0 ? *i += ft_qtenb(tab[1], 'd', 10, 10) : 0;
	}
	//tab[0] = tab[4] == 1 ? 0 : tab[0]; en fait archi faux, puisqu'on doit decaler du coup a droite
	if (str[*i] != 'f' && (str[*i] != 'L' && str[*i + 1] != 'f'))
		tab[2] = tab[1] > 0 ? 0 : tab[2]; // Si Flag '0' et lim[1] > 0 alors pas de 0 ?? SAUF POUR 'F' ??
//printf("\nAfter-Lim Tab : %d %d\n", tab[0], tab[1]);
//printf("tab %d %d %d %d %d %d %d \n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6]);
	return (tab);
}
