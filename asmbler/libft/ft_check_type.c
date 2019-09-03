/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:06:36 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:06:41 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	check_type(t_print *la, va_list list)
{
	if (la->q.l)
		return (va_arg(list, long int));
	if (la->q.ll || la->q.z)
		return (va_arg(list, long long int));
	if (la->q.j)
		return (va_arg(list, intmax_t));
	if (la->q.h)
		return ((short int)va_arg(list, int));
	if (la->q.hh)
		return ((signed char)va_arg(list, int));
	return (va_arg(list, int));
}

uintmax_t	check_type_2(t_print *la, va_list list)
{
	if (la->q.l)
		return (va_arg(list, unsigned long int));
	if (la->q.ll)
		return (va_arg(list, unsigned long long int));
	if (la->q.z)
		return (va_arg(list, size_t));
	if (la->q.j)
		return (va_arg(list, uintmax_t));
	if (la->q.h)
		return ((unsigned short int)va_arg(list, int));
	if (la->q.hh)
		return ((unsigned char)va_arg(list, int));
	return (va_arg(list, unsigned int));
}

long double	check_type_3(t_print *la, va_list list)
{
	if (la->q.lzl)
		return (va_arg(list, long double));
	return (va_arg(list, double));
}
