/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:09:19 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:09:20 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put(t_print *la, char c)
{
	while (la->q.width--)
		check_bf(la, c);
}

void	pro_c(t_print *la, va_list list)
{
	la->q.symvol = va_arg(list, int);
	if (la->q.min)
	{
		check_bf(la, la->q.symvol);
		if (la->q.width)
		{
			la->q.width -= 1;
			la->q.zero ? ft_put(la, '0') : 0;
			!la->q.zero ? ft_put(la, ' ') : 0;
		}
	}
	else
	{
		if (la->q.width)
		{
			la->q.width -= 1;
			la->q.zero ? ft_put(la, '0') : 0;
			!la->q.zero ? ft_put(la, ' ') : 0;
		}
		check_bf(la, la->q.symvol);
	}
	ft_bzero(&(la->q), sizeof(t_flags_list));
}
