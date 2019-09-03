/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prof_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:13:27 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/28 18:47:16 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buff(t_print *la, char *str, int j)
{
	if (la->q.min)
	{
		j > 0 ? check_bf(la, '-') : 0;
		la->q.plus > 0 ? check_bf(la, '+') : 0;
		while (la->q.p--)
			check_bf(la, '0');
		while (la->q.lens--)
			check_bf(la, str[la->q.it++]);
		while (la->q.width--)
			check_bf(la, ' ');
	}
	else
		bufff(la, j);
}

void	ft_minf(t_print *la, char *str, int j)
{
	if (la->q.min && la->q.p <= 0 && la->q.width <= 0)
	{
		while (la->q.space--)
			check_bf(la, ' ');
		buff(la, str, j);
	}
	if (la->q.min && la->q.p > 0 && la->q.width > 0)
		buff(la, str, j);
	la->q.min && la->q.p > 0 ? buff(la, str, j) : 0;
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
			buff(la, str, j);
	}
}

void	ft_plusf(t_print *la, char *str, int j)
{
	if (la->q.p <= 0 && la->q.width <= 0)
	{
		j > 0 ? buff(la, str, j) : 0;
		la->q.plus && j <= 0 ? buff(la, str, j) : 0;
		if (la->q.space && !la->q.plus && j <= 0)
		{
			while (la->q.space--)
				check_bf(la, ' ');
		}
	}
	!la->q.min && la->q.p > 0 && la->q.width >= 0 ? buff(la, str, j) : 0;
	la->q.width < la->q.p && la->q.p > 0 ? buff(la, str, j) : 0;
	la->q.p > 0 ? buff(la, str, j) : 0;
	if (la->q.width > 0)
		plusf(la, str, j);
	while (la->q.lens--)
		check_bf(la, str[la->q.it++]);
	la->q.p <= 0 && la->q.hesh > 0 ? check_bf(la, '.') : 0;
}

void	prof_f(t_print *la, char *str, long double drob)
{
	int			flag;
	int			j;

	flag = 0;
	j = 0;
	la->q.p = 0;
	drob < 0 || (drob < 0 && la->q.plus) || (drob >= 0 && la->q.space &&
		!la->q.plus) || (drob >= 0 && la->q.plus) ? flag++ : 0;
	la->q.p <= 0 && la->q.hesh > 0 ? la->q.width-- : 0;
	la->q.plus && la->q.min && drob < 0 ? la->q.plus = 0 : 0;
	la->q.dr ? j++ : 0;
	str[0] == '0' && drob > 0 && la->q.min > 0 ? la->q.width-- : 0;
	str[0] == '-' ? ft_re(str) : 0;
	la->q.lens = (int)ft_strlen(str);
	str[0] == '0' && drob == 0 && la->q.min > 0 ? la->q.width-- : 0;
	la->q.width <= la->q.lens ? la->q.width = 0 : 0;
	la->q.width > la->q.lens ? la->q.width = la->q.width
			- la->q.p - la->q.lens - flag : 0;
	la->q.width < 0 ? la->q.width = 0 : 0;
	la->q.min ? ft_minf(la, str, j) : 0;
	!la->q.min ? ft_plusf(la, str, j) : 0;
	ft_bzero(&(la->q), sizeof(t_flags_list));
}
