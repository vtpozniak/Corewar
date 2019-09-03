/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_lst_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:38:37 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 16:42:48 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create_list_init(t_lst *list)
{
	list->hash_flag = 'n';
	list->prior_space = 'n';
	list->prior_plus = 'n';
	list->flags = 'n';
	list->width = 0;
	list->width_as_arg = 'n';
	list->precision = -1;
	list->precision_as_arg = 'n';
	list->size = "n";
	list->big_l_size = 'n';
	list->type = 'n';
}

static int	check_list_type(const char *s, size_t *i)
{
	if (s[*i] == 'd' || s[*i] == 'i' || s[*i] == 'f' || s[*i] == 'u'
	|| s[*i] == 's' || s[*i] == 'c' || s[*i] == '%' || s[*i] == 'x'
	|| s[*i] == 'X' || s[*i] == 'o' || s[*i] == 'p' || s[*i] == 'r'
	|| s[*i] == 'F' || s[*i] == 'b')
		return (1);
	return (0);
}

void		create_list(const char *s, size_t *i, va_list ptr, t_lst *list)
{
	create_list_init(list);
	while (s[*i] != 's' && s[*i] != 'c' && s[*i] != '%' && s[*i] != 'd'
	&& s[*i] != 'i' && s[*i] != 'f' && s[*i] != 'u' && s[*i] != 'x' &&
	s[*i] != 'X' && s[*i] != 'o' && s[*i] != 'p' && s[*i] != 'r' &&
	s[*i] != 'F' && s[*i] != 'b' && s[*i])
	{
		if (s[*i] == '-' || s[*i] == '0' || s[*i] == ' ' || s[*i] == '+'
		|| s[*i] == '#')
			create_list_flags(s, &*i, list);
		if ((s[*i] >= '1' && s[*i] <= '9') || s[*i] == '*')
			list->width = create_list_width(s, &*i, list, ptr);
		if (s[*i] == '.')
			list->precision = create_list_precision(s, &*i, list);
		if (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'j' || s[*i] == 'z'
		|| s[*i] == 'L')
			create_list_size(s, &*i, list);
		if (ft_strchr(" .-+#lLhjz0123456789*", s[*i]) != NULL)
			continue ;
		else
			break ;
	}
	if (check_list_type(s, &*i) == 1)
		list->type = create_list_type(s, &*i);
	read_specif(list, ptr);
}
