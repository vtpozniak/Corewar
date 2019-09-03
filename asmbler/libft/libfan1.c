/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfan1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:08:32 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:08:33 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		minzero(double src)
{
	long long *tmp;
	long long bit;
	long long j;

	tmp = (long long *)(&src);
	bit = *tmp;
	j = bit >> 63;
	if (j < 0)
		return (1);
	return (0);
}
