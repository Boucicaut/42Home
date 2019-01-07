#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

#define	MAXPOURCENT 9
typedef struct	s_matchpat
{
	char	pattern;
	void	(*f)(va_list, char*, int*);	
}				t_matchpat;

int				*setlim(char *str, int *i, va_list args);

void			hexatolower(char *res);

void			pourcentp(va_list args, char *str, int *i);
void			pourcentu(va_list args, char *str, int *i);
void			pourcento(va_list args, char *str, int *i);
void			pourcentx(va_list args, char *str, int *i);
void			pourcentd(va_list args, char *str, int *i);
void			pourcents(va_list args, char *str, int *i);
void			pourcentc(va_list args, char *str, int *i);

void			roundednine(char *str, int i);
void			roundit(char *nbchar, int lim2, int z, int d);
int				*setuplim(char *str, int *i, va_list args);
void			pourcentf(va_list args, char *str, int *i);

int				whatafterpourcent(char *str, int i, va_list args, t_matchpat *tab);
void			pourcentd(va_list args, char *str, int *i);
void			printnb(int *i, char *str, va_list args);
void			ft_printf(char *str, ...);

#endif
