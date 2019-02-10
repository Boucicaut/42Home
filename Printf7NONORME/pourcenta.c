#include "includes/ft_printf.h"

int		pourcenta(va_list args, char *str, int *lim, int *i)
{
	int	d;
	int	h1;
	int	*hh;
	int	i;
	long double vl;
	long double vl2;
	char	*res;
	int		rounding;
	int		printed;
	int		precision;

	vl = (long double)va_arg(args, long double);
	precision = !lim[1] && !lim[8] ? 6 : lim[1];
	vl2 = vl;
	i = -1;
	d = -1;
	//hh = (int*)ft_memalloc(sizeof(int) * precision);
	hh = (int*)malloc(sizeof(int) * precision);
	while (vl2 >= 2.0)
	{
		vl2 = vl;
		vl2 = vl2/(double)ft_tento(2, ++d);		// on sort d, exposant a la fin, *2^d
	}
	h1 = (int)vl2;
	vl2 = vl2 - h1;
//printf("AFTER D }{\tVl : %f\t||\td : %d\t||\th1 : %d\n", vl2, d, h1);
	while (++i < precision)
	{
		vl2 *= 16.0;
		hh[i] = (int)vl2;	// ici on doit check si besoin d'arrondir au dessus
		//hh[i] = ((int)(vl2 * 10.0) * 10) < (int)(vl2 * 100.0) ? (int)vl2 + 1 : (int)vl2;	// ici on doit check si besoin d'arrondir au dessus
//printf("interVl : %d == %d ?\n", (int)(vl2 * 10.0) * 10, (int)(vl2 * 100.0));
//printf("While hh }{\tVl : %f\t||\thh[%d] : %d\n", vl2, i, hh[i]);
		//vl2 -= (int)vl2;
		vl2 -= (int)hh[i];
//printf("\t\tvl apres substraction : %f\n", vl2);
	}
	rounding = (int)(vl2 *= 16.0);
printf("Rounding : %d\n", rounding);
	i = -1;

	res = ft_strnew(2 + 1 + 1 + precision + 1 + 1 + 1 + 1);	// Ox + h1 + . + precision + p + +/- + d + '\0'
//printf("%s | malloced a %d\n", res, 8 + precision);
	res = ft_strcpy(res, "0x");
//printf("%s\n", res);
	res[2] = h1 + '0';
//printf("%s\n", res);
	res[3] = '.';
//printf("%s\n", res);
	while (++i < precision)
		res[4 + i] = hh[i] < 10 ? hh[i] + '0' : hh[i] + 'W';
//printf("%s\n", res);
	res[4 + precision] = 'p';
//printf("%s\n", res);
	res[5 + precision] = '+';
//printf("%s\n", res);
	res[6 + precision] = d + '0';

	if (rounding > 7)
		res[precision + 3] += res[precision + 3] != '9' ? 1 : 40;

	while (str[*i] != 'a' && str[*i] != 'A')
		*i += 1;
	str[*i] == 'a' ? hexatolower(res) : 0;

	printed = doshittythings(lim, res, 0, 'a');
//printf("%s\n", res);

	free(hh);
	return (printed);
}
/*
int	main(void)
{
	pourcenta((double)3.2, 12);
	printf("%.12a\n", 3.2);
write(1, "\n", 1);
	pourcenta((double)3.2, 13);
	printf("%.13a\n", 3.2);
write(1, "\n", 1);
	pourcenta((double)3.2, 14);
	printf("%.14a\n", 3.2);
write(1, "\n", 1);
	pourcenta((double)3.334, 12);
	printf("%.12a\n", 3.334);
write(1, "\n", 1);
	pourcenta((double)3.334, 13);
	printf("%.13a\n", 3.334);
write(1, "\n", 1);
	pourcenta((double)3.334, 14);
	printf("%.14a\n", 3.334);
write(1, "\n", 1);
	pourcenta((double)3.334, 15);
	printf("%.15a\n", 3.334);
write(1, "\n", 1);
	pourcenta((double)3.334, 16);
	printf("%.16a\n", 3.334);
write(1, "\n", 1);
	pourcenta((double)210.1234, 11);
	printf("%.11a\n", 210.1234);
write(1, "\n", 1);
	pourcenta((double)210.1234, 11);
	printf("%.11a\n", 210.1234);
write(1, "\n", 1);
	pourcenta((double)210.1234, 12);
	printf("%.12a\n", 210.1234);
write(1, "\n", 1);
	pourcenta((double)210.1234, 13);
	printf("%.13a\n", 210.1234);
write(1, "\n", 1);
	pourcenta((double)210.1234, 2);
	printf("%.2a\n", 210.1234);
write(1, "\n", 1);
	pourcenta((double)210.1234, 3);
	printf("%.3a\n", 210.1234);
write(1, "\n", 1);
	pourcenta((double)210.1234, 4);
	printf("%.4a\n", 210.1234);
write(1, "\n", 1);
	return (0);
}*/
