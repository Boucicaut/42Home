#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"

int	main(void)
{

ft_printf("\n==========TEST %%c && %%s==========\n\n");
	ft_printf("%10.2s\n", "test");
	printf("%10.2s\n", "test");
											write(1, "\n", 1);
	ft_printf("%.2s\n", "a");
	printf("%.2s\n", "a");
											write(1, "\n", 1);
	ft_printf("%5c\n", 'L');
	printf("%5c\n", 'L');
											write(1, "\n", 1);
	ft_printf("%2s O\n", "");
	printf("%2s O\n", "");
											write(1, "\n", 1);
	ft_printf("%5s\n", "Hello a tous\tMfgr\nrs");
	printf("%5s\n", "Hello a tous\tMfgr\nrs");
											write(1, "\n", 1);

ft_printf("\n==========TEST %%d==========\n\n");
	ft_printf("% 5d\n", 214);
	printf("% 5d\n", 214);
											write(1, "\n", 1);
	ft_printf("% 25.18d\n", -2147483647);
	printf("% 25.18d\n", -2147483647);
											write(1, "\n", 1);
	ft_printf("%25.1ld\n", 21474454583647);
	printf("%25.1ld\n", 21474454583647);
											write(1, "\n", 1);
	ft_printf("%.1ld\n", -21474454583647);
	printf("%.1ld\n", -21474454583647);
											write(1, "\n", 1);
	ft_printf("a %025.1d\n", -214);
	printf("a %025.1d\n", -214);
											write(1, "\n", 1);
	ft_printf("%+25.6d\n", 210);
	printf("%+25.6d\n", 210);
											write(1, "\n", 1);

ft_printf("\n==========TEST %%x==========\n\n");
	ft_printf("%#8x a\n", 42);				//!! BUG ICI CONCERNANT LIM[1]
	printf("%#8x a\n", 42);
											write(1, "\n", 1);
	ft_printf("%#08x a\n", 42);				//!! BUG ICI CONCERNANT LIM[1]
	printf("%#08x a\n", 42);
											write(1, "\n", 1);
	ft_printf("%-10x a\n", 42);
	printf("%-10x a\n", 42);
											write(1, "\n", 1);
	ft_printf("%-15.4x s\n", 214);
	printf("%-15.4x s\n", 214);
											write(1, "\n", 1);
	ft_printf("%#25.10x\n", 214);
	printf("%#25.10x\n", 214);
											write(1, "\n", 1);
	ft_printf("%5.1x\n", -2147483647);
	printf("%5.1x\n", -2147483647);
											write(1, "\n", 1);
	ft_printf("%25.18lX\n", 21474454583647);
	printf("%25.18lX\n", 21474454583647);
											write(1, "\n", 1);
	ft_printf("%.1X\n", 2147444578);
	printf("%.1X\n", 2147444578);
											write(1, "\n", 1);
	ft_printf("%#25.1X\n", -214);
	printf("%#25.1X\n", -214);
											write(1, "\n", 1);
	ft_printf("%#6.15x\n", 210);
	printf("%#6.15x\n", 210);
											write(1, "\n", 1);
	ft_printf("%#6.15x\n", 217890);
	printf("%#6.15x\n", 217890);
											write(1, "\n", 1);

ft_printf("\n==========TEST %%o==========\n\n");
	ft_printf("%-5.3dA\n", -1);
	printf("%-5.3dA\n", -1);
											write(1, "\n", 1);
	ft_printf("%#5.3o\n", 0);
	printf("%#5.3o\n", 0);
											write(1, "\n", 1);
	ft_printf("%05.1o\n", -2147483647);
	printf("%05.1o\n", -2147483647);
											write(1, "\n", 1);
	ft_printf("%25.1lo\n", 21474454583647);
	printf("%25.1lo\n", 21474454583647);
											write(1, "\n", 1);
	ft_printf("%0.1o\n", 2147444578);
	printf("%0.1o\n", 2147444578);
											write(1, "\n", 1);
	ft_printf("%#25.1o\n", -214);
	printf("%#25.1o\n", -214);
											write(1, "\n", 1);
	ft_printf("%#6.10o\n", 210);
	printf("%#6.10o\n", 210);
											write(1, "\n", 1);
	ft_printf("%0#6.10o\n", 217890);
	printf("%0#6.10o\n", 217890);
											write(1, "\n", 1);

ft_printf("\n==========TEST %%u==========\n\n");
	ft_printf("%5.1u\n", 214);
	printf("%5.1u\n", 214);
											write(1, "\n", 1);
	ft_printf("%05.1u\n", -2147483647);
	printf("%05.1u\n", -2147483647);
											write(1, "\n", 1);
	ft_printf("a%025lu\n", 21474454583647);
	printf("a%025lu\n", 21474454583647);
											write(1, "\n", 1);
/* POUR GERER le flag 0 -> lim[2]
 *	Si lim[1] > 0 et lim[2] == 1 alors lim[2] est mis a 0
 * */
	ft_printf("%0.1u\n", 2147444578);
	printf("%0.1u\n", 2147444578);
											write(1, "\n", 1);
	ft_printf("%025.1u\n", 888888888);
	printf("%025.1u\n", 888888888);
											write(1, "\n", 1);
	ft_printf("%6.10u\n", 210);
	printf("%6.10u\n", 210);
											write(1, "\n", 1);
	ft_printf("%-16.10u\n", 217890);
	printf("%-16.10u\n", 217890);
											write(1, "\n", 1);

ft_printf("\n==========TEST %%p==========\n\n");
int	i = 4;
int	k = 18;
i = 3;
	ft_printf("%30p\n", &i);
	printf("%30p\n", &i);
											write(1, "\n", 1);
	ft_printf("%-30p\n", &i);
	printf("%-30p\n", &i);
											write(1, "\n", 1);
	ft_printf("%p\n", &k);
	printf("%p\n", &k);
											write(1, "\n", 1);

ft_printf("\n==========TEST %%f==========\n\n");
//printf("----\n First test 214 : %f, %Lf\n",(double)214, (long double)214);
	ft_printf("%5.1f a\n", (double)214);
	printf("%5.1f a\n", (double)214);
											write(1, "\n", 1);
	ft_printf("%05.1f b\n", (double)-2147483647);
	printf("%05.1f b\n", (double)-2147483647);
											write(1, "\n", 1);
	ft_printf("%025Lf c\n", (long double)21474454583647);
	printf("%025Lf c\n", (long double)21474454583647);
											write(1, "\n", 1);
	ft_printf("%0.1fd\n", (double)2147444578);
	printf("%0.1fd\n", (double)2147444578);
											write(1, "\n", 1);
	ft_printf("%025.1fe\n", (double)888888888);
	printf("%025.1fe\n", (double)888888888);
											write(1, "\n", 1);
	ft_printf("%6.10ff\n", (double)210);
	printf("%6.10ff\n", (double)210);
											write(1, "\n", 1);
	ft_printf("%-16.10fg\n", (double)217890);
	printf("%-16.10fg\n", (double)217890);
											write(1, "\n", 1);

/* D'ou vient le probleme du test all ? */
	ft_printf("%#9X\n", 546897);
	printf("%#9X\n", 546897);
											write(1, "\n", 1);
	ft_printf("%-9x\n", 12345);
	printf("%-9x\n", 12345);
											write(1, "\n", 1);
/*									*/
ft_printf("\n==========TEST pourcent==========\n\n");
	ft_printf("%5%\n");
	printf("%5%\n");
	ft_printf("%-5% a\n");
	printf("%-5% a\n");

ft_printf("\n==========TEST ALL==========\n\n");
ft_printf("Resul : %+5d et Str : %5s %c,\t %025u, %#9X, %09x\n", 3, "HELLSAA", 103, 454545, 546897, 12345);
printf("Resul : %+5d et Str : %5s %c,\t %025u, %#9X, %09x\n", 3, "HELLSAA", 103, 454545, 546897, 12345);
	return (0);
}
