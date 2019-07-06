/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:29:54 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/06 19:32:13 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/free_and_quit.h"
#include "../includes/del_whitespaces.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

char		*identify_op(t_champ *champ, char *a_line, char *line)
{
	int	i;
	t_instruct	*ins;
	char	**args;

	i = 16; // 16 can change ? if yes parse op_tab to get max
	while (--i >= 0)
		if (!(ft_strncmp(a_line, op_tab[i].op, ft_strlen(op_tab[i].op))))
			break ;
	if (i < 0)
		free_and_quit("Invalid syntax instruction", champ, line);
	a_line = del_whitespaces(a_line + ft_strlen(op_tab[i].op));
printf(" -> Valid OP \"%s\"   Args : |%s|\n",op_tab[i].op, a_line);

/*strsplit args */
	int	j;
	j = -1;
	if (!(args = ft_strsplit(a_line, SEPARATOR_CHAR)))
		free_and_quit("Strsplit args failed", champ, line);
	while (args[++j])
		args[j] = del_whitespaces(args[j]);

/* check args */
	j = -1;
	int	jj = -1;
	while (args[++j])
	{
		if (args[j][0] && args[j][0] == 'r') // ON ACCEPTE R0
		{
			if (ft_atoi(&(args[j][1])) >= 0 && ft_atoi(&(args[j][1])) < REG_NUMBER && op_tab[i].params[j] & T_REG)
				printf("\t-> Args[%d] : %s  ==  T_REG\n", j, args[j]);
			else
				free_and_quit("Invalid arg T_REG", champ, line);
		}
		else if (args[j][0] && args[j][0] == DIRECT_CHAR)
		{
			if (args[j][1] && args[j][1] == LABEL_CHAR && op_tab[i].params[j] & T_DIR)
				printf("\t-> Args[%d] : %s  ==  T_LAB(DIR)\n", j, args[j]);
			jj = 0; // ++0 : DIRECT_CHAR
			while (args[j][++jj])
				if (!ft_isdigit(args[j][jj]) && op_tab[i].params[j] & T_IND)
					free_and_quit("Invalid arg T_IND", champ, line);
			//full num
			//valid label
		}
		else
			while (args[j][++jj])
				if (!ft_isdigit(args[j][jj]) && op_tab[i].params[j] & T_IND)
					free_and_quit("Invalid arg T_IND", champ, line);
		/*T_DIR*/
		/*T_IND*/
	}

	j = -1;
	while (args[++j])
		free(args[j]);
	free(args);

/* init new_ins */
	if (!(ins = (t_instruct*)malloc(sizeof(t_instruct))))
		free_and_quit("Malloc instruct failed", champ, line);
	ins->prev = champ->ins;
	ins->next = NULL;
	if (champ->ins)
		champ->ins->next = ins;
	champ->ins = ins;


	return (0);
}
