/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:12:35 by vpozniak          #+#    #+#             */
/*   Updated: 2019/09/03 18:56:20 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

char		*read_block(char *n)
{
	int		file;
	char	c;
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(n, O_RDONLY);
	if ((file = read(fd, &c, 1)) < 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * 100000000);
	while (file != '\0')
	{
		str[i] = c;
		i++;
		file = read(fd, &c, 1);
	}
	str[i] = '\0';
	return (str);
}

void		ft_end(char *tmp, char *fl, char *n)
{
	int		z;
	int		c;
	int		b;
	int		m;

	c = 0;
	m = 0;
	b = 0;
	tmp = read_block(n);
	while (tmp[b] != '\0')
		b++;
	z = 0;
	while (isalpha(tmp[b]) != 1)
	{
		tmp[b] == '\n' ? z++ : 0;
		tmp[b] == '\t' ? m++ : 0;
		tmp[b] == ' ' ? c++ : 0;
		b--;
	}
	if (z == 0)
		error_message(fl, "no newline after command");
	if (z == 0 && (c > 0 || m > 0))
		error_message(fl, "no newline after command");
	free(tmp);
}

static void	ft_init(int fd, t_bot **st, char *n)
{
	t_bot	*mas;
	t_bot	*nuch;

	mas = 0;
	mas = (t_bot*)malloc(sizeof(t_bot));
	mas->func = 0;
	validat(fd, &mas, n);
	close(fd);
	!mas->func ? error_message("No commands!", 0) : 0;
	if (!*st)
	{
		mas->next = *st;
		*st = mas;
	}
	else
	{
		nuch = *st;
		while (nuch->next)
			nuch = nuch->next;
		nuch->next = mas;
		mas->next = 0;
	}
	close(fd);
}

static void	usage(void)
{
	ft_putstr("How does asm work\n");
	exit(0);
}

int			main(int ac, char **av)
{
	t_bot	*st;
	int		fd;
	int		i;

	st = 0;
	i = 0;
	g_fllag = 0;
	ac == 1 ? usage() : 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-a"))
		{
			g_fllag = 1;
			i++;
		}
		fd = open(av[i], O_RDONLY);
		fd == -1 ? ft_putstr("Can't read source file ") : 0;
		fd == -1 ? error_message(av[i], 0) : 0;
		ft_init(fd, &st, av[i]);
	}
	if (g_fllag == 1)
		flag_a(st);
	else
		record_file(st, av, 0, NULL);
	return (0);
}
