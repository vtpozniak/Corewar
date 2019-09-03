/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_parsers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:36:32 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/22 16:36:33 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_list_flags(const char *s, size_t *i, t_lst *list)
{
	if (s[*i] == '#')
		list->hash_flag = '#';
	if (s[*i] == '-' || s[*i] == '0')
	{
		if (list->flags == '-')
		{
			*i += 1;
			return ;
		}
		else
			list->flags = s[*i];
	}
	if (s[*i] == ' ')
	{
		if (list->prior_plus == '+')
		{
			*i += 1;
			return ;
		}
		else
			list->prior_space = s[*i];
	}
	if (s[*i] == '+')
		list->prior_plus = s[*i];
	*i += 1;
}

void	create_list_size(const char *s, size_t *i, t_lst *list)
{
	if (s[*i] == 'h' && s[*i + 1] != 'h' && list->size[0] != 'l'
			&& list->size[0] != 'z' && list->size[0] != 'j')
		list->size = "h";
	if (s[*i] == 'l' && s[*i + 1] != 'l' && list->size[0] != 'l'
	&& list->size[1] != 'l' && list->size[0] != 'z' && list->size[0] != 'j')
		list->size = "l";
	if (s[*i] == 'h' && s[*i + 1] == 'h' && list->size[0] != 'h'
	&& list->size[0] != 'l' && list->size[1] != 'l' && list->size[0] != 'z'
	&& list->size[0] != 'j')
	{
		*i += 1;
		list->size = "hh";
	}
	if (s[*i] == 'l' && s[*i + 1] == 'l' && list->size[0] != 'z'
	&& list->size[0] != 'j')
	{
		*i += 1;
		list->size = "ll";
	}
	(s[*i] == 'z' && list->size[0] != 'j') ? list->size = "z" : 0;
	(s[*i] == 'j') ? list->size = "j" : 0;
	(s[*i] == 'L') ? list->big_l_size = 'L' : 0;
	*i += 1;
}

int		create_list_width(const char *s, size_t *i, t_lst *list, va_list ptr)
{
	int result;

	result = 0;
	if (s[*i] == '*')
	{
		list->width_as_arg = '*';
		list->width = va_arg(ptr, int);
		(list->width < 0 && list->width_as_arg == '*') ? list->flags = '-' : 0;
		(list->width < 0 && list->width_as_arg == '*') ? list->width *= -1 : 0;
		*i += 1;
		result = list->width;
	}
	else
		result = ft_atoi_i(s, &*i);
	return (result);
}

int		create_list_precision(const char *s, size_t *i, t_lst *list)
{
	int result;

	result = 0;
	*i += 1;
	if (s[*i] == '*')
	{
		list->precision_as_arg = '*';
		*i += 1;
	}
	else if (s[*i] >= '0' && s[*i] <= '9')
		result = ft_atoi_i(s, &*i);
	return (result);
}

char	create_list_type(const char *s, size_t *i)
{
	char c;

	c = s[*i];
	*i += 1;
	return (c);
}
