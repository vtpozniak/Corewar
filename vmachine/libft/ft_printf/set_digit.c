/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:29:17 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 17:46:59 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			set_flag(t_lst *lst, intmax_t i)
{
	int flag;

	flag = 0;
	if ((lst->type == 'f' || lst->type == 'F') && lst->precision != 0
	&& lst->hash_flag != '#')
		flag += 1;
	if ((lst->prior_space == ' ' || lst->prior_plus == '+' || i < 0
	|| g_fl_sign == 1) && (lst->type == 'd' || lst->type == 'i'
	|| lst->type == 'f' || lst->type == 'F'))
		flag += 1;
	if (lst->hash_flag == '#' || lst->type == 'p')
	{
		if (lst->type == 'x' || lst->type == 'X' || lst->type == 'p')
			flag += 2;
		if (lst->type == 'o')
			flag += 1;
		if ((lst->type == 'f' || lst->type == 'F') && lst->precision == 0)
			flag += 1;
	}
	return (flag);
}

void		set_arg(t_lst *lst, va_list ptr)
{
	if (lst->precision_as_arg == '*')
		lst->precision = va_arg(ptr, int);
}

intmax_t	set_size(t_lst *lst, va_list ptr)
{
	if (lst->size[0] == 'l' && lst->size[1] != 'l')
		return (va_arg(ptr, long int));
	if (lst->size[0] == 'l' && lst->size[1] == 'l')
		return (va_arg(ptr, long long int));
	if (lst->size[0] == 'z')
		return (va_arg(ptr, size_t));
	if (lst->size[0] == 'j')
		return (va_arg(ptr, intmax_t));
	if (lst->size[0] == 'h' && lst->size[1] != 'h')
		return ((short int)va_arg(ptr, int));
	if (lst->size[0] == 'h' && lst->size[1] == 'h')
		return ((signed char)va_arg(ptr, int));
	return (va_arg(ptr, int));
}

long double	set_size_float(t_lst *lst, va_list ptr)
{
	if (lst->big_l_size == 'L')
		return (va_arg(ptr, long double));
	return (va_arg(ptr, double));
}

uintmax_t	set_size_unsigned(t_lst *lst, va_list ptr)
{
	if (lst->size[0] == 'l' && lst->size[1] != 'l')
		return (va_arg(ptr, unsigned long int));
	if (lst->size[0] == 'l' && lst->size[1] == 'l')
		return (va_arg(ptr, unsigned long long int));
	if (lst->size[0] == 'z')
		return (va_arg(ptr, size_t));
	if (lst->size[0] == 'j')
		return (va_arg(ptr, uintmax_t));
	if (lst->size[0] == 'h' && lst->size[1] != 'h')
		return ((unsigned short int)va_arg(ptr, int));
	if (lst->size[0] == 'h' && lst->size[1] == 'h')
		return ((unsigned char)va_arg(ptr, int));
	if (lst->type == 'p')
		return (va_arg(ptr, unsigned long int));
	return (va_arg(ptr, unsigned int));
}
