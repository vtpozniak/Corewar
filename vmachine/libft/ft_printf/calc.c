/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:19:23 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 17:40:36 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_buff(const char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (g_count == 8190)
		{
			ft_print_buff(g_buff);
			ft_bzero(g_buff, 8192);
			g_count = 0;
		}
		g_buff[g_count++] = str[i++];
	}
	g_len += len;
}

size_t	ft_print_buff(char *str)
{
	size_t len;

	len = ft_strlen(g_buff);
	write(1, str, len);
	return (len);
}

int		ft_atoi_i(const char *str, size_t *i)
{
	unsigned long int	a;
	int					b;

	a = 0;
	b = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '-')
		b = -1;
	if (str[*i] == '+' || str[*i] == '-')
		*i += 1;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		if (a > 922337203685477580U && b == 1)
			return (-1);
		else if (a > 922337203685477580U && b == -1)
			return (0);
		a = a * 10 + (str[*i] - '0');
		*i += 1;
	}
	return ((int)(a * b));
}

void	ft_print_str_of_char(int len, char c)
{
	char	str[len + 1];
	int		i;

	i = 0;
	str[len] = '\0';
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	if (g_flag == 1)
	{
		write(1, str, len);
		g_len += len;
		g_flag = 0;
	}
	else
		ft_fill_buff(str, len);
}

void	ft_print_flag(t_lst *lst, intmax_t i)
{
	if (i < 0 && (lst->type == 'i' || lst->type == 'd' || lst->type == 'f'
	|| lst->type == 'F'))
		ft_fill_buff("-", 1);
	if (lst->prior_space == ' ' && i >= 0 && lst->prior_plus != '+'
			&& (lst->type == 'd' || lst->type == 'i'))
		ft_fill_buff(" ", 1);
	if (lst->prior_plus == '+' && i >= 0 && (lst->type == 'i'
			|| lst->type == 'd'))
		ft_fill_buff("+", 1);
	if (lst->hash_flag == '#' || lst->type == 'p')
	{
		if ((lst->type == 'x' && i != 0)
		|| lst->type == 'p')
			ft_fill_buff("0x", 2);
		if (lst->type == 'X' && i != 0)
			ft_fill_buff("0X", 2);
		if (lst->type == 'o')
			ft_fill_buff("0", 1);
	}
}
