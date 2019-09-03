/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:07:29 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:07:30 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_bf(t_print *la, char c)
{
	la->buf[la->i++] = c;
	if (la->i == 4096)
	{
		la->count += la->i;
		write(1, la->buf, la->i);
		la->i = 0;
	}
}

int		ft_printf(const char *pars, ...)
{
	size_t				i;
	va_list				list;
	static t_print		la;
	static char			bf[4096];

	i = 0;
	ft_bzero(&la, sizeof(t_print));
	la.buf = bf;
	va_start(list, pars);
	while (pars[i])
	{
		if (pars[i] == '%')
			i = parsing(pars, &la, &list, i);
		else
			check_bf(&la, pars[i++]);
	}
	va_end(list);
	if (la.i > 0)
		write(1, la.buf, la.i);
	la.count = la.count + la.i;
	return (la.count);
}
