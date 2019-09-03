/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_oct_uns_ptr_type.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:28:14 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 17:30:20 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_function1(t_lst *lst, va_list ptr, int *flag, uintmax_t *i)
{
	set_arg(lst, ptr);
	*i = set_size_unsigned(lst, ptr);
	*flag = set_flag(lst, *i);
}

static void	set_function2(t_lst *lst, uintmax_t i, char **nb, int *len)
{
	if (i == 0 && lst->precision == 0 && lst->type != 'o')
		*nb = ft_strdup("");
	else if (i == 0 && lst->precision <= 0 && lst->type == 'o')
	{
		if (lst->hash_flag == '#' || lst->precision == 0)
			*nb = ft_strdup("");
		else
			*nb = ft_itoa_base_p(lst, 0, i, 8);
	}
	else
	{
		if (lst->type == 'x' || lst->type == 'X' || lst->type == 'p')
			*nb = ft_itoa_base_p(lst, 0, i, 16);
		if (lst->type == 'o')
			*nb = ft_itoa_base_p(lst, 0, i, 8);
		if (lst->type == 'u')
			*nb = ft_itoa_base_p(lst, 0, i, 10);
	}
	*len = (int)ft_strlen(*nb);
}

static void	set_function3(t_lst *lst, int *j, int len, int flag)
{
	if (lst->type == 'x' || lst->type == 'X' || lst->type == 'p')
	{
		*j = lst->precision - len;
		(*j < 0) ? (*j = 0) : 0;
		lst->width = lst->width - flag - *j - len;
	}
	if (lst->type == 'o')
	{
		lst->precision = lst->precision - flag;
		*j = lst->precision - len;
		(*j < 0) ? (*j = 0) : 0;
		lst->width = lst->width - flag - *j - len;
	}
	if (lst->type == 'u')
	{
		*j = lst->precision - len;
		(*j < 0) ? (*j = 0) : 0;
		lst->width = lst->width - flag - *j - len;
	}
}

void		ft_print_hex_oct_uns_p(t_lst *lst, va_list ptr)
{
	char		*nb;
	int			flag;
	int			len;
	uintmax_t	i;
	int			j;

	set_function1(lst, ptr, &flag, &i);
	set_function2(lst, i, &nb, &len);
	set_function3(lst, &j, len, flag);
	if (lst->flags == '-')
	{
		ft_print_precision_digit(lst, i, j);
		ft_fill_buff(nb, len);
		ft_print_width_digit(lst, i);
	}
	else
	{
		ft_print_width_digit(lst, i);
		ft_print_precision_digit(lst, i, j);
		ft_fill_buff(nb, len);
	}
	free(nb);
}

void		fill_nan_inf(long double i, t_lst *lst)
{
	(i * 2 == i && i != 0 && i < 0 && lst->type == 'f')
	? ft_fill_buff("-inf", 4) : 0;
	(i * 2 == i && i != 0 && i > 0 && lst->type == 'f')
	? ft_fill_buff("inf", 3) : 0;
	(i != i && lst->type == 'f') ? ft_fill_buff("nan", 3) : 0;
	(i * 2 == i && i != 0 && i < 0 && lst->type == 'F')
	? ft_fill_buff("-INF", 4) : 0;
	(i * 2 == i && i != 0 && i > 0 && lst->type == 'F')
	? ft_fill_buff("INF", 3) : 0;
	(i != i && lst->type == 'F') ? ft_fill_buff("NAN", 3) : 0;
}
