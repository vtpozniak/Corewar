/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_d_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:09:30 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:09:31 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_re(char *str)
{
	int			i;

	i = 0;
	while (str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
	return (*str);
}

void	buf(t_print *la, char *str, int j, intmax_t src)
{
	if (la->q.min)
	{
		j > 0 ? check_bf(la, '-') : 0;
		la->q.plus-- && src >= 0 ? check_bf(la, '+') : 0;
		la->q.space-- && la->q.p >= 0 && src >= 0 ? check_bf(la, ' ') : 0;
		while (la->q.p--)
			check_bf(la, '0');
		while (la->q.lens--)
			check_bf(la, str[la->q.it++]);
		if (la->q.width > 0)
		{
			while (la->q.width--)
				check_bf(la, ' ');
		}
	}
	else
		bufd(la, j, src);
}

void	ft_min(t_print *la, char *str, intmax_t src, int j)
{
	if (la->q.min && la->q.p <= 0 && la->q.width <= 0)
		buf(la, str, j, src);
	if (la->q.min && la->q.p > 0 && la->q.width > 0)
		buf(la, str, j, src);
	la->q.min && la->q.p > 0 ? buf(la, str, j, src) : 0;
	if (la->q.min && la->q.width > 0)
	{
		if (la->q.zero && j > 0)
		{
			check_bf(la, '-');
			while (la->q.width--)
				check_bf(la, '0');
		}
		else if (la->q.zero)
			while (la->q.width--)
				check_bf(la, '0');
		else
			buf(la, str, j, src);
	}
}

void	ft_plus(t_print *la, char *str, intmax_t src, int j)
{
	if (la->q.p <= 0 && la->q.width <= 0)
	{
		j > 0 ? buf(la, str, j, src) : 0;
		la->q.plus && j <= 0 ? buf(la, str, j, src) : 0;
		if (la->q.space && !la->q.plus && j <= 0)
			while (la->q.space--)
				check_bf(la, ' ');
	}
	!la->q.min && la->q.p > 0 && la->q.width >= 0 ? buf(la, str, j, src) : 0;
	la->q.width < la->q.p && la->q.p > 0 ? buf(la, str, j, src) : 0;
	la->q.p > 0 ? buf(la, str, j, src) : 0;
	if (la->q.width > 0)
		plusd(la, str, src, j);
	while (la->q.lens--)
		check_bf(la, str[la->q.it++]);
}

void	pro_d_i(t_print *la, va_list list)
{
	intmax_t	src;
	char		*str;
	int			flag;
	int			j;

	flag = 0;
	j = 0;
	str = NULL;
	src = check_type(la, list);
	str = ft_putdup(la, src, str);
	str[0] == '-' ? j++ : 0;
	src < 0 || (src < 0 && la->q.plus) || (src >= 0 && la->q.space &&
	!la->q.plus) || (src >= 0 && la->q.plus) ? flag++ : 0;
	str[0] == '-' ? ft_re(str) : 0;
	la->q.lens = ft_strlen(str);
	la->q.p <= la->q.lens ? la->q.p = 0 : 0;
	la->q.p > la->q.lens ? la->q.p -= la->q.lens : 0;
	la->q.width <= la->q.lens ? la->q.width = 0 : 0;
	la->q.width > la->q.lens ? la->q.width = la->q.width
			- la->q.p - la->q.lens - flag : 0;
	la->q.width < 0 ? la->q.width = 0 : 0;
	la->q.min ? ft_min(la, str, src, j) : 0;
	!la->q.min ? ft_plus(la, str, src, j) : 0;
	free(str);
	ft_bzero(&(la->q), sizeof(t_flags_list));
}
