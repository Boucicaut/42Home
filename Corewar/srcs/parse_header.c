/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:52:34 by bviollet          #+#    #+#             */
/*   Updated: 2019/07/04 19:49:41 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/free_and_quit.h"
#include "../includes/read_asmfile.h"

static int		len_doublequote(char *line, int i)
{
	int	len;

	len = 0;
	while (line && line[i] && line[i] != '"')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (-1);
		i++;
	}
	len = ++i;
	while (line && line[i] && line[i] != '"')
		i++;
	len = i - len;
	while (line && line[++i])
		if (line[i] != ' ' && line[i] != '\t')
			return (-1);
	return (len);
}

static int		valid_header_name_comment(t_champ *champ, char *line)
{
	int	len;

	if (!(ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))))
	{
		if ((len = len_doublequote(line, ft_strlen(NAME_CMD_STRING))) == -1)
			free_and_quit("Invalid syntax", champ, line);
		if (len > PROG_NAME_LENGTH)
			free_and_quit("Name too long", champ, line);
		if (champ->header->prog_name[0] != '\0')
			free_and_quit("Double name header", champ, line);
		return (1);
	}
	else if (!(ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))))
	{
		if ((len = len_doublequote(line, ft_strlen(COMMENT_CMD_STRING))) == -1)
			free_and_quit("Invalid syntax", champ, line);
		if (len > COMMENT_LENGTH)
			free_and_quit("Comment too long", champ, line);
		if (champ->header->comment[0] != '\0')
			free_and_quit("Double comment header", champ, line);
		return (2);
	}
	return (0);
}

int		parse_header(t_champ *champ, char *line)
{
	if (valid_header_name_comment(champ, line) == 1)
		ft_strcpy(champ->header->prog_name, ft_strchr(line, '"'));
	else if (valid_header_name_comment(champ, line) == 2)
		ft_strcpy(champ->header->comment, ft_strchr(line, '"'));
	else
	{
		if (champ->header->prog_name[0] == '\0' && champ->header->comment[0] == '\0')
			free_and_quit("Invalid syntax, a name and a comment are required", champ, line);
		else if (champ->header->prog_name[0] == '\0')
			free_and_quit("Invalid syntax, a name is required", champ, line);
		else if (champ->header->comment[0] == '\0')
			free_and_quit("Invalid syntax, a comment is required", champ, line);
	}
	return (0);
}
