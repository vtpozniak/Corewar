/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rozm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:56:21 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 19:38:44 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

int			rozm(char *str, char c)
{
	int		i;

	i = -1;
	if (c == '%')
		i = i + 2;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			break ;
	}
	return (i = i + 1);
}

char		*ft_strndup(char const *str, size_t n)
{
	size_t	i;
	char	*mass;

	if (!(mass = (char*)malloc(sizeof(*mass) * n + 1)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		mass[i] = str[i];
		i++;
	}
	mass[i] = '\0';
	return (mass);
}

void		record_byt(int fd, int a, int count_bytes, int j)
{
	int				t;
	unsigned char	mass[count_bytes];

	t = 8;
	j = count_bytes;
	while (count_bytes--)
	{
		mass[count_bytes] = (unsigned char)a;
		a >>= t;
	}
	while (++count_bytes < j)
		write(fd, &mass[count_bytes], 1);
}

int			mcheck(t_func *func)
{
	int		size;
	t_var	*var;

	size = 0;
	size++;
	func->kode ? size++ : 0;
	var = func->varr;
	while (var)
	{
		size += var->rozm;
		var = var->next;
	}
	return (size);
}

int			size_code(t_bot *st)
{
	int		size;
	t_func	*func;

	size = 0;
	func = st->func;
	while (func)
	{
		ft_strcmp(func->name, "-1") ? size += mcheck(func) : 0;
		func = func->next;
	}
	return (size);
}
