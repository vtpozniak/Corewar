/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funck_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:07:49 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:07:50 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	plusf(t_print *la, char *str, int j)
{
	if (la->q.zero && j > 0)
	{
		check_bf(la, '-');
		while (la->q.width--)
			check_bf(la, '0');
	}
	else if (la->q.zero && j <= 0 && !la->q.plus)
	{
		la->q.space ? check_bf(la, ' ') : 0;
		while (la->q.width--)
			check_bf(la, '0');
	}
	else
		buff(la, str, j);
}

void	bufff(t_print *la, int j)
{
	if (la->q.zero && la->q.p == 0 && j <= 0)
	{
		if (la->q.plus && j <= 0 && !la->q.t)
		{
			check_bf(la, '+');
			la->q.plus = 0;
			while (la->q.width--)
				check_bf(la, '0');
		}
	}
	while (la->q.width-- && la->q.width >= 0)
		check_bf(la, ' ');
	if (la->q.space && la->q.plus <= 0)
		check_bf(la, ' ');
	j > 0 ? check_bf(la, '-') : 0;
	la->q.plus && j <= 0 ? check_bf(la, '+') : 0;
	while (la->q.p--)
		check_bf(la, '0');
}

char	*tochnf(intmax_t *whole, t_print *la, int i, long double drob)
{
	if (la->q.p == 0 && la->str[0] >= '5')
	{
		if (*whole % 2 == 0 && (drob == 0.5 || drob == -0.5))
		{
			*la->str = 0;
			return (la->str);
		}
		*whole = *whole + 1;
		*whole < 0 ? *whole = *whole - 2 : 0;
		*la->str = 0;
		return (la->str);
	}
	if (la->str[0] == '9' && la->str[1] >= '5' && la->q.p == 1)
	{
		i == 1 && la->str[1] >= '5' && la->str[1] <= '9' ?
		*whole = *whole + 1 : 0;
		la->str[0] = '0';
		la->str[la->q.p] = '\0';
		return (la->str);
	}
	return (0);
}

void	ft_flo(long double src, t_print *la, intmax_t whole)
{
	if (la->q.lzl > 0)
		la->who = ft_itoa_base(la, whole, 10);
	else
		la->who = ft_itoa(whole);
	la->q.lens = (int)ft_strlen(la->str);
	la->q.lens1 = (int)ft_strlen(la->who);
	if (src * 2 == src && src != 0 && src < 0 && la->q.f)
		la->tmp = ft_strdup("-inf");
	else if (src * 2 == src && src != 0 && src > 0 && la->q.f)
		la->tmp = ft_strdup("inf");
	else if (src != src && la->q.f)
	{
		la->tmp = ft_strdup("nan");
		la->q.plus = 0;
	}
	else
		la->tmp = iter(la);
}
