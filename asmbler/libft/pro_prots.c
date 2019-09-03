/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_prots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:10:35 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:10:36 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pro_prots(t_print *la)
{
	if (la->q.zero)
		la->q.symvol = '0';
	else
		la->q.symvol = ' ';
	if (la->q.width && !la->q.min)
		while ((la->q.width--) - 1)
			check_bf(la, la->q.symvol);
	check_bf(la, '%');
	if (la->q.width && la->q.min)
		while ((la->q.width--) - 1)
			check_bf(la, la->q.symvol);
}
