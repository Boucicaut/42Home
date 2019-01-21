/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:57:07 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/20 16:36:39 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# define MAXPOURCENT 10

typedef struct	s_matchpat
{
	char		pattern;
	int			(*f)(va_list args, char *str, int *lim, int *i);
}				t_matchpat;

int				islongornot(char *str, int i, char c);

int				doshittythings(int *lim, char *nb, int neg, char c);
int				*setflag(char *str, int *i, int *tab);
int				*setlim(char *str, int *i, va_list args);

int				pourcentd(va_list args, char *str, int *lim, int *i);
char			*delminus(char *str);
void	pourcentdnol(va_list args, char *str, int *lim, int *i);
void	pourcentdll(va_list args, char *str, int *lim, int *i);

int				pourcento(va_list args, char *str, int *lim, int *i);
void	pourcentoll(va_list args, char *str, int *lim, int *i);
void	pourcentonoll(va_list args, char *str, int *lim, int *i);
void	octprintall(int j, int *lim, char *res);

int				pourcentu(va_list args, char *str, int *lim, int *i);
void	pourcentull(va_list args, char *str, int *lim, int *i);
void	pourcentunll(va_list args, char *str, int *lim, int *i);
void	uprintall(char *res, int *tab, int qtenb);
void	fillcharu(unsigned long long int nb, char *str, int j);
int				pourcentx(va_list args, char *str, int *lim, int *i);
char			*checkzero(char *str);
void			pourcentxll(va_list args, char *str, int *lim, int *i);
int				pourcentp(va_list args, char *str, int *lim, int *i);
void	pprintall(int j, int *lim);
void			pourcentxnoel(va_list args, char *str, int *lim, int *i);
void			hexaprintall(int j, int x, int *lim, char *res);
void			hexatolower(char *res);
int				pourcents(va_list args, char *str, int *lim, int *i);
int				pourcentc(va_list args, char *str, int *lim, int *i);

void			fpall(int *lim, char *res, int d, int z);
void			hexatolower(char *res);

void			roundednine(char *str, int i);
void			roundit(char *nbchar, int lim2, int z, int d);
int				*setuplim(char *str, int *i, va_list args);
int				pourcentf(va_list args, char *str, int *lim, int *i);
void	pourcentfl(va_list args, char *str, int *lim, int *i);
void	pourcentfnl(va_list args, char *str, int *lim, int *i);
void	fpall(int *lim, char *res, int d, int z);

int				pourcentpourcent(va_list args, char *str, int *lim, int *i);
int				whatafterpourcent(char *str, int i, va_list args\
, t_matchpat *tab);
void			printnb(int *i, char *str, va_list args);
int				ft_printf(char *str, ...);
t_matchpat	*initmatchpat(void);
int		whatafterpourcent(char *str, int i, va_list args, t_matchpat *tab);
int		gofurther(char *str, int i, t_matchpat *tab);

#endif
