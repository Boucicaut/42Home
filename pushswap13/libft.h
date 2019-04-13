/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:07:12 by bviollet          #+#    #+#             */
/*   Updated: 2019/04/13 18:04:41 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define COUNT_OF(ptr) (sizeof(ptr) / sizeof((ptr)[0]))
# define ABSS(x) x > 0 ? x : -x
# define BUFF_SIZE 10
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
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

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					strmaxint(char *str);
unsigned long long	convunsigned(long long int nb);
void				hexatoupper(char *res, char mode);
int					convsignchar(int vl, int mode);
char				*ft_bigitoa(long long int n);
char				ft_strchrcol(char **str, int i, int j, int find);
int					ft_qtebignb(long double vl, int base);
void				ft_putbignbr(long long int n);
int					ft_issamealpha(char c, char d);
char				*ft_itoadouble(long double nb, int z, int max);
long double			ft_tento(int nb, int i);
long double			ft_tentoneg(int nb, int i);
int					ft_qtenb(long double vl, char mode, int base, int max);
char				*ft_convertbase(long long unsigned int nb, int base);
void				ft_freeptr(void **ptr);
void				runthrough(char **ptr, void(*f)(char **ptr, int i, int j));
int					ft_nextline(char **str, char **line, int fd, int nbbytes);
int					get_next_line(const int fd, char **line);
void				ft_findreplace(char *str, char find, char replace);
void				ft_freestr(char **ptr, int nb);
void				ft_swap(void *s, void *s2, int size);
void				ft_bzero(void *ptr, size_t n);
void				*ft_memset(void *ptr, int nb, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void	*s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, int nb);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, int n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int nb);
char				*ft_strrchr(const char *s, int nb);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*setupresa(char *res, int *lim, int *hh);
int					*setuphha(int *hh, int *lim, long double vl);
int					printbeforea(char *str, int i, int *lim, int qted);
int					pourcenta(va_list args, char *str, int *lim, int *i);
int					arrondi(long double vl, int max);
int					coloreds(int *lim, char *res, int qte);
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
