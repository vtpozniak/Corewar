/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_o_u_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:09:53 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:09:54 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_flag(t_print *la, char str)
{
	if (la->q.hesh > 0 && str != '0')
	{
		if (la->q.x && str != '\0')
		{
			check_bf(la, '0');
			check_bf(la, 'x');
			la->q.width = la->q.width - 2;
		}
		if (la->q.xl && str != '\0')
		{
			check_bf(la, '0');
			check_bf(la, 'X');
			la->q.width = la->q.width - 2;
		}
		if (la->q.o)
		{
			check_bf(la, '0');
			la->q.p <= 0 ? la->q.width-- : 0;
		}
	}
	la->q.hesh && la->q.o && str != '0' && !la->q.x &&
	la->q.p > 0 ? la->q.p-- : 0;
	la->q.hesh = 0;
}

void	buf2(t_print *la, char *str, uintmax_t src)
{
	if (la->q.min)
	{
		ft_print_flag(la, *str);
		while (la->q.p--)
			check_bf(la, '0');
		ft_print_flag(la, *str);
		while (la->q.lens--)
			check_bf(la, str[la->q.it++]);
		while (la->q.width-- && la->q.width >= 0)
			check_bf(la, ' ');
	}
	else
	{
		if (la->q.hesh > 0 && src != 0)
		{
			la->q.x > 0 || la->q.xl > 0 ? la->q.width -= 2 : 0;
			la->q.o > 0 && la->q.width > la->q.p ? la->q.width-- : 0;
		}
		while (la->q.width-- && la->q.width >= 0 && la->q.flag)
			check_bf(la, ' ');
		ft_print_flag(la, *str);
		la->q.space && la->q.plus <= 0 && src > 0 ? check_bf(la, ' ') : 0;
		while (la->q.p-- && la->q.p >= 0)
			check_bf(la, '0');
	}
}

void	ft_min2(t_print *la, char *str, uintmax_t src)
{
	if (la->q.min || la->q.p >= 0 || la->q.width >= 0)
		buf2(la, str, src);
	la->q.min && la->q.p > 0 ? buf2(la, str, src) : 0;
}

void	ft_plus2(t_print *la, char *str, intmax_t src)
{
	if (la->q.p <= 0 && la->q.width <= 0)
		la->q.plus ? buf2(la, str, src) : 0;
	!la->q.min && la->q.p > 0 && la->q.width >= 0 ? buf2(la, str, src) : 0;
	la->q.width < la->q.p && la->q.p > 0 ? buf2(la, str, src) : 0;
	la->q.p > 0 ? buf2(la, str, src) : 0;
	if (la->q.width > 0)
	{
		if (la->q.zero && !la->q.plus && !la->q.t)
		{
			ft_print_flag(la, *str);
			while (la->q.width--)
				check_bf(la, '0');
		}
		else
			buf2(la, str, src);
	}
	else
		ft_print_flag(la, *str);
	while (la->q.lens--)
		check_bf(la, str[la->q.it++]);
}

void	pro_o_u_x(t_print *la, va_list list)
{
	uintmax_t	src;
	char		*str;
	int			flag;

	flag = 0;
	src = check_type_2(la, list);
	if (src == 0 && la->q.p == 0 && la->q.width <= 0)
		str = ft_strdup("");
	else if (src == 0 && la->q.p == 0 && la->q.width > 0 && !la->q.hesh)
		str = ft_strdup(" ");
	else
		str = ft_itoa_base(la, src, la->q.base);
	str == 0 ? flag = 0 : 0;
	la->q.lens = (int)ft_strlen(str);
	la->q.p <= la->q.lens ? la->q.p = 0 : 0;
	la->q.p > la->q.lens ? la->q.p -= la->q.lens : 0;
	la->q.width <= la->q.lens ? la->q.width = 0 : 0;
	la->q.width > la->q.lens ? la->q.width = la->q.width
			- la->q.p - la->q.lens : 0;
	la->q.width < 0 ? la->q.width = 0 : 0;
	la->q.min ? ft_min2(la, str, src) : 0;
	!la->q.min ? ft_plus2(la, str, src) : 0;
	free(str);
	ft_bzero(&(la->q), sizeof(t_flags_list));
}
