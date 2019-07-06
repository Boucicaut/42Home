/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:52:24 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/06 18:57:09 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/identify_op.h"
#include "../includes/free_and_quit.h"
#include "../includes/del_whitespaces.h"

static int		size_instruct(t_instruct *ins)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 1;
	while (ins->params[i][0] != 0)
		bytes += ins->params[i++][1];
	return (i);
}

static int		set_label_position(t_champ *champ)
{
	t_instruct	*ins;
	int			i;

	i = 0;
	if (!champ->ins)
		return (0);
	ins = champ->ins;
	while (ins)
	{
		i += size_instruct(ins); // New_file ?
		ins = ins->next;
	}
	return (i);
}

static char	*identify_label(t_champ *champ, char *line)
{
	int	i[2];
	t_label	*new_label;

	i[0] = -1;
	i[1] = ft_strlen(line) - ft_strlen(ft_strchr(line, LABEL_CHAR));
	while (line[++i[0]] != LABEL_CHAR)
		if (!(ft_strchr(LABEL_CHARS, line[i[0]])))
			free_and_quit("Invalid label syntax", champ, line);
	if (!(new_label = (t_label*)malloc(sizeof(t_label))))
		free_and_quit("Malloc label failed", champ, line);
	if (!(new_label->name = (char*)malloc(sizeof(char) * (i[1] + 1))))
		free_and_quit("Malloc label->name failed", champ, line);
	new_label->next = NULL;
	new_label->prev = champ->label;
	new_label->position = set_label_position(champ);
	ft_strncpy(new_label->name, line, i[1]);
	if (champ->label)
		champ->label->next = new_label;
	champ->label = new_label;
	printf("\t______________________________________\n\tNew Label :\n\t\tName\t: %s\n\t\tPos\t: %d\n\t______________________________________\n", champ->label->name, champ->label->position);
	return (del_whitespaces(line + i[1] + 1));
}

int		parse_content(t_champ *champ, char *line)
{
	char	*a_line;

	a_line = line;
	if (ft_strchr(line, LABEL_CHAR) && (!ft_strchr(line, DIRECT_CHAR) || ft_strlen(ft_strchr(line, LABEL_CHAR)) > ft_strlen(ft_strchr(line, DIRECT_CHAR))) && (a_line = identify_label(champ, line)))
		if (!a_line || !(*a_line) || a_line[0] == COMMENT_CHAR)
			return (0);
	printf("TO_DO :  |%s|\n", a_line);
	identify_op(champ, a_line, line);
	//printf("TO_DO : Parse_content [l.%d] : %s\n",champ->nb_line, line);
	return (0);
}
