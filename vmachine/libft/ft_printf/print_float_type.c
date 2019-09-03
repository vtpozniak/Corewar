/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:23:05 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 17:31:26 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_precision_float(t_lst *lst, long double fract)
{
	int		p_count;
	char	*fr_buff;
	int		c;

	c = 0;
	(lst->precision < 0) ? (p_count = 7) : 0;
	(lst->precision >= 0) ? (p_count = lst->precision + 1) : 0;
	fr_buff = (char *)malloc(sizeof(char) * (p_count + 1));
	ft_bzero(fr_buff, p_count + 1);
	while (c < p_count)
	{
		fr_buff[c] = fract * 10 + 48;
		fract *= 10;
		fract -= (uintmax_t)fract;
		c++;
	}
	return (fr_buff);
}

static char	*round_float(char *fr, unsigned long long *whole, t_lst *lst, int i)
{
	(lst->precision < 0) ? i = 6 : 0;
	(lst->precision > 0) ? i = lst->precision : 0;
	if (lst->precision == 0 && *whole % 2 == 1 && fr[0] >= '5')
	{
		*whole += 1;
		return (fr);
	}
	if (lst->precision == 1 && fr[0] == '2' && fr[1] == '5')
		return (fr);
	if (i >= 0 && fr[i] >= '5')
	{
		if (fr[i] == '9')
		{
			while (fr[i] == '9')
			{
				(i == 0 && fr[i] == '9') ? *whole += 1 : 0;
				fr[i--] = '0';
			}
			fr[i]++;
		}
		else
			fr[i - 1]++;
	}
	return (fr);
}

static void	non_sign_float_fill(t_lst *lst, char *fr, char *wh, int width)
{
	if (width > 0 && lst->flags == '0')
	{
		(lst->prior_space == ' ' && lst->prior_plus != '+')
		? ft_fill_buff(" ", 1) : 0;
		(g_fl_sign == 1) ? ft_fill_buff("-", 1) : 0;
		(lst->prior_plus == '+' && g_fl_sign == 0) ? ft_fill_buff("+", 1) : 0;
		ft_print_str_of_char(width, '0');
		ft_fill_buff(wh, (int)ft_strlen(wh));
		(lst->precision != 0 || (lst->precision == 0 && lst->hash_flag == '#'))
		? ft_fill_buff(".", 1) : 0;
		(lst->precision != 0) ? ft_fill_buff(fr, ((int)ft_strlen(fr) - 1)) : 0;
	}
	else
	{
		ft_print_str_of_char(width, ' ');
		(lst->prior_space == ' ' && lst->prior_plus != '+')
		? ft_fill_buff(" ", 1) : 0;
		(lst->prior_plus == '+' && g_fl_sign == 0) ? ft_fill_buff("+", 1) : 0;
		(g_fl_sign == 1) ? ft_fill_buff("-", 1) : 0;
		ft_fill_buff(wh, (int)ft_strlen(wh));
		(lst->precision != 0 || (lst->precision == 0 && lst->hash_flag == '#'))
		? ft_fill_buff(".", 1) : 0;
		(lst->precision != 0) ? ft_fill_buff(fr, ((int)ft_strlen(fr) - 1)) : 0;
	}
}

static void	fill_float(t_lst *lst, char *fr, char *wh)
{
	int flag;
	int width;
	int precision;

	precision = (int)ft_strlen(fr) - 1;
	(precision < 0) ? (precision = 0) : 0;
	flag = set_flag(lst, 0);
	width = lst->width - flag - (int)ft_strlen(wh) - precision;
	(width < 0) ? (width = 0) : 0;
	if (lst->flags == '-')
	{
		(lst->prior_space == ' ' && lst->prior_plus != '+')
		? ft_fill_buff(" ", 1) : 0;
		(g_fl_sign == 1) ? ft_fill_buff("-", 1) : 0;
		(lst->prior_plus == '+' && g_fl_sign == 0) ? ft_fill_buff("+", 1) : 0;
		ft_fill_buff(wh, (int)ft_strlen(wh));
		(lst->precision != 0 || (lst->precision == 0 && lst->hash_flag == '#'))
		? ft_fill_buff(".", 1) : 0;
		(lst->precision != 0) ? ft_fill_buff(fr, ((int)ft_strlen(fr) - 1)) : 0;
		ft_print_str_of_char(width, ' ');
	}
	else
		non_sign_float_fill(lst, fr, wh, width);
	g_fl_sign = 0;
}

void		ft_print_float(t_lst *lst, va_list ptr, long double i)
{
	long double			fract;
	unsigned long long	whole;
	char				*fr;
	char				*wh;

	g_fl_sign = 0;
	set_arg(lst, ptr);
	i = set_size_float(lst, ptr);
	if (i != i || (i * 2 == i && i != 0))
	{
		fill_nan_inf(i, lst);
		return ;
	}
	(i < 0 || (check_minus_zero(i) == 1 && i == 0)) ? (g_fl_sign = 1) : 0;
	(i < 0) ? (i = -i) : 0;
	whole = (unsigned long long)i;
	fract = i - whole;
	fr = get_precision_float(lst, fract);
	fr = round_float(fr, &whole, lst, 0);
	wh = ft_itoa_base_p(lst, 0, whole, 10);
	fill_float(lst, fr, wh);
	free(wh);
	free(fr);
}
