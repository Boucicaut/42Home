/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:57:07 by bviollet          #+#    #+#             */
/*   Updated: 2019/02/13 18:11:03 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# define MAXPOURCENT 12
# define CBLA "\e[30m"
# define CRED "\e[31m"
# define CGRE "\e[32m"
# define CYEL "\e[33m"
# define CBLU "\e[34m"
# define CPIN "\e[35m"
# define CCYA "\e[36m"
# define CWHI "\e[37m"
# define CDEF "\e[0m"

typedef struct		s_matchpat
{
	char			pattern;
	int				(*f)(va_list args, char *str, int *lim, int *i);
}					t_matchpat;

char				*setupresa(char *res, int *lim, int *hh);
int					*setuphha(int *hh, int *lim, long double vl);
int					printbeforea(char *str, int i, int *lim, int qted);
int					pourcenta(va_list args, char *str, int *lim, int *i);

int					arrondi(long double vl, int max);
int					coloreds(int *lim, char *res);
int					*qtenbfors(int *qtenb, char c, int *lim);
int					skipifcolor(char *str, int i);
char				*getcolor(char *res, char *str, int i, int *lim);
char				*selectcolor(char *str);

int					islon(char *str, int i, char c);

int					putbeginning(char *res, int *lim, int *qtenb, char c);
int					putend(char *res, int *lim, int *qtenb, char c);
int					signandbase(char *res, int neg, int *lim, char c);
int					*preqte(int *lim, char c, int neg, char *nb);
int					doshittythings(int *lim, char *nb, int neg, char c);
int					*setflag(char *str, int *i, int *tab);
int					*setlim(char *str, int *i, va_list args);
int					*setlim2(va_list args, char *str, int *i, int *tab);

int					pourcentb(va_list args, char *str, int *lim, int *i);

int					pourcentd2(char *str, char *res, int *lim, int i);
int					pourcentd(va_list args, char *str, int *lim, int *i);
char				*delminus(char *str);

unsigned long long	pourcento2(va_list args, char *str, int i);
int					pourcento(va_list args, char *str, int *lim, int *i);
void				octprintall(int j, int *lim, char *res);

int					pourcentu(va_list args, char *str, int *lim, int *i);
unsigned long long	pourcentu2(va_list args, char *str, int i);
void				uprintall(char *res, int *tab, int qtenb);
void				fillcharu(unsigned long long int nb, char *str, int j);
int					pourcentx(va_list args, char *str, int *lim, int *i);
unsigned long long	pourcentx3(va_list args, char *str, int i);
int					pourcentx2(char *res, int printed, char c, int *lim);
char				*checkzero(char *str);
int					pourcentp(va_list args, char *str, int *lim, int *i);
void				pprintall(int j, int *lim);
void				hexaprintall(int j, int x, int *lim, char *res);
void				hexatolower(char *res);
int					pourcents(va_list args, char *str, int *lim, int *i);
int					pourcentc(va_list args, char *str, int *lim, int *i);

void				fpall(int *lim, char *res, int d, int z);
void				hexatolower(char *res);

void				roundednine(char *str, int i);
void				roundedf(char *str, int i);
void				roundit(char *nbchar, int lim2, int z, int arrondi);
int					*setuplim(char *str, int *i, va_list args);
int					pourcentf(va_list args, char *str, int *lim, int *i);
void				fpall(int *lim, char *res, int d, int z);

int					pourcentpourcent(va_list args, char *str, int *lim, int *i);
int					whatafterpourcent(char *str, int i, va_list args\
, t_matchpat *tab);
void				printnb(int *i, char *str, va_list args);
int					ft_printf2(char *str, int *i, int printed);
int					ft_printf(char *str, ...);
t_matchpat			*initmatchpat(void);
t_matchpat			*initmatchpat2(t_matchpat *tab);
int					whatafterpourcent(char *str, int i\
, va_list args, t_matchpat *tab);
int					gofurther(char *str, int i, t_matchpat *tab);

#endif
