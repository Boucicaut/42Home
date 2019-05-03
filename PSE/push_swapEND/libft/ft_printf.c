/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:21:59 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/11 19:43:13 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			whatafterpourcent(char *str, int i, va_list args, t_matchpat *tab)
{
	int			ii;
	int			j;
	int			printed;

	printed = 0;
	ii = i;
	while (str[ii])
	{
		j = 0;
		while (j < MAXPOURCENT)
		{
			if (ft_issamealpha(str[ii], tab[j].pattern))
			{
				printed = tab[j].f(args, str, setlim(str, &i, args), &i);
				return (printed);
			}
			j++;
		}
		ii++;
	}
	return (printed);
}

int			gofurther(char *str, int i, t_matchpat *tab)
{
	int			j;

	while (str[i])
	{
		j = 0;
		while (j < MAXPOURCENT)
		{
			if (ft_issamealpha(str[i], tab[j].pattern))
				return (i + 1);
			j++;
		}
		i++;
	}
	return (i);
}

int			ft_printf2(char *str, int *i, int printed)
{
	if (str[*i] == 92)
	{
		printed++;
		*i += 1;
		ft_putchar(92);
	}
	ft_putchar(str[*i]);
	printed++;
	*i += 1;
	return (printed);
}

int			ft_printf(char *str, ...)
{
	va_list		args;
	int			i;
	t_matchpat	*tab;
	int			printed;

	printed = 0;
	tab = initmatchpat();
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '{' || str[i] == '}')
			i = str[i] == '{' ? skipifcolor(str, i) : i;
		if (str[i] == '%')
		{
			i += 1;
			printed += whatafterpourcent(str, i, args, tab);
			i = gofurther(str, i, tab);
		}
		else if (str[i] != '\0')
			printed = ft_printf2(str, &i, printed);
	}
	va_end(args);
	free(tab);
	return (printed);
}
