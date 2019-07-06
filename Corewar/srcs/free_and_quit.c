/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:52:53 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/06 15:21:52 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/free_and_quit.h"

static void	free_instruct_label(t_champ *champ)
{
	t_instruct	*ins;
	t_label	*label;

	ins = champ->ins;
	while (ins)
	{
		champ->ins = champ->ins->prev;
		free(ins);
		ins = NULL;
		ins = champ->ins;
	}
	label = champ->label;
	while (label)
	{
		champ->label = champ->label->prev;
		if (label->name)
			free(label->name);
		free(label);
		label = NULL;
		label = champ->label;
	}
}

void	free_and_quit(char *err_msg, t_champ *champ, char *line)
{
	if (line)
		free(line);
	get_next_line(0, NULL, -10, 0);
	if (err_msg && champ)
		printf("ERROR : %s [l.%d]\n", err_msg, champ->nb_line);
	else if (err_msg)
		printf("ERROR : %s\n", err_msg);
	if (champ)
	{
		if (champ->header)
			free(champ->header);
		champ->header = NULL;
		free_instruct_label(champ);
		free(champ);
		champ = NULL;
	}
	exit(-1);
}
