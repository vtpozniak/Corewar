/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_nc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:56:21 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 20:03:53 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static int	is_comment(char *fl, char *nuch, int i)
{
	int		q;

	q = 0;
	nuch = fl;
	while (nuch[i] && (nuch[i] == ' ' || nuch[i] == '\t'))
		i++;
	if (nuch[i] == COMMENT_CHAR || nuch[i] == ';')
		q = 1;
	return (q);
}

int			tmprt(char **buff, char *fl, int size, int fd)
{
	int		i;

	i = 0;
	while (!kop(fl, buff, ft_strlen(*buff), size))
	{
		i += get_next_line(fd, &fl);
		!fl ? error_message("No '\"' symbol", *buff) : 0;
	}
	return (i);
}

static char	*write_in_str(char *fl, int fd, int size, int i)
{
	int		ot;
	char	*buff;

	ot = 4;
	buff = ft_strdup("\"");
	size == COMMENT_LENGTH ? ot = 7 : 0;
	fl[rozm(fl, '.') + ot] != ' ' && fl[rozm(fl, '.') + ot] != '"'
		&& fl[rozm(fl, '.') + ot] != '\t' ?
		error_message("function not found", 0) : 0;
	i = rozm(fl, '.') + ot - 1;
	while (fl[++i] && fl[i] != '"')
		fl[i] != ' ' && fl[i] != '\t' ?
			error_message("Error", fl) : 0;
	!ft_strchr(fl, '"') ? error_message("No name or no comment", fl) : 0;
	i = tmprt(&buff, fl, size, fd);
	!i ? chk_error(fl + rozm(fl, '"') + ft_strlen(buff))
	: chk_error(fl + rozm(fl, '"'));
	return (buff);
}

static char	*chek_nc(int fd, int size, char *func, int error)
{
	char	*fl;
	char	*nuch;
	char	*str;

	while ((error = get_next_line(fd, &fl)) > 0)
	{
		if (!ft_strstr(fl, func))
			chk_error(fl);
		else if (ft_strstr(fl, func) && !is_comment(fl, NULL, 0))
			break ;
		ft_strdel(&fl);
	}
	!error ? error_message("Blank document", 0) : 0;
	error == -1 ? error_message("No .s file", 0) : 0;
	!fl ? error_message("No name or no comment", 0) : 0;
	nuch = fl;
	while (*nuch && (*nuch == ' ' || *nuch == '\t'))
		nuch++;
	ft_strncmp(nuch, func, rozm(nuch, ' ') - 1) &&
			ft_strncmp(nuch, func, rozm(nuch, '\t') - 1)
			&& ft_strncmp(nuch, func, rozm(nuch, '"') - 1) ?
			error_message("function not found", nuch) : 0;
	str = write_in_str(nuch, fd, size, 0);
	return (str);
}

char		**pars_nc(int fd, t_bot **st, char *fl, char *n)
{
	char	**mass;
	char	*str;

	str = ft_memalloc(1);
	(*st)->name = chek_nc(fd, PROG_NAME_LENGTH, NAME_CMD_STRING, 0);
	(*st)->comment = chek_nc(fd, COMMENT_LENGTH, COMMENT_CMD_STRING, 0);
	while (get_next_line(fd, &fl))
		str = new_free(str, fl, 1);
	mass = ft_strsplit(str, '\n');
	ft_end(NULL, fl, n);
	ft_strdel(&str);
	return (mass);
}
