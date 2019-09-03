/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:18:35 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 20:03:11 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static int	srv(char *line, char *nuch, int i)
{
	nuch = line;
	while (*nuch && (*nuch == '\t' || *nuch == ' '))
		nuch++;
	if (*nuch == COMMENT_CHAR || *nuch == ';')
		return (0);
	while (*nuch)
	{
		i = -1;
		while (SYMBOL[++i])
			if (*nuch == SYMBOL[i])
				return (1);
		nuch++;
	}
	return (0);
}

static int	add_mark(char *line, t_mark **b, int i, t_mark *mark)
{
	char	*nuch;
	char	*buff;
	int		k;

	ft_mtrim(line, '\t', ' ');
	nuch = line;
	while (*nuch && *nuch == ' ')
		nuch++;
	while (nuch[++i] && nuch[i] != LABEL_CHAR)
		if (!ft_strchr(line, LABEL_CHAR) || nuch[i] == ' ' ||
				nuch[i] == '%' || nuch[i] == '#' || nuch[i] == ';')
			return (0);
	buff = ft_strndup(nuch, rozm(nuch, LABEL_CHAR) - 1);
	mark = (t_mark*)malloc(sizeof(t_mark));
	mark->name = ft_strtrim(buff);
	!ft_strlen(mark->name) ? error_message("No mark name", line) : 0;
	ft_strdel(&buff);
	name_mark(mark->name, NULL);
	mark->next = *b;
	*b = mark;
	k = rozm(line, LABEL_CHAR);
	return (k);
}

static void	end_file(t_bot **st, t_mark *mark)
{
	t_func	*b;

	b = (t_func*)malloc(sizeof(t_func));
	b->name = ft_strdup("-1");
	b->marks = mark;
	b->varr = 0;
	end_com(st, b);
}

static void	p_mas(char **mass, t_bot **st, int *p, int i)
{
	t_mark			*marks;
	char			*line;

	marks = 0;
	while (mass[++i])
	{
		line = mass[i];
		line += add_mark(line, &marks, -1, NULL);
		if (ft_strlen(line) && !srv(line, NULL, -1))
			chk_error(line);
		else if (ft_strlen(line))
			break ;
	}
	*p = i;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	ft_strlen(line) && (i == (int)ft_strlen(line) || !srv(line, NULL, -1)) ?
	chk_error(line) : check_com(line, st, marks, 0);
	if (marks && (i == (int)ft_strlen(line) || !srv(line, NULL, -1)))
		end_file(st, marks);
}

void		check_val(int fd, t_bot **st, char **mass, char *n)
{
	int		i;

	i = 0;
	mass = pars_nc(fd, st, NULL, n);
	while (mass[i])
	{
		if (!srv(mass[i], NULL, -1))
			chk_error(mass[i]);
		else
			p_mas(mass, st, &i, i - 1);
		if (!mass[i])
			break ;
		i++;
	}
	free_matr(mass);
}
