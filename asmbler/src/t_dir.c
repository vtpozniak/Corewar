/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:56:21 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 20:05:07 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

void			myfunc(int c, char *line, char *buff, t_func **b)
{
	t_var	*a;

	a = (t_var*)malloc(sizeof(t_var));
	if ((*b)->k == 0)
	{
		a->rozm = g_operations[c].mark_size;
		a->value = ft_atoi(line + 1);
		a->name_mark = 0;
		a->bin = 2;
	}
	if ((*b)->k == 1)
	{
		a->rozm = g_operations[c].mark_size;
		a->value = -1;
		a->bin = 2;
		a->name_mark = ft_strdup(buff);
	}
	tetr(&(*b)->varr, a);
}

static void		make_dir(char *line, int c, int i, t_func **b)
{
	char	*buff;

	(*b)->k = 1;
	ft_mtrim(line, ';', COMMENT_CHAR);
	if (i + 1 == g_operations[c].kol_a
			&& ft_strchr(line, COMMENT_CHAR))
		buff = ft_strndup(line + 2, rozm(line + 2, COMMENT_CHAR) - 1);
	else
		buff = ft_strdup(line + 2);
	name_mark(buff, NULL);
	myfunc(c, line, buff, b);
	ft_strdel(&buff);
}

void			myfcg(t_func **b, char *line, int c, int i)
{
	int		j;

	j = 1;
	(*b)->k = 0;
	!ft_isdigit(line[1]) && line[1] != '-' ?
	error_message("not true value '%'", line) : 0;
	line[1] == '-' ? j++ : 0;
	while (line[j] && ft_isdigit(line[j]))
		j++;
	i + 1 != g_operations[c].kol_a && line[j] != 0 ?
	error_message("not valid symbol near 't_ind'", line) : 0;
	i + 1 == g_operations[c].kol_a ? chk_error(line + j) : 0;
	myfunc(c, line, NULL, b);
}

void			t_dir(char *line, int c, int i, t_func **b)
{
	line[1] == LABEL_CHAR ? make_dir(line, c, i, b) : 0;
	line[1] != LABEL_CHAR ? myfcg(b, line, c, i) : 0;
}
