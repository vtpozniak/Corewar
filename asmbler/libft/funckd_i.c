/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funckd_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:08:04 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:08:05 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putdup(t_print *la, intmax_t src, char *str)
{
	if (src == 0 && la->q.p == 0 && la->q.width <= 0)
		str = ft_strdup("");
	else if (src == 0 && la->q.p == 0 && la->q.width > 0)
		str = ft_strdup(" ");
	else
		str = ft_itoa(src);
	return (str);
}

void	plusd(t_print *la, char *str, intmax_t src, int j)
{
	if (la->q.zero && j > 0)
	{
		check_bf(la, '-');
		while (la->q.width--)
			check_bf(la, '0');
	}
	else if (la->q.zero && j <= 0 && !la->q.plus && !la->q.t)
	{
		la->q.space ? check_bf(la, ' ') : 0;
		while (la->q.width--)
			check_bf(la, '0');
	}
	else
		buf(la, str, j, src);
}

void	bufd(t_print *la, int j, intmax_t src)
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
	if (la->q.space && la->q.plus <= 0 && src >= 0)
		check_bf(la, ' ');
	j > 0 ? check_bf(la, '-') : 0;
	la->q.plus && j <= 0 ? check_bf(la, '+') : 0;
	while (la->q.p--)
		check_bf(la, '0');
}
