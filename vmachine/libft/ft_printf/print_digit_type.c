/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:36:24 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/02 15:36:36 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_function1(t_lst *lst, va_list ptr, int *flag, intmax_t *i)
{
	set_arg(lst, ptr);
	*i = set_size(lst, ptr);
	*flag = set_flag(lst, *i);
}

static void	set_function2(t_lst *lst, intmax_t i, char **nb, int *len)
{
	if (i == 0 && lst->precision == 0 && lst->width <= 0)
		*nb = ft_strdup("");
	else if (i == 0 && lst->precision == 0 && lst->width > 0)
		*nb = ft_strdup(" ");
	else if (lst->type == 'b' && i > 0)
		*nb = ft_itoa_base_p(lst, i, 0, 2);
	else
		*nb = ft_itoa_base_p(lst, i, 0, 10);
	*len = (int)ft_strlen((*nb));
}

void		ft_print_width_digit(t_lst *lst, intmax_t i)
{
	if (((lst->flags != '-') && (lst->width > 0 && lst->flags == '0'
	&& lst->precision < 0)) || ((lst->flags != '-') && (lst->width <= 0
	&& lst->precision < 0)) || (i == 0 && lst->precision == 0
	&& lst->prior_space == ' '))
		ft_print_flag(lst, i);
	if (lst->width <= 0)
		return ;
	if (lst->flags == '0' && lst->precision < 0)
	{
		while (lst->width > 4096)
		{
			ft_print_str_of_char(4096, '0');
			lst->width -= 4096;
		}
		ft_print_str_of_char(lst->width, '0');
	}
	else
	{
		while (lst->width > 4096)
		{
			ft_print_str_of_char(4096, ' ');
			lst->width -= 4096;
		}
		ft_print_str_of_char(lst->width, ' ');
	}
}

void		ft_print_precision_digit(t_lst *lst, intmax_t i, int j)
{
	if (lst->flags == '-' && j == 0 && lst->precision < 0)
		ft_print_flag(lst, i);
	if ((lst->precision >= 0) || (lst->precision < 0 && lst->width >= 0
	&& lst->flags != '0' && lst->flags != '-'))
		ft_print_flag(lst, i);
	if (lst->precision < 0)
		return ;
	if (j > 0)
		ft_print_str_of_char(j, '0');
}

void		ft_print_i_d(t_lst *lst, va_list ptr)
{
	char		*nb;
	int			flag;
	int			len;
	intmax_t	i;
	int			j;

	set_function1(lst, ptr, &flag, &i);
	set_function2(lst, i, &nb, &len);
	j = lst->precision - len;
	(j < 0) ? (j = 0) : 0;
	lst->width = lst->width - flag - j - len;
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
