#include "libft.h"
#include <stdio.h>

int	checkzerodec(double nb, int i)
{
	i = 16 - i;
	while (i > 0)
	{
		nb = nb * 10;
		if ((int)nb > 0)
			return (1);
		i--;
	}
	return (0);
}

double	numb(int i)
{
	double	n;
	n = 0.9;
	while (++i < 14) // ++, dot -> +2 donc 14 + 2 == 16
		n = (n / 10) + 0.9; // max 16 / 17 digits pour un double
//printf("Last n : %.20f\n", n);
	return (n);
}

int	afterdot(int i, double nb)
{
	int	j;

	j = 0;
	//while (nb == 0 || nb >= 0.0000000000000000000000000000001 || nb - (int)nb > 1)
	while (j + i < 17 && (((int)(nb * 10)) % 10 != 0 || checkzerodec(nb, i + j) == 1))
	{
		nb = (nb * 10);
		if ((nb = nb - ((int)nb)) > numb(i + j)) //!!! attention mais si test avec 304.003405451 
		{
			//nb--; // print valeur rounded (le 17e caractere)
			j++;
			return (j + i);
		}
		j++;
	}
	return (j + i);
}

/************************************************************************************/

int		needtodecrement(double nb) /* si les crap digits font +1 lors du cast , on check si que des 0 dans les 16 premiers digits*/
{
	double	nbdel;

	nbdel = nb;
	nbdel = nbdel - (int)nb;
	printf("nbdel... : %f\n", nbdel - (int)nb);
	if (nbdel < 0)
		return (1);
	return (0);
}

int	ismaxint(double nb, char mode)	/* enlever la partie au dessus de max int et compter son nb  */
{
	int		i;
printf("Nb entree ismaxint : %f\n", nb);
	i = 0;
	while (nb > 2147483647)
	{
printf("ISMAXINT **  nb : %f , i : %d\n", nb, i);
		i++;
		nb = nb / 10;
		if (mode == 'z' && needtodecrement(nb) == 1)
		{
			printf("NeedtoDecre OK\n");
			i--;
		}
	}
	i = i < 0 ? 0 : i;
	printf("i fin ismaxint : %d\n", i);
	return (i);
}

double	newdoublemaxint(double nb) /* nouveau double nb qui convient en int  */
{
	while (nb > 2147483647)
		nb = nb / 10;
	return (nb);
}

int		nbdenb(int nb, int base)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / base;
	}
	return (i);
}

int		getdecimals(double nb, int id, int max, int base)
{
	int	idsave;
	int	iz;

	iz = 0;
	idsave = id;
	nb = nb / ft_tento(10, id); /* 0.xxx */
	
printf("nb START getdec : %.15f\n", nb);
	while (id-- > 0)
	{
		nb = nb * 10;
		nb = nb - (int)nb;
printf("id : %d || nb current : %.15f\n",id, nb);
	}
printf("Nb before tento : %.20f\n", nb);
	nb = nb * ft_tento(10, max - (idsave));
printf("Nb after tento : %.20f\n", nb); /* ici on a soit des 0 a la fin si nb < 16 digits, sinon du crap || les 9 s'ils sont la sont en case 17 et avant si digits total < 16 					on a donc 16 digits ds tt les cas*/


printf("ismaxint de nb : %d\n", ismaxint(nb, 'z'));
	if ((iz = ismaxint(nb, 'z')))
	 	nb = (int)newdoublemaxint(nb);
	iz = 0;
	while ((int)nb % 10 == 0 || (int)nb % 10 == 9)
	{
		printf("DEL 0 ou 9\n");
		nb = nb / 10;
	}
printf("Nb after deleting all 0 if nb digits < 16 : %f\n", nb);

printf("HEKKKK POUR LA PARTIE ZZZZZZZZZZ\n");

/* Attention pour la convertion en int qui peut faire +1 */
	nb = (int)nb;
	if (needtodecrement(nb))
	{
		printf("DECREMENTED\n");
		nb--;
	}

printf("iz : %d && new nbd : %d\n", iz, (int)nb);
	while ((int)nb % 10 == 9)
	{
		nb = (int)nb / 10;
		iz--;
	}
	iz--;		/* ??????????????????????????*/
	iz = iz + nbdenb(nb, base);	
	return (iz);
}

