/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:51:09 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 18:38:33 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_nonprc_str(const char *s, int j, int len, char *tmp)
{
	int i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '\t' || s[i] == '\r'
		|| s[i] == '\v' || s[i] == '\a' || s[i] == '\b' || s[i] == '\f')
		{
			tmp[j] = '\0';
			(s[i] == '\n') ? tmp = ft_strcat(tmp, "\\n") : 0;
			(s[i] == '\t') ? tmp = ft_strcat(tmp, "\\t") : 0;
			(s[i] == '\r') ? tmp = ft_strcat(tmp, "\\r") : 0;
			(s[i] == '\v') ? tmp = ft_strcat(tmp, "\\v") : 0;
			(s[i] == '\a') ? tmp = ft_strcat(tmp, "\\a") : 0;
			(s[i] == '\b') ? tmp = ft_strcat(tmp, "\\b") : 0;
			(s[i] == '\f') ? tmp = ft_strcat(tmp, "\\f") : 0;
			j += 2;
		}
		tmp[j++] = s[i++];
	}
	tmp = ft_strcat(tmp, "\\0");
	j += 2;
	tmp[j] = '\0';
	return (tmp);
}

char	*format_nonprc(char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	tmp = NULL;
	len = (int)ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\a' || str[i] == '\b'
		|| str[i] == '\f')
			len += 3;
		i++;
	}
	len += 3;
	tmp = get_nonprc_str(str, 0, len, tmp);
	return (tmp);
}

void	print_format_no_spec(const char *format, size_t *i)
{
	int		len;
	size_t	j;

	len = 0;
	j = *i;
	while (format[j] && format[j] != '%' && format[j] != '{')
	{
		len++;
		j++;
	}
	ft_fill_buff(&format[*i], len);
	if (format[j] == '{' && check_colors(&format[j]) == 1)
	{
		get_color(&format[j], &j, 0);
		get_color2(&format[j], &j, 0);
	}
	else if (format[j] == '{' && check_colors(&format[j]) == 0)
	{
		ft_fill_buff(&format[j], 1);
		j++;
	}
	*i = j;
}

void	read_specif(t_lst *lst, va_list ptr)
{
	if (lst->type == '%')
		ft_print_percent(lst);
	if (lst->type == 'c')
		ft_print_char(lst, ptr);
	if (lst->type == 's' || lst->type == 'r')
		ft_print_str(lst, ptr);
	if (lst->type == 'i' || lst->type == 'd' || lst->type == 'b')
		ft_print_i_d(lst, ptr);
	if (lst->type == 'x' || lst->type == 'X' || lst->type == 'o'
	|| lst->type == 'u' || lst->type == 'p')
		ft_print_hex_oct_uns_p(lst, ptr);
	if (lst->type == 'f' || lst->type == 'F')
		ft_print_float(lst, ptr, 0.0);
}

int		ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	ptr;
	t_lst	list;

	g_len = 0;
	g_count = g_len;
	ft_bzero(g_buff, 8192);
	va_start(ptr, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			g_flag = 0;
			create_list(format, &i, ptr, &list);
		}
		else
			print_format_no_spec(format, &i);
	}
	va_end(ptr);
	ft_print_buff(g_buff);
	return (g_len);
}
