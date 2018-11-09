#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
/* SUPPRIMER CET INCLUDE !!!!!!!!!!!!*/

/*determine size of an array*/
#define COUNT_OF(ptr) (sizeof(ptr) / sizeof((ptr)[0]))

void		ft_bzero(void *ptr, size_t n);
void 		*ft_memset(void *ptr, int nb, size_t len);
void		*ft_memcpy(void *dst, void *src, size_t n);
void		*ft_memmove(void *dst, void *src, size_t len);
void		*ft_memchr(void	*s, int c, size_t n);
int			ft_memcmp(void *s1, void *s2, size_t n);
size_t		ft_strlen(char *s);
char		*ft_strdup(char *s);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strncpy(char *dest, char *src, int nb);
char		*ft_strcat(char *dest, char *src);
char		*ft_strncat(char *dest, char *src, int n);
size_t		ft_strlcat(char *dst, char *src, size_t size);
char		*ft_strchr(char *s, int nb);
char		*ft_strrchr(char *s, int nb);
char		*ft_strstr(char *s1, char *s2);
char		*ft_strnstr(char *s1, char *s2, size_t size);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_atoi(char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char *s, char (*f)(char));
char		*ft_strmapi(char *s, char (*f)(unsigned int, char));
int			ft_strequ(char *s1, char *s2);
int			ft_strnequ(char *s1, char *s2, size_t n);
char		*ft_strsub(char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char *s);
char		**ft_strsplit(char *s, char c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putendl(char *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif

