#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "includes/ft_printf.h"

int	main(void)
{

	int	a = 0;
	int	b = 0;
ft_printf("\n==========TEST %%c && %%s==========\n\n");
	a+=ft_printf("%c TEST\n", 'c');
	b+=printf("%c TEST\n", 'c');
											write(1, "\n", 1);
	a+=ft_printf("%-9c TEST\n", ';');
	b+=printf("%-9c TEST\n", ';');
											write(1, "\n", 1);
	a+=ft_printf("%c TEST\n", '\0');
	b+=printf("%c TEST\n", '\0');
											write(1, "\n", 1);
	a+=ft_printf("%5ca\n", 0);
	b+=printf("%5ca\n", 0);
											write(1, "\n", 1);
	a+=ft_printf("%5ca\n", 0);
	b+=printf("%5ca\n", 0);
											write(1, "\n", 1);
	a+=ft_printf("%-5ca\n", 42);
	b+=printf("%-5ca\n", 42);
											write(1, "\n", 1);
	a+=ft_printf("%.2ca\n", '\0');
	b+=printf("%ca\n", '\0');
											write(1, "\n", 1);
	a+=ft_printf("%5cb\n", '\0');
	b+=printf("%5cb\n", '\0');
											write(1, "\n", 1);
	a+=ft_printf("%4cc\n", 't');
	b+=printf("%4cc\n", 't');
											write(1, "\n", 1);
	a+=ft_printf("%10.2s\n", "test");
	b+=printf("%10.2s\n", "test");
											write(1, "\n", 1);
	a+=ft_printf("%.2s\n", "a");
	b+=printf("%.2s\n", "a");
											write(1, "\n", 1);
	a+=ft_printf("%5c\n", 'L');
	b+=printf("%5c\n", 'L');
											write(1, "\n", 1);
	a+=ft_printf("%9s O\n", NULL);
	b+=printf("%9s O\n", NULL);
											write(1, "\n", 1);
	a+=ft_printf("%2s O\n", "");
	b+=printf("%2s O\n", "");
											write(1, "\n", 1);
	a+=ft_printf("%5s\n", "Hello a tous\tMfgr\nrs");
	b+=printf("%5s\n", "Hello a tous\tMfgr\nrs");
											write(1, "\n", 1);

	ft_printf("A:%10d\n", a);
	ft_printf("B:%10d\n", b);
ft_printf("\n==========TEST %%d==========\n\n");
	printf("@moulitest: %.d %.0d\n", 42, 43);
	ft_printf("@moulitest: %.d %.0d\n", 42, 43);
											write(1, "\n", 1);
	a+=ft_printf("%lld\n", (long long)-9223372036854775807);
	b+=printf("%lld\n", (long long)-9223372036854775807);
											write(1, "\n", 1);
	a+=ft_printf("%lld\n", (long long)9223372036854775807);
	b+=printf("%lld\n", (long long)9223372036854775807);
											write(1, "\n", 1);
	ft_printf("%hhd\n", (signed char)128);
	printf("%hhd\n", (signed char)128);
											write(1, "\n", 1);
	ft_printf("%hd\n", (short)32768);
	printf("%hd\n", (short)32768);
											write(1, "\n", 1);
	ft_printf("%hhd\n", (signed char)-129);
	printf("%hhd\n", (signed char)-129);
											write(1, "\n", 1);
	a+=ft_printf("%d\n", -2147483648);
	b+=printf("%ld\n", -2147483648);
											write(1, "\n", 1);
	ft_printf("%d\n", -2147483648);
	printf("%ld\n", -2147483648);
											write(1, "\n", 1);
	ft_printf("%05d\n", -214);
	printf("%05d\n", -214);
											write(1, "\n", 1);
	ft_printf("% 5d\n", 214);
	printf("% 5d\n", 214);
											write(1, "\n", 1);
	a+=ft_printf("% 25.18d\n", -2147483647);
	b+=printf("% 25.18d\n", -2147483647);
											write(1, "\n", 1);
	a+=ft_printf("%25.1ld\n", 21474454583647);
	b+=printf("%25.1ld\n", 21474454583647);
											write(1, "\n", 1);
	a+=ft_printf("%.1ld\n", -21474454583647);
	b+=printf("%.1ld\n", -21474454583647);
											write(1, "\n", 1);
	ft_printf("a %025.1d\n", -214);
	printf("a %025.1d\n", -214);
											write(1, "\n", 1);
	ft_printf("%+25.6d\n", 210);
	printf("%+25.6d\n", 210);
											write(1, "\n", 1);

	ft_printf("A:%10d\n", a);
	ft_printf("B:%10d\n", b);
ft_printf("\n==========TEST %%x==========\n\n");
	ft_printf("%#8x a\n", 42);				//!! BUG ICI CONCERNANT LIM[1]
	printf("%#8x a\n", 42);
											write(1, "\n", 1);
	ft_printf("%#08x a\n", 42);				//!! BUG ICI CONCERNANT LIM[1]
	printf("%#08x a\n", 42);
											write(1, "\n", 1);
	ft_printf("%#-10x a\n", 42);
	printf("%#-10x a\n", 42);
											write(1, "\n", 1);
	a+=ft_printf("%#-15.4x s\n", 214);
	b+=printf("%#-15.4x s\n", 214);
											write(1, "\n", 1);
	ft_printf("%#25.10x\n", 214);
	printf("%#25.10x\n", 214);
											write(1, "\n", 1);
	ft_printf("%#5.1x\n", -2147483647);
	printf("%#5.1x\n", -2147483647);
											write(1, "\n", 1);
	a+=ft_printf("%#25.18lX\n", 21474454583647);
	b+=printf("%#25.18lX\n", 21474454583647);
											write(1, "\n", 1);
	a+=ft_printf("%#.1X\n", 2147444578);
	b+=printf("%#.1X\n", 2147444578);
											write(1, "\n", 1);
	a+=ft_printf("%#25.1X\n", -214);
	b+=printf("%#25.1X\n", -214);
											write(1, "\n", 1);
	a+=ft_printf("%#6.15x\n", 210);
	b+=printf("%#6.15x\n", 210);
											write(1, "\n", 1);
	a+=ft_printf("%#6.15x\n", 217890);
	b+=printf("%#6.15x\n", 217890);
											write(1, "\n", 1);
	a+=ft_printf("%.0x a\n", 0); // BLANC
	b+=printf("%.0x b\n", 0);
											write(1, "\n", 1);
	ft_printf("%0x a\n", 0);
	printf("%0x b\n", 0);
											write(1, "\n", 1);
	a+=ft_printf("%.x a\n", 0); // BLANC
	b+=printf("%.x b\n", 0);
											write(1, "\n", 1);
	ft_printf("%#0x a\n", 0);
	printf("%#0x b\n", 0);
											write(1, "\n", 1);
	ft_printf("%x a\n", 0);
	printf("%x b\n", 0);
											write(1, "\n", 1);

	ft_printf("\nA:%10d\n", a);
	ft_printf("\nB:%10d\n", b);
ft_printf("\n==========TEST %%o==========\n\n");
	ft_printf("%o\n", 0);
	printf("%o\n", 0);
											write(1, "\n", 1);
	a+=ft_printf("%o\n", 0);
	b+=printf("%o\n", 0);
											write(1, "\n", 1);
	a+=ft_printf("%-5.3dA\n", -1);
	b+=printf("%-5.3dA\n", -1);
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
	a+=ft_printf("%0.1o\n", 2147444578);
	b+=printf("%0.1o\n", 2147444578);
											write(1, "\n", 1);
	a+=ft_printf("%#25.1o\n", -214);
	b+=printf("%#25.1o\n", -214);
											write(1, "\n", 1);
	a+=ft_printf("%#6.10o\n", 210);
	b+=printf("%#6.10o\n", 210);
											write(1, "\n", 1);
	a+=ft_printf("%0#6.10o\n", 217890);
	b+=printf("%0#6.10o\n", 217890);
											write(1, "\n", 1);

ft_printf("Aa:%010.5d\n", a);
printf("Bb:%010.5d\n", b);
ft_printf("\n==========TEST %%u==========\n\n");
	ft_printf("%u a\n", 0);
	printf("%u a\n", 0);
											write(1, "\n", 1);
	ft_printf("%u a\n", 1);
	printf("%u a\n", 1);
											write(1, "\n", 1);
	a+=ft_printf("%lu a0\n", 4294967296);
	b+=printf("%lu a0\n", 4294967296);
											write(1, "\n", 1);
	a+=ft_printf("%5.1u\n", 214);
	b+=printf("%5.1u\n", 214);
											write(1, "\n", 1);
	a+=ft_printf("%05.1u\n", -2147483647);
	b+=printf("%05.1u\n", -2147483647);
											write(1, "\n", 1);
	a+=ft_printf("a%025lu\n", 21474454583647);
	b+=printf("a%025lu\n", 21474454583647);
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
	a+=ft_printf("%lu\n", (unsigned long)4294967296);
	b+=printf("%lu\n", (unsigned long)4294967296);
											write(1, "\n", 1);
	a+=ft_printf("%u a\n", (unsigned int)-1);
	b+=printf("%u a\n", (unsigned int)-1);
											write(1, "\n", 1);
	ft_printf("%5.o %5.0o O\n", (int)0, (int)0);
	printf("%5.o %5.0o O\n", (int)0, (int)0);
											write(1, "\n", 1);
	ft_printf("%5.u %5.0u U\n", (int)0, (int)1);
	printf("%5.u %5.0u U\n", (int)0, (int)1);
											write(1, "\n", 1);
	a+=ft_printf("%5.d %5.0d D\n", (int)0, (int)0);
	b+=printf("%5.d %5.0d D\n", (int)0, (int)0);
											write(1, "\n", 1);
	a+=ft_printf("%.d %.0d D\n", (int)0, (int)0);
	b+=printf("%.d %.0d D\n", (int)0, (int)0);
											write(1, "\n", 1);

ft_printf("\n==========TEST %%p==========\n\n");
int	i = 4;
int	k = 18;
i = 3;
	a+=ft_printf("%p\n", (void*)0);
	b+=printf("%p\n", (void*)0);
											write(1, "\n", 1);
	a+=ft_printf("%30p\n", &i);
	b+=printf("%30p\n", &i);
											write(1, "\n", 1);
	a+=ft_printf("%-30p\n", &i);
	b+=printf("%-30p\n", &i);
											write(1, "\n", 1);
	a+=ft_printf("%p\n", &k);
	b+=printf("%p\n", &k);
											write(1, "\n", 1);

/* D'ou vient le probleme du test all ? */
	a+=ft_printf("%#9X\n", 546897);
	b+=printf("%#9X\n", 546897);
											write(1, "\n", 1);
	a+=ft_printf("%-9x\n", 12345);
	b+=printf("%-9x\n", 12345);
											write(1, "\n", 1);
/*									*/
ft_printf("\n==========TEST pourcent==========\n\n");
	a+=ft_printf("%.5%\n");
	b+=printf("%.5%\n");
											write(1, "\n", 1);
	a+=ft_printf("%-9% a\n");
	b+=printf("%-9% a\n");
											write(1, "\n", 1);
	a+=ft_printf("%-5% a\n");
	b+=printf("%-5% a\n");
											write(1, "\n", 1);
ft_printf("\n==========TEST %%*==========\n\n");

	a+=ft_printf("%0*Lf c\n",25, (long double)21474454583647);
	b+=printf("%0*Lf c\n",25, (long double)21474454583647);
											write(1, "\n", 1);

	a+=ft_printf("%.*f c\n",25, (double)214744.583647);
	b+=printf("%.*f c\n",25, (double)214744.583647);
											write(1, "\n", 1);

	a+=ft_printf("%-*d c\n",5, -150);
	b+=printf("%-*d c\n",5, -150);
											write(1, "\n", 1);
	a+=ft_printf("{{%*.*d c\n",15,3, -150);
	b+=printf("{{%*.*d c\n",15,3, -150);
											write(1, "\n", 1);
	a+=ft_printf("%0*hhd c\n",25, (char)-150);
	b+=printf("%0*hhd c\n",25, (char)-150);
											write(1, "\n", 1);
	a+=ft_printf("%-*f A\n",5, (double)150.309309);
	b+=printf("%-*f A\n",5, (double)150.309309);
											write(1, "\n", 1);
	a+=ft_printf("%-*f B\n",5, (double)150.309309309);
	b+=printf("%-*f B\n",5, (double)150.309309309);
											write(1, "\n", 1);
	a+=ft_printf("%-.*f C\n",5, (double)150.309309309);
	b+=printf("%-.*f C\n",5, (double)150.309309309);
											write(1, "\n", 1);
	a+=ft_printf("%-*ld D\n",05, (long)-150120130);
	b+=printf("%-*ld D\n",05, (long)-150120130);
											write(1, "\n", 1);

ft_printf("\n==========TEST %%b==========\n\n");
char	*aa = ft_convertbase(8,2);
char	*bb = ft_convertbase(789456,2);
	a+=ft_printf("%b a\n", 8);
	b+=printf("%s a\n", aa);
											write(1, "\n", 1);
	a+=ft_printf("%b a\n", 789456);
	b+=printf("%s a\n", bb);
											write(1, "\n", 1);
free(aa);
free(bb);

ft_printf("\n==========TEST ALL==========\n\n");
a+=ft_printf("Resul : %+5d et Str : %15.4s %c,\t %025u, %#9X, %09x\n", 3, "HELLSAA", 103, 454545, 546897, 12345);
b+=printf("Resul : %+5d et Str : %15.4s %c,\t %025u, %#9X, %09x\n", 3, "HELLSAA", 103, 454545, 546897, 12345);

ft_printf("\n==========LAST TESTS FROM 42FC===========\n\n");

	a+=ft_printf("%hd \t//32768\n", (short)32768);
	b+=printf("%hd \t//32738\n", (short)32768);
											write(1, "\n", 1);
	a+=ft_printf("%hhd \t//838\n", (char)838);
	b+=printf("%hhd \t//838\n", (char)838);
											write(1, "\n", 1);
	a+=ft_printf("%hhd \t//238\n", (char)238);
	b+=printf("%hhd \t//238\n", (char)238);
											write(1, "\n", 1);
	a+=ft_printf("%hhd \t//130\n", (char)130);
	b+=printf("%hhd \t//130\n", (char)130);
											write(1, "\n", 1);
	a+=ft_printf("%hhd \t//-150\n", (char)-150);
	b+=printf("%hhd \t//-150\n", (char)-150);
											write(1, "\n", 1);
	a+=ft_printf("%hhd\n", (char)-129);
	b+=printf("%hhd\n", (char)-129);
											write(1, "\n", 1);
	a+=ft_printf("@moulitest: %.d %.0d\n", 42, 43);
	b+=printf("@moulitest: %.d %.0d\n", 42, 43);
											write(1, "\n", 1);
	a+=ft_printf("@moulitest: %.d %.0d\n", 42, 43);
	b+=printf("@moulitest: %.d %.0d\n", 42, 43);
											write(1, "\n", 1);
	a+=ft_printf("%5.d %5.0d D\n", (int)0, (int)0);
	b+=printf("%5.d %5.0d D\n", (int)0, (int)0);
											write(1, "\n", 1);
	a+=ft_printf("%u\n", -1);
	b+=printf("%u\n", -1);
											write(1, "\n", 1);
	a += ft_printf("%-5c:\n", '*');
	b += printf("%-5c:\n", '*');
											write(1, "\n", 1);
	b+=ft_printf("%.0u|.0u\n", 76543);
	a+=printf("%.0u|.0u\n", 76543);
											write(1, "\n", 1);
	b+=ft_printf("%#0o\n", 0);
	a+=printf("%#0o\n", 0);
											write(1, "\n", 1);
	a+=ft_printf("%st%04.2o%#2oet %#-8.3o\n", "titi", 0, 0, 0);
	b+=printf("%st%04.2o%#2oet %#-8.3o\n", "titi", 0, 0, 0);
											write(1, "\n", 1);
	a+=ft_printf("%024hho et%#1.2o %0012.o\n", (unsigned char)12, 0, 123654789);
	b+=printf("%024hho et%#1.2o %0012.o\n", (unsigned char)12, 0, 123654789);
											write(1, "\n-------\n", 10);
	ft_printf("%012.o|012.o\n", 123654789);
	printf("%012.o|012.o\n", 123654789);
											write(1, "\n", 1);
	ft_printf("%0012o|0012o\n", 123654789);
	printf("%0012o|0012o\n", 123654789);
											write(1, "\n", 1);
	ft_printf("%#6.10o|#6.10o\n", 210);
	printf("%#6.10o|#6.10o\n", 210);
											write(1, "\n", 1);
	ft_printf("%#9o|#9o\n", 210);
	printf("%#9o|#9o\n", 210);
											write(1, "\n", 1);
	ft_printf("%0#10.0x\n", 12345);
	printf("%0#10.0x\n", 12345);
											write(1, "\n", 1);
	a+=ft_printf("toto%###.0o%#.o et %#.1o O!\n",0,0,0);
	b+=printf("toto%###.0o%#.o et %#.1o O!\n",0,0,0);
											write(1, "\n", 1);
	a+=ft_printf("toto %###.0o |%#.o et %#.1o O!\n",0,0,0);
	b+=printf("toto %###.0o |%#.o et %#.1o O!\n",0,0,0);
											write(1, "\n", 1);
	ft_printf("%#.o O!\n",0);
	printf("%#.o O!\n",0);
											write(1, "\n", 1);
	ft_printf("%.o O!\n",0);
	printf("%.o O!\n",0);
											write(1, "\n", 1);
	ft_printf("%.u U!\n",0);
	printf("%.u U!\n",0);
											write(1, "\n", 1);
	ft_printf("%.u U!\n",0);
	printf("%.u U!\n",0);
											write(1, "\n", 1);
	a+=ft_printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	b+=printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
											write(1, "\n", 1);
	a+=ft_printf("c%-c ??\n", (char)564);
	b+=printf("c%-c ??\n", (char)564);
											write(1, "\n", 1);
	a+=ft_printf("%.s S\n", "coco");
	b+=printf("%.s S\n", "coco");
											write(1, "\n", 1);
	a+=ft_printf("%12%\n");
	b+=printf("%12%\n");
											write(1, "\n", 1);
a+=ft_printf("hello ca%----4c %1c va %10c%-c??\n", '\0', '\n', (char)564, 0);
b+=printf("hello ca%----4c %1c va %10c%-c??\n", '\0', '\n', (char)564, 0);
											write(1, "\n", 1);
ft_printf("\n==========TESTS COLOR===========\n\n");

	a+=ft_printf("%20.1s\n", "RED !!!");
	b+=printf("%20.1s\n", "RED !!!");
											write(1, "\n", 1);
	a+=ft_printf("{yellow}%3.1s{default} to\n", "yello !!!");
	b+=printf("%3.1s to\n", "yello !!!");
											write(1, "\n", 1);
	a+=ft_printf("{red}%20.2s{default}\n", "RED !!!");
	b+=printf("%20.2s\n", "RED !!!");
											write(1, "\n", 1);
	a+=ft_printf("{blue}%-10s{eoc} {red}%s{eoc} {green}%-5s{eoc} %s\n", "Blue","red","green", "default");
	b+=printf("%-10s %s %-5s %s\n", "Blue","red","green","default");
											write(1, "\n", 1);
	a+=ft_printf("%s\n", "Aucune couleur");
	b+=printf("%s\n", "Aucune couleur");
											write(1, "\n", 1);

	/*printf("Z qtenb : %d |9\n", ft_qtenb(2.123456789, 'z', 10, 16));
	printf("Z qtenb : %d |15\n", ft_qtenb(2.123456789012345, 'z', 10, 19));
	printf("Z qtenb : %d |19\n", ft_qtenb(2.1234567890123456789, 'z', 10, 16));
											write(1, "\n", 1);*/
	/*printf("\tQte dec : %d |1\n", ft_qtenb(1.1,'z',10,16));
	printf("\tQte dec : %d |2\n", ft_qtenb(1.12,'z',10,16));
	printf("\tQte dec : %d |3\n", ft_qtenb(1.123,'z',10,16));
	printf("\tQte dec : %d |10\n", ft_qtenb(1.1234567891,'z',10,16));
	printf("\tQte dec : %d |11\n", ft_qtenb(1.12345678912,'z',10,16));
	printf("\tQte dec : %d |12\n", ft_qtenb(1.123456789123,'z',10,16));
	printf("\tQte dec : %d |13\n", ft_qtenb(1.1234567891234,'z',10,16));
	printf("\tQte dec : %d |14\n", ft_qtenb(1.12345678912345,'z',10,16));
	printf("\tQte dec : %d |15\n", ft_qtenb(1.123456789123456,'z',10,16));
	printf("\tQte dec : %d |16\n", ft_qtenb(1.1234567891234567,'z',10,16));
	printf("\tQte dec : %d |17\n", ft_qtenb(1.12345678912345678,'z',10,16));*/
											write(1, "\n", 1);

ft_printf("Aa:%010.5d\n", a);
printf("Bb:%010.5d\n", b);
ft_printf("\n==========TEST %%YAPT==========\n\n");
	a+=ft_printf("%0.0hd\n", (short)32767);
	b+=printf("%0.0hd\n", (short)32767);
											write(1, "\n", 1);
	a+=ft_printf("%0.0hd\n", (short)32767);
	b+=printf("%0.0hd\n", (short)32767);
											write(1, "\n", 1);
	a+=ft_printf("%0.0hd\n", (short)32766);
	b+=printf("%0.0hd\n", (short)32766);
											write(1, "\n", 1);
	a+=ft_printf("%0.0hd\n", (short)32768);
	b+=printf("%0.0hd\n", (short)32768);
											write(1, "\n", 1);
	a+=ft_printf("Y s\\n\n");
	b+=printf("Y s\\n\n");
											write(1, "\n", 1);
	a+=ft_printf("|%s| a\n", "STR");
	b+=printf("|%s| a\n", "STR");
											write(1, "\n", 1);
	a+=ft_printf("|%-s| a\n", "A");
	b+=printf("|%-s| a\n", "A");
											write(1, "\n", 1);
	a+=ft_printf("|%lo|\n", (long)9223372036854775807);
	b+=printf("|%lo|\n", (long)9223372036854775807);
											write(1, "\n", 1);
	a+=ft_printf("|%lo|\n", (long)9223372036854775807);
	b+=printf("|%lo|\n", (long)9223372036854775807);
											write(1, "\n", 1);
	a+=ft_printf("|%llo|\n", (unsigned long long int)1844674407370955161);
	b+=printf("|%llo|\n", (unsigned long long int)1844674407370955161);
											write(1, "\n", 1);
	a+=ft_printf("|%o|\n", 1854775807);
	b+=printf("|%o|\n", 1854775807);
											write(1, "\n", 1);
	a+=ft_printf("Aa %x|\n", (short)32767);
	b+=printf("Aa %x|\n", (short)32767);
											write(1, "\n", 1);
	a+=ft_printf("Ba %lx|\n", 4294967295);
	b+=printf("Ba %lx|\n", 4294967295);
											write(1, "\n", 1);
	a+=ft_printf("{%*d}|\n", -5, 42);
	b+=printf("{%*d}|\n", -5, 42);
											write(1, "\n", 1);
	a+=ft_printf("{%.*d}|\n", -5, 42);
	b+=printf("{%.*d}|\n", -5, 42);
											write(1, "\n", 1);
	a+=ft_printf("{%*c}|\n", 0, 0);
	b+=printf("{%*c}|\n", 0, 0);
											write(1, "\n", 1);
	a+=ft_printf("|||%05.*d|\n", -15, 42);
	b+=printf("|||%05.*d|\n", -15, 42);
											write(1, "\n", 1);
	a+=ft_printf("|||%05.*d|\n", -15, -42);
	b+=printf("|||%05.*d|\n", -15, -42);
											write(1, "\n", 1);
	a+=ft_printf(".0 %05.0d|\n", 42);
	b+=printf(".0 %05.0d|\n", 42);
											write(1, "\n", 1);
	a+=ft_printf("0 %05d|\n", 42);
	b+=printf("0 %05d|\n", 42);
											write(1, "\n", 1);
	a+=ft_printf(".1 %05.1d|\n", 42);
	b+=printf(".1 %05.1d|\n", 42);
											write(1, "\n", 1);
	a+=ft_printf("%010.*d|\n",3, 42);
	b+=printf("%010.*d|\n", 3, 42);
											write(1, "\n", 1);
	a+=ft_printf("%025.1u\n", 888888888);
	b+=printf("%025.1u\n", 888888888);
											write(1, "\n", 1);
	a+=ft_printf("1lim1 %025.1d\n", -214);
	b+=printf("1lim1 %025.1d\n", -214);
											write(1, "\n", 1);
	a+=ft_printf(".lim1 %025.d\n", -214);
	b+=printf(".lim1 %025.d\n", -214);
											write(1, "\n", 1);
	a+=ft_printf("0lim1 %025d\n", -214);
	b+=printf("0lim1 %025d\n", -214);
											write(1, "\n", 1);
	a+=ft_printf("|||%025.*u|\n", 15, -2);
	b+=printf("|||%025.*u|\n", 15, -2);
											write(1, "\n", 1);
	a+=ft_printf("%*.8d|\n",10, 42);
	b+=printf("%*.8d|\n", 10, 42);
											write(1, "\n", 1);
	a+=ft_printf("% 5d\n", 214);
	b+=printf("% 5d\n", 214);
											write(1, "\n", 1);
	a+=ft_printf("%025.8fe\n", (double)888888888);
	b+=printf("%025.8fe\n", (double)888888888);
											write(1, "\n", 1);
	a+=ft_printf("%025fe\n", (double)-888888888);
	b+=printf("%025fe\n", (double)-888888888);
											write(1, "\n", 1);
	a+=ft_printf("%025.10fe\n", (double)-888888888);
	b+=printf("%025.10fe\n", (double)-888888888);
											write(1, "\n", 1);
	a+=ft_printf("toto %###.0o |%#.o et %#.1o O!\n",0,0,0);
	b+=printf("toto %###.0o |%#.o et %#.1o O!\n",0,0,0);
											write(1, "\n", 1);
	ft_printf("%#6.10o|#6.10o\n", 210);
	printf("%#6.10o|#6.10o\n", 210);
											write(1, "\n", 1);
ft_printf("Aa:%010.5d\n", a);
printf("Bb:%010.5d\n", b);
ft_printf("\n==========TEST %%f==========\n\n");
//printf("----\n First test 214 : %f, %Lf\n",(double)214, (long double)214);
	a+=ft_printf("%.f a\n", (double)1.00000000001);
	b+=printf("%.f a\n", (double)1.00000000001);
											write(1, "\n", 1);
	a+=ft_printf("%0.2f a\n", (double)0.00000000001);
	b+=printf("%0.2f a\n", (double)0.00000000001);
											write(1, "\n", 1);
	a+=ft_printf("%0.2f a\n", (double)-0.00000000001);
	b+=printf("%0.2f a\n", (double)-0.00000000001);
											write(1, "\n", 1);
	a+=ft_printf("%0.2f b\n", (double)0.0);
	b+=printf("%0.2f b\n", (double)0.0);
											write(1, "\n", 1);
	a+=ft_printf("%#15.0f a\n", (double)12313);
	b+=printf("%#15.0f a\n", (double)12313);
											write(1, "\n", 1);
	a+=ft_printf("%15.f a\n", (double)12313);
	b+=printf("%15.f a\n", (double)12313);
											write(1, "\n", 1);
	a+=ft_printf("%+15.5f a\n", (double)12313);
	b+=printf("%+15.5f a\n", (double)12313);
											write(1, "\n", 1);
	a+=ft_printf("%5.1f a\n", (double)214);
	b+=printf("%5.1f a\n", (double)214);
											write(1, "\n", 1);
	a+=ft_printf("%05.1f b\n", (double)-2147483647);
	b+=printf("%05.1f b\n", (double)-2147483647);
											write(1, "\n", 1);
	a+=ft_printf("%025Lf c\n", (long double)21474454583647);
	b+=printf("%025Lf c\n", (long double)21474454583647);
											write(1, "\n", 1);
	a+=ft_printf("%0.1fd\n", (double)2147444578);
	b+=printf("%0.1fd\n", (double)2147444578);
											write(1, "\n", 1);
	a+=ft_printf("%025.1fe\n", (double)888888888);
	b+=printf("%025.1fe\n", (double)888888888);
											write(1, "\n", 1);
	a+=ft_printf("%6.10ff\n", (double)210);
	b+=printf("%6.10ff\n", (double)210);
											write(1, "\n", 1);
	a+=ft_printf("%-16.10fg\n", (double)217890);
	b+=printf("%-16.10fg\n", (double)217890);
											write(1, "\n", 1);
	a+=ft_printf("%-16fg\n", (double)2.17890);
	b+=printf("%-16fg\n", (double)2.17890);
											write(1, "\n", 1);
	a+=ft_printf("%17fg\n", (double)3.33);
	b+=printf("%17fg\n", (double)3.33);
											write(1, "\n", 1);
	a+=ft_printf("%.1fg\n", (double)3.33);
	b+=printf("%.1fg\n", (double)3.33);
											write(1, "\n", 1);
ft_printf("Aa:%010.5d\n", a);
printf("Bb:%010.5d\n", b);
											write(1, "\n", 1);
	a+=ft_printf("%-.1f |YES\n", (double)3.78);
	b+=printf("%-.1f |YES\n", (double)3.78);
											write(1, "\n", 1);
	a+=ft_printf("%-.8f |YES\n", (double)3.7777777777);
	b+=printf("%-.8f |YES\n", (double)3.7777777777);
											write(1, "\n", 1);
	a+=ft_printf("%.16f |NO\n", (double)1.123456789123456);
	b+=printf("%.16f |NO\n", (double)1.123456789123456);
											write(1, "\n", 1);
	a+=ft_printf("%f |NO\n", (double)465784.16548645156484845465); // probleme de z ici
	b+=printf("%f |NO\n", (double)465784.16548645156484845465);
											write(1, "\n", 1);
	a+=ft_printf("%26.4f |YES\n", (double)2178.99999999);
	b+=printf("%26.4f |YES\n", (double)2178.99999999);
											write(1, "\n", 1);
	a+=ft_printf("%-.5f |YES\n", (double)3.999999999);
	b+=printf("%-.5f |YES\n", (double)3.999999999);
											write(1, "\n", 1);
	a+=ft_printf("%-.16f |YES\n", (double)3.999999999999999999999999999);
	b+=printf("%-.16f |YES\n", (double)3.999999999999999999999999999);
											write(1, "\n", 1);
	a+=ft_printf("%f |YES\n", (double)90.0123456789123456);
	b+=printf("%f |YES\n", (double)90.0123456789123456);
											write(1, "\n", 1);
	a+=ft_printf("%030f |YES\n", (double)2147436474812.45);
	b+=printf("%030f |YES\n", (double)2147436474812.45);
											write(1, "\n", 1);
	a+=ft_printf("Aaa %f %f %f\n", (double)2,(double)3,(double)4);
	b+=printf("Aaa %f %f %f\n", (double)2, (double)3,(double)4);
											write(1, "\n", 1);

											write(1, "\n", 1);
	a+=ft_printf("%030f |YES\n", (double)214743647.45);
	b+=printf("%030f |YES\n", (double)214743647.45);
											write(1, "\n", 1);
	a+=ft_printf("%30f |YES\n", (double)214743647.45);
	b+=printf("%30f |YES\n", (double)214743647.45);
											write(1, "\n", 1);
	a+=ft_printf("%030d |YES\n", 2147436474);
	b+=printf("%030d |YES\n", 2147436474);
											write(1, "\n", 1);

	a+=ft_printf("%030f |YES\n", (double)214743647.454545454545);
	b+=printf("%030f |YES\n", (double)214743647.454545454545);
											write(1, "\n", 1);
	a+=ft_printf("%030f |YES\n", (double)214.45);
	b+=printf("%030f |YES\n", (double)214.45);
											write(1, "\n", 1);
	a+=ft_printf("%030f |YES\n", (double)21474364.481245);
	b+=printf("%030f |YES\n", (double)21474364.481245);
											write(1, "\n", 1);
	a+=ft_printf("%030f |YES\n", (double)2.214743647481245);
	b+=printf("%030f |YES\n", (double)2.214743647481245);
											write(1, "\n", 1);
	a+=ft_printf("%030f |YES\n", (double)2.2214743647481245);
	b+=printf("%030f |YES\n", (double)2.2214743647481245);
											write(1, "\n", 1);
											write(1, "\n", 1);
											write(1, "\n", 1);
	a+=ft_printf("%-.16f |YES\n", (double)3.999899999999999999999);
	b+=printf("%-.16f |YES\n", (double)3.999899999999999999999);
											write(1, "\n", 1);
	a+=ft_printf("%-.26Lf |YES\n", (long double)3.9999);
	b+=printf("%-.26Lf |YES\n", (long double)3.9999);
											write(1, "\n", 1);
											write(1, "\n", 1);
	/* PROBLEME ICI A RESOIDRE ET COMPRENDRE */
	a+=ft_printf("%-.4f |NO\n", (double)3.012345678);
	b+=printf("%-.4f |NO\n", (double)3.012345678);
											write(1, "\n", 1);
	a+=ft_printf("%-.5f |NO\n", (double)3.012345678);
	b+=printf("%-.5f |NO\n", (double)3.012345678);
											write(1, "\n", 1);
	a+=ft_printf("%.6f |NO\n", (double)3.012345678);
	b+=printf("%.6f |NO\n", (double)3.012345678);
											write(1, "\n", 1);
	a+=ft_printf("%026f |26L1\n", (double)3.012345678);
	b+=printf("%026f |26L1\n", (double)3.012345678);
											write(1, "\n", 1);
	a+=ft_printf("%.0f |NO\n", (double)3.012345678);
	b+=printf("%.0f |NO\n", (double)3.012345678);
											write(1, "\n", 1);
	a+=ft_printf("%.f |NO\n", (double)3.012345678);
	b+=printf("%.f |NO\n", (double)3.012345678);
											write(1, "\n", 1);
	a+=ft_printf("%.*f |NO\n", 3,(double)3.012345678);
	b+=printf("%.*f |NO\n", 3,(double)3.012345678);
											write(1, "\n", 1);
	a+=ft_printf("%-*.*f |NO\n", 10,20,(double)3.012345678);
	b+=printf("%-*.*f |NO\n", 10,20,(double)3.012345678);
											write(1, "\n", 1);
	a+=ft_printf("%-f |NO\n", (double)3.012345678);
	b+=printf("%-f |NO\n", (double)3.012345678);
											write(1, "\n", 1);
	/*printf("%10d\n", -42);
	printf("%010.d\n", -42);
	printf("%10.*d\n", -5,-42);
	printf("%010.3d\n", -42);
	printf("%10.3d\n", -42);
	printf("%010.*d\n", 5,-42);
	printf("%010.d\n", -42);
	printf("%010.5d\n", -42);
	printf("%010.0d\n", -42);
	printf("%010.*d\n", -5,-42);
	printf("%010d\n", 42);
											write(1, "\n", 1);
	printf("!!%5.0d|\n", -42);
	printf("!!%05.*d|\n", -15, -42);*/
											write(1, "\n", 1);
	a+=ft_printf("%a |\n", (double)2.345);
	b+=printf("%a |\n", (double)2.345);
											write(1, "\n", 1);
	ft_printf("%La |LONG\n", (long double)7.34567);
	printf("%La |LONG\n", (long double)7.34567);
											write(1, "\n", 1);
	a+=ft_printf("%a (\n", (double)7.34567);
	b+=printf("%a (\n", (double)7.34567);
											write(1, "\n", 1);
	a+=ft_printf("%.1a (\n", (double)3.4);
	b+=printf("%.1a (\n", (double)3.4);
											write(1, "\n", 1);
	a+=ft_printf("%a |\n", (double)2.2);
	b+=printf("%a |\n", (double)2.2);
											write(1, "\n", 1);
	a+=ft_printf("%a\n", (double)278.2458);
	b+=printf("%a\n", (double)278.2458);
											write(1, "\n", 1);
	a+=ft_printf("%a\n", (double)-45200.0045);
	b+=printf("%a\n", (double)-45200.0045);
											write(1, "\n", 1);
ft_printf("Aa:%010.5d\n", a);
printf("Bb:%010.5d\n", b);
	ft_printf("%.10La |LONG\n", (long double)278458745453.54345);
	printf("%.10La |LONG\n", (long double)278458745453.54345);
											write(1, "\n", 1);
	ft_printf("%.9a !9!!\n", (double)2785453.54345);
	printf("%.9a !9!!\n", (double)2785453.54345);
											write(1, "\n", 1);
	ft_printf("%.10a !10!!\n", (double)2785453.54345);
	printf("%.10a !10!!\n", (double)2785453.54345);
											write(1, "\n", 1);
	ft_printf("%.11a !11!!\n", (double)2785453.54345);
	printf("%.11a !11!!\n", (double)2785453.54345);
											write(1, "\n", 1);
	a+=ft_printf("%-20.0a -\n", (double)2.345);
	b+=printf("%-20.0a -\n", (double)2.345);
											write(1, "\n", 1);
	a+=ft_printf("%030.0a|\n", (double)-2.345);
	b+=printf("%030.0a|\n", (double)-2.345);
											write(1, "\n", 1);
	a+=ft_printf("%.5a\n", (double)5485.24564);
	b+=printf("%.5a\n", (double)5485.24564);
											write(1, "\n", 1);
	a+=ft_printf("%.5A\n", (double)5485.24564);
	b+=printf("%.5A\n", (double)5485.24564);
											write(1, "\n", 1);
	a+=ft_printf("%.5A\n", (double)5485.00004);
	b+=printf("%.5A\n", (double)5485.00004);
											write(1, "\n", 1);
	a+=ft_printf("%5a +\n", (double)5485.00004);
	b+=printf("%5a +\n", (double)5485.00004);
											write(1, "\n", 1);
	a+=ft_printf("%-20a *\n", (double)5400.4800004);
	b+=printf("%-20a *\n", (double)5400.4800004);
											write(1, "\n", 1);
	a+=ft_printf("% d *\n", (int)5400);
	b+=printf("% d *\n", (int)5400);
											write(1, "\n", 1);
											write(1, "\n", 1);
	a+=ft_printf("A:%010.5d\n", a);
	b+=printf("B:%010.5d\n", b);
											write(1, "\n", 1);
	a+=ft_printf("%hO\n", (short)48);
	b+=printf("%hO\n", (short)48);
											write(1, "\n", 1);
	a+=ft_printf("NW %15.4d P\n", 424242);
	b+=printf("NW %15.4d P\n", 424242);
											write(1, "\n", 1);
	a+=ft_printf("NW %15.4o P\n", 42);
	b+=printf("NW %15.4o P\n", 42);
											write(1, "\n", 1);
	a+=ft_printf("NW %15.4o P\n", 42);
	b+=printf("NW %15.4o P\n", 42);
											write(1, "\n", 1);
	a+=ft_printf("NW %15u P\n", -1);
	b+=printf("NW %15u P\n", -1);
											write(1, "\n", 1);
	a+=ft_printf("NW %15zd P\n", (ssize_t)1);
	b+=printf("NW %15zd P\n", (ssize_t)1);
											write(1, "\n", 1);
	a+=ft_printf("NW %15zd P\n", 4294967296);
	b+=printf("NW %15zd P\n", 4294967296);
											write(1, "\n", 1);
	a+=ft_printf("NW %15ju P\n", (uintmax_t)1);
	b+=printf("NW %15ju P\n", (uintmax_t)1);
											write(1, "\n", 1);
	a+=ft_printf("%u\n", -1);
	b+=printf("%u\n", -1);
											write(1, "\n", 1);
	a+=ft_printf("%U\n", (unsigned int)-1);
	b+=printf("%U\n", (unsigned int)-1);
											write(1, "\n", 1);
	a+=ft_printf("%U\n", (unsigned int)4294967296);
	b+=printf("%U\n", (unsigned int)4294967296);
											write(1, "\n", 1);
	a+=ft_printf("NW %15zd P\n", (ssize_t)0);
	b+=printf("NW %15zd P\n", (ssize_t)0);
											write(1, "\n", 1);
	a+=ft_printf("%hU\n", (unsigned short)4294967296);
	b+=printf("%hU\n", (unsigned short)4294967296);
											write(1, "\n", 1);
	a+=ft_printf("|%u|\n", (unsigned int)4294967296);
	b+=printf("|%u|\n", (unsigned int)4294967296);
											write(1, "\n", 1);
	a+=ft_printf("|%u|\n", -1);
	b+=printf("|%u|\n", -1);
											write(1, "\n", 1);
	a+=ft_printf("|%X|\n", 1);
	b+=printf("|%X|\n", 1);
											write(1, "\n", 1);
	a+=ft_printf("A|%o|\n", -42);
	b+=printf("A|%o|\n", -42);
											write(1, "\n", 1);
	a+=ft_printf("|%*d|\n",0, 42);
	b+=printf("|%*d|\n", 0, 42);
											write(1, "\n", 1);
	a+=ft_printf("% ~\n", 42);
	b+=ft_printf("% ~\n", 42);
											write(1, "\n", 1);
	a+=ft_printf("%*d\n", 5, 42);
	b+=printf("%*d\n", 5, 42);
											write(1, "\n", 1);
	a+=ft_printf("{%*d}\n", -5, 42);
	b+=printf("{%*d}\n", -5, 42);
											write(1, "\n", 1);
	a+=ft_printf("{%*d}\n", 0, 42);
	b+=printf("{%*d}\n", 0, 42);
											write(1, "\n", 1);
	a+=ft_printf("{%*c}\n", 0, 0);
	b+=printf("{%*c}\n", 0, 0);
											write(1, "\n", 1);
	a+=ft_printf("{%*c}\n", -15, 0);
	b+=printf("{%*c}\n", -15, 0);
											write(1, "\n", 1);
	a+=ft_printf("{%.*d}\n", 5, 42);
	b+=printf("{%.*d}\n", 5, 42);
											write(1, "\n", 1);
	a+=ft_printf("{%.*d}\n", -5, 42);
	b+=printf("{%.*d}\n", -5, 42);
											write(1, "\n", 1);
	a+=ft_printf("{%.*d}\n", 0, 42);
	b+=printf("{%.*d}\n", 0, 42);
											write(1, "\n", 1);
	a+=ft_printf("{%.*s||}\n", -5, "42");
	b+=printf("{%.*s||}\n", -5, "42");
											write(1, "\n", 1);
	a+=ft_printf("{%.*s}\n", 0, "42");
	b+=printf("{%.*s}\n", 0, "42");
											write(1, "\n", 1);
	a+=ft_printf("{%3s}\n",  "k");
	b+=printf("{%3s}\n",  "k");
											write(1, "\n", 1);
	a+=ft_printf("{%.*s}\n", 5, "42");
	b+=printf("{%.*s}\n", 5, "42");
											write(1, "\n", 1);
	a+=ft_printf("|% d|\n", 12345);
	b+=printf("|% d|\n", 12345);
											write(1, "\n", 1);
	a+=ft_printf("|% 20d|\n", 12345);
	b+=printf("|% 20d|\n", 12345);
											write(1, "\n", 1);
	a+=ft_printf("|%- 20d|\n", 12345);
	b+=printf("|%- 20d|\n", 12345);
											write(1, "\n", 1);
	a+=ft_printf("(%+20d)\n", 12345);
	b+=printf("(%+20d)\n", 12345);
											write(1, "\n", 1);
											write(1, "\n", 1);
											write(1, "\n", 1);
											write(1, "\n", 1);
											write(1, "\n", 1);
a+=ft_printf("%hhu, %hhu\n", (unsigned char)0, (unsigned char)(UCHAR_MAX + 42));
b+=printf("%hhu, %hhu\n", (unsigned char)0, (unsigned char)(UCHAR_MAX + 42));
											write(1, "\n", 1);
a+=ft_printf("|%p, %p|\n", (void*)0, (void*)0);
b+=printf("|%p, %p|\n", (void*)0, (void*)0);
a+=ft_printf("%p|%p\n", (void*)42, (void*)42);
b+=printf("%p|%p\n", (void*)42, (void*)42);
a+=ft_printf("%hhu / %hhu\n", (unsigned char)(SHRT_MAX - 42), (unsigned char)(SHRT_MAX - 4200));
b+=printf("%hhu / %hhu\n", (unsigned char)(SHRT_MAX - 42), (unsigned char)(SHRT_MAX - 4200));
a+=ft_printf("|%#020X|\n", 874531);
b+=printf("|%#020X|\n", 874531);
a+=ft_printf("|%#020O|\n", 874531);
b+=printf("|%#020O|\n", 874531);
a+=ft_printf("%u\n", (unsigned int)-1);
b+=printf("%u\n", (unsigned int)-1);
a+=ft_printf("%u\n", (unsigned int)4294967296);
b+=printf("%u\n", (unsigned int)4294967296);
a+=ft_printf("%u\n", -1);
b+=printf("%u\n", -1);
a+=ft_printf("%X\n", 1);
b+=printf("%X\n", 1);
a+=ft_printf("%0#20.10X\n", 7896541);
b+=printf("%0#20.10X\n", 7896541);
a+=ft_printf("%-#20.10X\n", 7896541);
b+=printf("%-#20.10X\n", 7896541);
											write(1, "\n", 1);
											write(1, "\n", 1);
a+=ft_printf("%20.*d\n", 3, 42);
b+=printf("%20.*d\n", 3, 42);
											write(1, "\n", 1);
a+=ft_printf("%20hho\n", (char)-42);
b+=printf("%20hho\n", (char)-42);
											write(1, "\n", 1);
a+=ft_printf("%20hhX\n", (char)-42);
b+=printf("%20hhX\n", (char)-42);
											write(1, "\n", 1);
a+=ft_printf("%20hhx\n", (char)-42);
b+=printf("%20hhx\n", (char)-42);
											write(1, "\n", 1);
a+=ft_printf("%20hhu (char)-42\n", (char)-42);
b+=printf("%20hhu (char)-42\n", (char)-42);
											write(1, "\n", 1);
a+=ft_printf("%.9a a\n", (double)2785453.54345);
b+=printf("%.9a a\n", (double)2785453.54345);
											write(1, "\n", 1);
a+=ft_printf("%a a\n", (double)2785453.54345);
b+=printf("%a a\n", (double)2785453.54345);
											write(1, "\n", 1);
											write(1, "\n", 1);
a+=ft_printf("!% 0.6hhi!\n", (char)1147141248);
b+=printf("!% 0.6hhi!\n", (char)1147141248);
											write(1, "\n", 1);
a+=ft_printf("% 0hhi!\n", (char)1147141248);
b+=printf("% 0hhi!\n", (char)1147141248);
											write(1, "\n", 1);
a+=ft_printf("!%u!\n", -1);
b+=printf("!%u!\n", -1);
											write(1, "\n", 1);
a+=ft_printf("%Lf!\n", (long double)999999999999999.999);
b+=printf("%Lf!\n", (long double)999999999999999.999);
											write(1, "\n", 1);
a+=ft_printf("%Lf!\n", (long double)999999999999999999);
b+=printf("%Lf!\n", (long double)999999999999999999);
											write(1, "\n", 1);
a+=ft_printf("|%lx|\n", (unsigned long int)4294967296);
b+=printf("|%lx|\n", (unsigned long int)4294967296);
											write(1, "\n", 1);
a+=ft_printf("%u\n", -1);
b+=printf("%u\n", -1);
											write(1, "\n", 1);
a+=ft_printf("%u\n", (unsigned int)4294967296);
b+=printf("%u\n", (unsigned int)4294967296);
											write(1, "\n", 1);
a+=ft_printf("%hU\n", (unsigned short)4294967296);
b+=printf("%hU\n", (unsigned short)4294967296);
											write(1, "\n", 1);
ft_printf("Aa:%010.5d\n", a);
printf("Bb:%010.5d\n", b);
											write(1, "\n", 1);
a+=ft_printf("{%-30.10d}\n", 967296);
b+=printf("{%-30.10d}\n", 967296);
											write(1, "\n", 1);
a+=ft_printf("{%-30.10d}\n", 967296);
b+=printf("{%-30.10d}\n", 967296);
											write(1, "\n", 1);
long double aaa = 999999999999999999;
a+=ft_printf("{%Lf}\n", aaa);
b+=printf("{%Lf}\n", aaa);
											write(1, "\n", 1);
a+=ft_printf("{%020.25Lf}\n", (long double)-422323.1234567890123);
b+=printf("{%020.25Lf}\n", (long double)-422323.1234567890123);
											write(1, "\n", 1);
a+=ft_printf("{%020.15Lf}\n", (long double)-422323.1234567890999);
b+=printf("{%020.15Lf}\n", (long double)-422323.1234567890999);
											write(1, "\n", 1);
a+=ft_printf("{%-50.15s}\n", "test str auc okwdw");
b+=printf("{%-50.15s}\n", "test str auc okwdw");
											write(1, "\n", 1);
a+=ft_printf("{%-*.15s}\n",0, "okwdw");
b+=printf("{%-*.15s}\n", 0,"okwdw");
											write(1, "\n", 1);
a+=ft_printf("{%-*.*i ld}\n", 30,22,(int)90000008);
b+=printf("{%-*.*i ld}\n", 30,22,(int)90000008);
											write(1, "\n", 1);
a+=ft_printf("{%0*.*llx ld}\n", 30,22,(long long  int)-90000000000008);
b+=printf("{%0*.*llx ld}\n", 30,22,(long long int)-90000000000008);
int c = 0;
int d = 0;
											write(1, "\n", 1);
c+=ft_printf("{%0*.*llx ld}\n", 30,22,(long long  int)-90000000000008);
d+=printf("{%0*.*llx ld}\n", 30,22,(long long int)-90000000000008);
											write(1, "\n", 1);
ft_printf("Aa:%010.5d\n", a);
printf("Bb:%010.5d\n", b);
											write(1, "\n", 1);
a+=ft_printf("{be}%s{defa}%%f336 cccc$%%%%e \\t \t \\ \\  \n \n", "oleee");
b+=printf("{be}%s{defa}%%f336 cccc$%%%%e \\t \t \\ \\  \n \n", "oleee");
											write(1, "\n", 1);
	c+=ft_printf("{}{}{ddd}{blu} \n");
	d+=printf("{}{}{ddd}{blu} \n");
											write(1, "\n", 1);
	a+=ft_printf("{blue}%-10s{default} {red}%s{eoc} {green}%-5s{eoc} %s\n", "Blue","red","green", "default\n");
	b+=printf("%-10s %s %-5s %s\n", "Blue","red","green","default\n");
											write(1, "\n", 1);
	a+=ft_printf("\\ try ,,ef \t %0#40.20llx|\n", (long long)934411193499999999);
	b+=printf("\\ try ,,ef \t %0#40.20llx|\n", (long long)934411193499999999);
											write(1, "\n", 1);
	a+=ft_printf("\\ try ,,ef % 0.20i|\n", (int)0);
	b+=printf("\\ try ,,ef % 0.20i|\n", (int)0);
											write(1, "\n", 1);
ft_printf("Ca:%010.5d\n", d);
printf("Db:%010.5d\n", c);
											write(1, "\n", 1);
ft_printf("Aa:%010.5d\n", a);
printf("Bb:%010.5d\n", b);
/*int y;
int x;
	    y =ft_printf("%.13f et aussi %c fini et puis %.d\n", 0.00003000, 'G', 0);
	    x = printf("%.13f et aussi %c fini et puis %.d\n", 0.00003000, 'G', 0);
	    y =ft_printf("%f et aussi %c fini et puis %.d\n", 0.0001406256066968, 'G', 0);
    x = printf("%f et aussi %c fini et puis %.d\n", 0.0001406256066968, 'G', 0);*/
	return (0);
}
	
