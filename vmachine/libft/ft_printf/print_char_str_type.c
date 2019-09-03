/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:26:50 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/11 17:57:39 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_percent(t_lst *lst)
{
	int width;

	width = lst->width - 1;
	if (lst->flags == '-')
	{
		ft_fill_buff("%", 1);
		ft_print_width_char(lst, width);
	}
	else
	{
		ft_print_width_char(lst, width);
		ft_fill_buff("%", 1);
	}
}

static void	ft_null_char(t_lst *lst, int width)
{
	int	i;

	i = (int)ft_strlen(g_buff);
	g_flag = 1;
	if (i > 0)
	{
		ft_print_buff(g_buff);
		ft_bzero(g_buff, 8192);
		g_count = 0;
	}
	if (lst->flags == '-')
	{
		write(1, "\0", 1);
		g_len++;
		ft_print_width_char(lst, width);
	}
	else
	{
		ft_print_width_char(lst, width);
		write(1, "\0", 1);
		g_len++;
	}
}

void		ft_print_char(t_lst *lst, va_list ptr)
{
	int		width;
	char	a;

	width = lst->width - 1;
	a = (char)va_arg(ptr, int);
	if (a == 0)
		ft_null_char(lst, width);
	else
	{
		if (lst->flags == '-')
		{
			ft_fill_buff(&a, 1);
			ft_print_width_char(lst, width);
		}
		else
		{
			ft_print_width_char(lst, width);
			ft_fill_buff(&a, 1);
		}
	}
}

void		ft_print_str(t_lst *lst, va_list ptr)
{
	char	*str;
	int		len;

	(lst->precision_as_arg == '*') ? lst->precision = va_arg(ptr, int) : 0;
	str = va_arg(ptr, char *);
	(lst->type == 'r') ? str = format_nonprc(str) : 0;
	(!str) ? str = "(null)" : 0;
	len = (int)ft_strlen(str);
	(lst->precision < 0 || lst->precision > len) ? lst->precision = len : 0;
	if (lst->flags == '-')
	{
		ft_fill_buff(str, lst->precision);
		ft_print_width_char(lst, (lst->width - lst->precision));
	}
	else
	{
		ft_print_width_char(lst, (lst->width - lst->precision));
		ft_fill_buff(str, lst->precision);
	}
	(lst->type == 'r') ? free(str) : 0;
}

void		ft_print_width_char(t_lst *lst, int width)
{
	if (width <= 0)
		return ;
	if (lst->flags == '0')
	{
		while (width > 4096)
		{
			ft_print_str_of_char(4096, '0');
			width -= 4096;
		}
		ft_print_str_of_char(width, '0');
	}
	else
	{
		while (width > 4096)
		{
			ft_print_str_of_char(4096, ' ');
			width -= 4096;
		}
		ft_print_str_of_char(width, ' ');
	}
}
