/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:56:21 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 20:04:20 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static void		write_name_comment(int fd, t_bot *st, int i)
{
	int			c;
	int			t;

	c = 134;
	t = 2054;
	record_byt(fd, COREWAR_EXEC_MAGIC, 4, 0);
	while (st->name[++i])
		record_byt(fd, st->name[i], 1, 0);
	while (++i < c)
		record_byt(fd, 0, 1, 0);
	record_byt(fd, size_code(st), 4, 0);
	i = 0;
	while (st->comment[++i])
		record_byt(fd, st->comment[i], 1, 0);
	while (++i < t)
		record_byt(fd, 0, 1, 0);
}

void			ftvare(t_var *var, int fd, t_func *func)
{
	var = func->varr;
	record_byt(fd, func->dir, 1, 0);
	func->kode ? record_byt(fd, func->kode, 1, 0) : 0;
	while (var)
	{
		record_byt(fd, var->value, var->rozm, 0);
		var = var->next;
	}
}

static void		writing_command(int fd, t_bot *st, t_func *func, t_var *var)
{
	func = st->func;
	while (func)
	{
		ft_strcmp(func->name, "-1") ? ftvare(var, fd, func) : 0;
		func = func->next;
	}
}

static void		writer(t_bot *st, char *file_name)
{
	int		fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	write_name_comment(fd, st, 0);
	writing_command(fd, st, NULL, NULL);
	ft_putstr("Output program to \n");
	ft_putstr(file_name);
	ft_putstr("\n");
	close(fd);
	ft_strdel(&file_name);
}

void			record_file(t_bot *st, char **str, int i, t_bot *nuch)
{
	char		*file_name;
	int			size_file;
	char		*tmp;

	nuch = st;
	while (str[++i])
	{
		tmp = str[i];
		size_file = ft_strlen(tmp) - 1;
		while (tmp[size_file] && tmp[size_file] != '.')
			size_file--;
		size_file == -1 ? file_name = ft_strdup(tmp) : 0;
		size_file != -1 ? file_name = ft_strndup(tmp, size_file) : 0;
		file_name = new_free(file_name, ".cor", 0);
		file_name[ft_strlen(file_name) - 1] = 0;
		writer(nuch, file_name);
		nuch = nuch->next;
	}
}
