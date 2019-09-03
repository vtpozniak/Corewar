/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:56:21 by vpozniak          #+#    #+#             */
/*   Updated: 2019/09/03 18:56:34 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

void	tetr(t_var **st, t_var *b)
{
	t_var	*nuch;

	nuch = *st;
	if (!*st)
	{
		b->next = *st;
		*st = b;
	}
	else
	{
		while (nuch->next)
			nuch = nuch->next;
		nuch->next = b;
		b->next = 0;
	}
}

void	chk_error(char *line)
{
	int	i;

	i = 0;
	ft_mtrim(line, ';', COMMENT_CHAR);
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR)
			break ;
		else if (line[i] != ' ' && line[i] != '\t')
			error_message("Error", line);
		i++;
	}
}

void	error_message(char *line, char *error)
{
	(error) ? ft_putstr(error) : 0;
	ft_putstr("\n");
	ft_putstr(line);
	ft_putstr("\n");
	exit(0);
}

void	free_matr(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		ft_strdel(&matrix[i]);
	free(matrix);
	matrix = 0;
}

void	name_mark(char *line, char *nuch)
{
	nuch = line;
	while (*nuch)
	{
		if (!ft_strchr(LABEL_CHARS, *nuch))
		{
			ft_putstr("forbidden in mark\n");
			ft_putstr(nuch);
			error_message("", line);
		}
		nuch++;
	}
}
