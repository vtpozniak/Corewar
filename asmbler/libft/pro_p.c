/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:10:20 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:10:21 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minp(t_print *la, char *str)
{
	check_bf(la, '0');
	check_bf(la, 'x');
	while (la->q.p--)
		check_bf(la, '0');
	while (la->q.lens--)
		check_bf(la, str[la->q.it++]);
	la->q.width >= 2 ? la->q.width -= 2 : 0;
	while (la->q.width && la->q.width--)
		check_bf(la, ' ');
}

void	ft_plusp(t_print *la, char *str)
{
	if (la->q.zero && !la->q.t)
	{
		check_bf(la, '0');
		check_bf(la, 'x');
		while (la->q.width && la->q.width--)
			check_bf(la, '0');
	}
	else
	{
		while (la->q.width && la->q.width >= 0 && la->q.width--)
			check_bf(la, ' ');
		check_bf(la, '0');
		check_bf(la, 'x');
	}
	while (la->q.p--)
		check_bf(la, '0');
	while (la->q.lens--)
		check_bf(la, str[la->q.it++]);
}

void	pro_p(t_print *la, va_list list)
{
	uintmax_t	src;
	char		*str;

	src = va_arg(list, unsigned long int);
	str = ft_itoa_base(la, src, la->q.base);
	la->q.lens = (int)ft_strlen(str);
	src == 0 && la->q.p == 0 && la->q.t > 0 ? la->q.lens = 0 : 0;
	la->q.p <= la->q.lens ? la->q.p = 0 : 0;
	la->q.p > la->q.lens ? la->q.p -= la->q.lens : 0;
	la->q.width <= la->q.lens ? la->q.width = 0 : 0;
	la->q.width > la->q.lens ? la->q.width = la->q.width
			- la->q.p - la->q.lens : 0;
	!la->q.min ? la->q.width = la->q.width - 2 : 0;
	la->q.width < 0 ? la->q.width = 0 : 0;
	if (!la->q.min)
		ft_plusp(la, str);
	if (la->q.min)
		ft_minp(la, str);
	free(str);
	ft_bzero(&(la->q), sizeof(t_flags_list));
}
