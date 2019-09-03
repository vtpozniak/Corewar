/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_com.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:34:58 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 20:01:35 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static int	search_com(char *line, int i, char *name, char *buff)
{
	char	zn;

	zn = ' ';
	ft_mtrim(line, '\t', ' ');
	while (line[++i])
		if (line[i] == DIRECT_CHAR || line[i] == ' ')
			break ;
	line[i] == DIRECT_CHAR ? zn = DIRECT_CHAR : 0;
	buff = ft_strndup(line, rozm(line, zn) - 1);
	name = ft_strtrim(buff);
	i = -1;
	while (zn != -1 && g_operations[++i].name)
		!ft_strcmp(g_operations[i].name, name) ? zn = -1 : 0;
	ft_strdel(&buff);
	ft_strdel(&name);
	if (zn == -1)
		return (i);
	error_message("Invalid command", line);
	return (-1);
}

static int	colvo_ag(t_func *func)
{
	t_var	*vars;
	int		kol_a;

	vars = func->varr;
	kol_a = 0;
	while (vars)
	{
		kol_a++;
		vars = vars->next;
	}
	return (kol_a);
}

static void	upr_argument(t_func *func, int num_func, char *line)
{
	int	q;

	q = colvo_ag(func);
	g_operations[num_func].kol_a > q ? error_message("sprat vars", line) : 0;
	g_operations[num_func].kol_a < q ? error_message("many vars", line) : 0;
	!q ? error_message("not vars", line) : 0;
}

static void	check_coms(char *line, int func, char *nuch, int count)
{
	char	**mass;

	while (*nuch && *nuch != ';' && *nuch != COMMENT_CHAR)
	{
		if (*nuch == SEPARATOR_CHAR)
			count++;
		nuch++;
	}
	count > g_operations[func].kol_a ? error_message("further ','", line) : 0;
	count < g_operations[func].kol_a ? error_message("sprat ','", line) : 0;
	mass = ft_strsplit(line, SEPARATOR_CHAR);
	count = -1;
	while (count != -2 && mass[++count] && !ft_strchr(mass[count], ';')
			&& !ft_strchr(mass[count], COMMENT_CHAR))
		ft_count_word(mass[count], ' ') > 1 ||
				ft_count_word(mass[count], '\t') > 1 ? count = -2 : 0;
	free_matr(mass);
	count == -2 ? error_message("Bad commas", line) : 0;
}

void		check_com(char *line, t_bot **bot, t_mark *marks, int func)
{
	t_func	*fk;

	if (!ft_strlen(line))
		return ;
	while (*line && (*line == '\t' || *line == ' '))
		line++;
	func = search_com(line, -1, NULL, NULL);
	line += ft_strlen(g_operations[func].name);
	fk = (t_func*)malloc(sizeof(t_func));
	check_coms(line, func, line, 1);
	fk->name = ft_strdup(g_operations[func].name);
	fk->varr = 0;
	fk->kode = g_operations[func].kode;
	check_argument(line, &fk, func);
	upr_argument(fk, func, line);
	fk->marks = marks;
	fk->dir = g_operations[func].dir;
	end_com(bot, fk);
}
