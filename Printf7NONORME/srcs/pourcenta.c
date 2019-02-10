#include "../includes/ft_printf.h"

void	hexatoupper(char *res)
{
	int	j;

	j = 0;
	while (res[j])
	{
		res[j] = ft_toupper(res[j]);
		j++;
	}
}

int		pourcenta(va_list args, char *str, int *lim, int *i)
{
	int	d;
	int	dd;
	int	h1;
	int	*hh;
	int	j;
	int	jj;
	long double vl;
	long double vl2;
	char	*res;
	int		rounding;
	int		printed;

	printed = 0;
	lim[6] = 1;
	rounding = 0;
	j = *i;
	vl = islongornot(str, j, 'a') ? va_arg(args, long double) : va_arg(args, double);
	lim[7] = vl < 0 ? 1 : lim[7];
	vl = vl < 0 ? -vl : vl;
//printf("Value : %Lf || NegLim7 : %d\n", vl, lim[7]);
//printf("Lim1 : %d, lim8 : %d\n", lim[1], lim[8]);
	lim[1] = !lim[1] && !lim[8] ? 13 : lim[1];
//printf("Lim1 : %d, lim8 : %d\n", lim[1], lim[8]);
	vl2 = vl;
	j = -1;
	d = -1;
	//hh = (int*)ft_memalloc(sizeof(int) * precision);
	hh = (int*)malloc(sizeof(int) * lim[1]);
	while (vl2 >= 2.0)
	{
		vl2 = vl;
		vl2 = vl2/(double)ft_tento(2, ++d);		// on sort d, exposant a la fin, *2^d
	}
	h1 = (int)vl2;
	vl2 = vl2 - h1;
//printf("AFTER D }{\tVl : %f\t||\td : %d\t||\th1 : %d\n", vl2, d, h1);
	//while (++j < lim[1] || (!lim[8] && ((int)(vl2 * 10.0) == ((int)vl2 * 10)) && ((int)vl2 * 100.0) == ((int)vl2 * 100))) // lim[8] || rounding < 8 dans le cas ou lim1 default
	while (++j < lim[1])	// lim[8] || rounding < 8 dans le cas ou lim1 default
	{
		vl2 *= 16.0;
		hh[j] = (int)vl2;	// ici on doit check si besoin d'arrondir au dessus
		//hh[j] = ((int)(vl2 * 10.0) * 10) < (int)(vl2 * 100.0) ? (int)vl2 + 1 : (int)vl2;	// ici on doit check si besoin d'arrondir au dessus
//printf("interVl : %d == %d ?\n", (int)(vl2 * 10.0) * 10, (int)(vl2 * 100.0));
//printf("While hh }{\tVl : %Lf\t||\thh[%d] : %d\n", vl2, j, hh[j]);
		//vl2 -= (int)vl2;
		vl2 -= (int)hh[j];
		rounding = (int)(vl2 * 16.0);
//printf("Rounding : %d\n", rounding);
//printf("Condition while, %Lf : %d | %d ((=)) %d\n",vl2, (int)(vl2 * 1000.0) / 1000, (int)vl2, (lim[8] && ((int)(vl2 * 1000.0) / 1000) != (int)vl2));
//printf("\t\tvl apres substraction : %f\n", vl2);
	}
//printf("Condition while, %Lf : %d | %d ((=)) %d\n",vl2, (int)(vl2 * 1000.0) / 1000, (int)vl2, (lim[8] && ((int)(vl2 * 1000.0) / 1000) != (int)vl2));

	while (str[*i] && str[*i] != 'a' && str[*i] != 'A')
		*i += 1;
	lim[7] && lim[2] && !lim[4] && lim[0] > (lim[1] + lim[7] + 6 + ft_qtenb(d, 'd', 10, 50)) ? ft_putchar('-') : 0;
	lim[6] && lim[2] && !lim[4] && lim[0] > (lim[1] + lim[7] + 6 + ft_qtenb(d, 'd', 10, 50)) ? ft_putchar('0'), ft_putchar(str[*i] + 23) : 0;
	while (!lim[4] && lim[0] > (lim[1] + lim[7] + 5 + ft_qtenb(d, 'd', 10, 50)))
	{
		lim[2] ? ft_putchar('0') : ft_putchar(' ');
		printed++;
		lim[0]--;
	}
	lim[7] && !lim[4] && !lim[2] /*&& lim[0] > (lim[1] + lim[7] + 6 + ft_qtenb(d, 'd', 10, 50))*/ ? ft_putchar('-') : 0;
	lim[6] && !lim[4] && !lim[2] /*&& lim[0] > (lim[1] + lim[7] + 6 + ft_qtenb(d, 'd', 10, 50))*/ ? ft_putchar('0'), ft_putchar(str[*i] + 23) : 0;

	res = ft_strnew(lim[7] + 2 + 1 + 1 + lim[1] + 1 + 1 + 1 + 1);	// Ox + h1 + . + precision + p + +/- + d + '\0'
//printf("%s | malloced a %d\n", res, 8 + precision);
	//res = lim[7] ? ft_strcpy(res, "-0x") : ft_strcpy(res, "0x");
	//jj = lim[7] ? 3 : 2;
	jj = 0;
	j = -1;
//printf("%s || jj : %d 0x\n", res, jj);
	res[jj++] = h1 < 10 ? h1 + '0' : h1 + 'W';
//printf("%s || jj : %d 1\n", res, jj);
	res[jj++] = lim[8] && !lim[1] ? '\0' : '.';
	jj -= lim[8] && !lim[1] ? 1 : 0;
//printf("%s || jj : %d .\n", res, jj);
	while (++j < lim[1])
		res[jj + j] = hh[j] < 10 ? hh[j] + '0' : hh[j] + 'W';
//printf("%s || jj : %d\n", res, jj);
	jj += j;
//printf("%s || jj : %d +=j\n", res, jj);
	res[jj++] = 'p';
//printf("%s || jj : %d P\n", res, jj);
	res[jj++] = '+';
//printf("%s || jj : %d\n", res, jj);
	j = ft_qtenb(d, 'd', 10, 50);
	dd = d;
	while (j > 0)
	{
//printf("J : %d jj : %d || d : %d\n", j,jj, d);
		res[jj + --j] = (d % 10) + '0';
		d /= 10;
	}
	if (rounding > 7)
		res[lim[1] + 1] += res[lim[1] + 1] != '9' ? 1 : 40;
	while (str[*i] != 'a' && str[*i] != 'A')
		*i += 1;
	str[*i] == 'A' ? hexatoupper(res) : 0;

	printed += (int)ft_strlen(res);
	//lim[7] && lim[4] /*&& lim[0] > (lim[1] + lim[7] + 6 + ft_qtenb(d, 'd', 10, 50))*/ ? ft_putchar('-') : 0;
	lim[6] && lim[4] /*&& lim[0] > (lim[1] + lim[7] + 6 + ft_qtenb(d, 'd', 10, 50))*/ ? ft_putchar('0'), ft_putchar(str[*i] + 23) : 0;
	ft_putstr(res);
	while (lim[4] && lim[0] > (lim[1] + lim[7] + 5 + ft_qtenb(dd, 'd', 10, 50)))
	{
		ft_putchar(' ');
		printed++;
		lim[0]--;
	}
	printed += lim[7] + 2;
//printf("%s\n", res);

	free(hh);
	return (printed);
}
