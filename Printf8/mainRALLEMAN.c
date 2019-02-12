/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralleman <ralleman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 14:32:43 by ralleman          #+#    #+#             */
/*   Updated: 2019/02/11 14:36:19 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int 	main()
{
	int		x;
	int		i;
	void	*p;
	int		y;
	float	f;
	long double lf;

	p = realloc;
	i = 1;
	f = 6;
	lf = 900.603665;

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y = ft_printf("Test avec %d et aussi %c fini\n", -42, 'G');
	x = printf("Test avec %d et aussi %c fini\n", -42, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %d et aussi %c fini\n", 42, 'G');
	x = printf("Test avec %d et aussi %c fini\n", 42, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y = ft_printf("Test avec %s et aussi %c fini\n", "que onda che", 'G');
	x = printf("Test avec %s et aussi %c fini\n", "que onda che", 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y = ft_printf("Test avec %19s et aussi %c fini\n", "que onda che", 'G');
	x = printf("Test avec %19s et aussi %c fini\n", "que onda che", 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y = ft_printf("Test avec %19.4s et aussi %c fini\n", "que onda che", 'G');
	x = printf("Test avec %19.4s et aussi %c fini\n", "que onda che", 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");


	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y = ft_printf("Test avec %-9.4d et aussi %c fini\n", -42, 'G');
	x = printf("Test avec %-9.4d et aussi %c fini\n", -42, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec % d et aussi %c fini\n", 728, 'G');
	x = printf("Test avec % d et aussi %c fini\n", 728, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-d et aussi %c fini\n", -42, 'G');
	x = printf("Test avec %-d et aussi %c fini\n", -42, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-4.5d et aussi %c fini\n", -42, 'G');
	x = printf("Test avec %-4.5d et aussi %c fini\n", -42, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-4.1d et aussi %c fini\n", -42968, 'G');
	x = printf("Test avec %-4.1d et aussi %c fini\n", -42968, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %o et aussi %c fini\n", 3568, 'G');
	x = printf("Test avec %o et aussi %c fini\n", 3568, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %.9o et aussi %c fini\n", 3568, 'G');
	x = printf("Test avec %.9o et aussi %c fini\n", 3568, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-12.9o et aussi %c fini\n", 3568, 'G');
	x = printf("Test avec %-12.9o et aussi %c fini\n", 3568, 'G');
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %#o et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	x = printf("Test avec %#o et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-#12o et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	x = printf("Test avec %-#12o et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %#12.2o et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	x = printf("Test avec %#12.2o et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %#x et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	x = printf("Test avec %#x et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %9.8x et aussi %c fini et puis %.d\n", 8598, 'G', 0);
	x = printf("Test avec %9.8x et aussi %c fini et puis %.d\n", 8598, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %#X et aussi %c fini et puis %.d\n", 58742, 'G', 0);
	x = printf("Test avec %#X et aussi %c fini et puis %.d\n", 58742, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-#19.9X et aussi %c fini et puis %.d\n", 15582, 'G', 0);
	x = printf("Test avec %#-19.9X et aussi %c fini et puis %.d\n", 15582, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %#9.8X et aussi %c fini et puis %.d\n", 0, 'G', 0);
	x = printf("Test avec %#9.8X et aussi %c fini et puis %.d\n", 0, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");
	ft_putchar('\n');

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-9.8x et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	x = printf("Test avec %-9.8x et aussi %c fini et puis %.d\n", 3568, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %p et aussi %c fini et puis %.d\n", p, 'G', 0);
	x = printf("Test avec %p et aussi %c fini et puis %.d\n", p, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %% et aussi %c fini et puis %.d\n", 'G', 0);
	x = printf("Test avec %% et aussi %c fini et puis %.d\n", 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %u et aussi %c fini et puis %.d\n", 258, 'G', 0);
	x = printf("Test avec %u et aussi %c fini et puis %.d\n", 258, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-27.0f et aussi %c fini et puis %.d\n", -372.606256066, 'G', 0);
	x = printf("Test avec %-27.0f et aussi %c fini et puis %.d\n", -372.606256066, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %#-27.0f et aussi %c fini et puis %.d\n", -372.606256066, 'G', 0);
	x = printf("Test avec %#-27.0f et aussi %c fini et puis %.d\n", -372.606256066, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-27.0f et aussi %c fini et puis %.d\n", 32.606256066, 'G', 0);
	x = printf("Test avec %-27.0f et aussi %c fini et puis %.d\n", 32.606256066, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %#-27.0f et aussi %c fini et puis %.d\n", 372.506256066, 'G', 0);
	x = printf("Test avec %#-27.0f et aussi %c fini et puis %.d\n", 372.506256066, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %.13f et aussi %c fini et puis %.d\n", 0.00003000, 'G', 0);
	x = printf("Test avec %.13f et aussi %c fini et puis %.d\n", 0.00003000, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-f et aussi %c fini et puis %.d\n", 0.0001406256066968, 'G', 0);
	x = printf("Test avec %-f et aussi %c fini et puis %.d\n", 0.0001406256066968, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %27.4f et aussi %c fini et puis %.d\n", 372.406256066968, 'G', 0);
	x = printf("Test avec %27.4f et aussi %c fini et puis %.d\n", 372.406256066968, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %.8f et aussi %c fini et puis %.d\n", 3.777777777, 'G', 0);
	x = printf("Test avec %.8f et aussi %c fini et puis %.d\n", 3.777777777, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %0#27.16Lf et aussi %c fini et puis %.d\n", lf, 'G', 0);
	x = printf("Test avec %0#27.16Lf et aussi %c fini et puis %.d\n", lf, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %019.10f et aussi %c fini et puis %.d\n", -10.00003000, 'G', 0);
	x = printf("Test avec %019.10f et aussi %c fini et puis %.d\n", -10.00003000, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %-+9.Lf et aussi %c fini et puis %.d\n", lf, 'G', 0);
	x = printf("Test avec %-+9.Lf et aussi %c fini et puis %.d\n", lf, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");

	printf("===============  \033[31mTEST %d\033[0m  ===============\n\n", i++);
	y =ft_printf("Test avec %.13f et aussi %c fini et puis %.d\n", 3.1234567890122, 'G', 0);
	x = printf("Test avec %.13f et aussi %c fini et puis %.d\n", 3.1234567890122, 'G', 0);
	printf("retour de mon printf = \033[36m%d\033[0m\n", y);
	printf("retour de printf = \033[36m%d\033[0m\n", x);
	y == x ? printf(">>>>>>>>>>>>>>>  \033[32mOK\033[0m  <<<<<<<<<<<<<<<\n\n") : printf(">>>>>>>>>>>>>>>  \033[33mFAIL\033[0m  <<<<<<<<<<<<<<<\n\n");


	return(0);
}
