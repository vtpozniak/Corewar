/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:10:44 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:10:45 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pro_s(t_print *la, va_list list)
{
	char	*str;

	if (!(str = va_arg(list, char*)))
	{
		str = "(null)";
		la->q.len = 6;
	}
	la->q.lens = (int)ft_strlen(str);
	la->q.p < la->q.lens && la->q.p >= 0 ? la->q.lens = la->q.p : 0;
	if (la->q.width > la->q.lens)
		la->q.width -= la->q.lens;
	else
		la->q.width = 0;
	if (!la->q.min)
		while (la->q.width--)
			check_bf(la, ' ');
	while (la->q.lens--)
		check_bf(la, str[la->q.it++]);
	if (la->q.min)
		while (la->q.width--)
			check_bf(la, ' ');
	ft_bzero(&(la->q), sizeof(t_flags_list));
}
