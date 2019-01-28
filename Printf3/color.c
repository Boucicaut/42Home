#include <stdio.h>
#include "libft/libft.h"

/* Black : 30 \ 40	||	Red : 31 / 41	||	Green : 32 / 42	||	Yellow : 33 / 43	||
 * Blue : 34 \ 44	||  Magenta : 35 / 45	|| Cyan : 36 / 46	|| White : 37 / 47
 							Bright, ajouter ;1 */

#define CBLA "\e[30m"
#define CRED "\e[31m"
#define CGRE "\e[32m"
#define CYEL "\e[33m"
#define CBLU "\e[34m"
#define CPIN "\e[35m"
#define CCYA "\e[36m"
#define CWHI "\e[37m"
#define CWH8 "\e[38m"

#define CDEF "\e[0m"

int	main(int argc, char **argv)
{
	ft_putstr(CBLA"black");
write(1, "\n", 1);
	ft_putstr(CRED"red");
write(1, "\n", 1);
	ft_putstr(CGRE"green");
write(1, "\n", 1);
	ft_putstr(CYEL"yellow");
write(1, "\n", 1);
	ft_putstr(CBLU"blue");
write(1, "\n", 1);
	ft_putstr(CPIN"pink");
write(1, "\n", 1);
	ft_putstr(CCYA"cyan");
write(1, "\n", 1);
	ft_putstr(CWHI"white");
write(1, "\n", 1);
	ft_putstr(CDEF"default");
write(1, "\n", 1);

	//write(1, str2, strlen(str2));
	/*
	write(1, str, strlen(str));
write(1, "\n", 1);
	write(1, str2, strlen(str2));
*/
	(void)argc;
	(void)argv;
	return (0);
}