int	sizenbchar(int base, double nb, char mode)
{
	int		id;
	int		iz;
	int		nbd;
	int		nbz;
	int		max;

	if (mode == 'f' || mode == 'z') 
		max = 16;
	else if (mode == 'h') /* POUR LES FLOATS ? qui ont un max plus petit ? */
		max = 7;
	iz = 0;
	id = 0;
	nb == 0 ? nb = 1 : nb;
	nbz = nb;
	nbd = 0;
printf("Nb studied : %.10f\n", nb);
	if ((id = ismaxint(nb, 'd')) > 0)
	{
		nbd = (int)newdoublemaxint(nb);
		printf("Nb > max int, new : %d\n", nbd);
	}
	else
		nbd = (int)nb;
printf("ID before new int : %d\n", id);
	/* partie gauche */
	id = id + nbdenb(nbd, base);
printf("ID after new int : %d\n", id);
printf("____________FIN ID______________\n");
	if (mode == 'd')
		return (id);

	/* partie droite */
	iz = getdecimals(nb, id, max, base);
	printf("IZ After all : %d\n", iz);
printf("____________FIN IZ______________\n");
	if (mode == 'z')
		return (iz);
	return (id + iz);
}

int	main(int argc, char **argv)
{
(void)argc;
(void)argv;

/* Comportement :
 * si on depasse 16 avec d et z, on renvoie le complement z pour aller jusqu'a 16, pour l'affichage on devra seulement arrondir ++ le 16e caractere (y compris si d = 16)
 * si
 * */
			/* si on stipule plus que 16 dans le printf on arrondit pas du tout et on affiche du crap */
			/* si on ......  moins que 16 ou 16 pile on doit arrondir suivant le chiffre d'apres */
printf("nb : %40.9f\n\n", 9999999928.22 ); // si 16d alors pas de z et on arrondit le dernier d
printf("nb : %30.9f\n\n", 99999999.77 ); // si 15d on affiche un z, + 1 crap on arrondit le z et d si 9 
printf("nb : %40.20f\n\n",999999.33333333339 );		// si on est large pour d et >16 sur z,  
printf("nb : %40.20f\n\n",999999992148.2238 );
printf("nb : %16.9f\n\n",999999.222222222 );
	printf("        total 11: %d******************************\n", sizenbchar(10, 879999.32301, 'f'));
	printf("        z     12: %d******************************\n", sizenbchar(10, 9.323223244444, 'z'));
	printf("        z     11: %d******************************\n", sizenbchar(10, 999.32327777579, 'z'));
	printf("        qte  3: %d*******************************\n", sizenbchar(10, 999.32322327, 'd'));
/*
printf("nb : 999.22321234234\n");
	printf("        total 14: %d\n", sizenbchar(10, 999.22321234234, 'f'));
	printf("        qte2  5: %d\n", sizenbchar(10, 999.22321234234, 'z'));
	printf("        qte  12: %d\n", sizenbchar(10, 999.22321234234, 'd'));

printf("nb : 8.001\n");
	printf("        total 16: %d\n", sizenbchar(10, 8.001, 'f'));
	printf("        qte2  4: %d\n", sizenbchar(10, 8.001, 'z'));
	printf("        qte  12: %d\n", sizenbchar(10, 8.001, 'd'));

printf("nb : 1.56454545654622321\n");
	printf("        total 18: %d\n", sizenbchar(10, 1.56454545654622321, 'f'));
	printf("        qte2 17: %d\n", sizenbchar(10, 1.56454545654622321, 'z'));
	printf("        qte2  1: %d\n", sizenbchar(10, 1.56454545654622321, 'd'));*/
	return (0);
}

/* test avec les 9999 venant apres le 1 qui est 0 dans le double
	printf("total 7: %d\n", sizenbchar(10, 0, 304.003405451, 'f'));*/
