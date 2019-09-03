/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:33:22 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 16:43:36 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_minus_zero(double i)
{
	long long *tmp;
	long long bitmove;
	long long j;

	tmp = (long long *)(&i);
	bitmove = *tmp;
	j = bitmove >> 63;
	if (j < 0)
		return (1);
	return (0);
}

void	get_color2(const char *format, size_t *j, size_t len)
{
	if (!ft_strncmp(format, "{purple}", 8))
	{
		ft_fill_buff(PURPLE, 5);
		len += 8;
		g_len -= 5;
	}
	else if (!ft_strncmp(format, "{cyan}", 6))
	{
		ft_fill_buff(CYAN, 5);
		len += 6;
		g_len -= 5;
	}
	else if (!ft_strncmp(format, "{eoc}", 5))
	{
		ft_fill_buff(EOC, 4);
		len += 5;
		g_len -= 4;
	}
	*j += len;
}

void	get_color(const char *format, size_t *j, size_t len)
{
	if (!ft_strncmp(format, "{red}", 5))
	{
		ft_fill_buff(RED, 5);
		len += 5;
		g_len -= 5;
	}
	else if (!ft_strncmp(format, "{green}", 7))
	{
		ft_fill_buff(GREEN, 5);
		len += 7;
		g_len -= 5;
	}
	else if (!ft_strncmp(format, "{yellow}", 8))
	{
		ft_fill_buff(YELLOW, 5);
		len += 8;
		g_len -= 5;
	}
	else if (!ft_strncmp(format, "{blue}", 6))
	{
		ft_fill_buff(BLUE, 5);
		len += 6;
		g_len -= 5;
	}
	*j += len;
}

int		check_colors(const char *format)
{
	int i;

	i = 0;
	(!ft_strncmp(format, "{red}", 5)) ? i = 1 : 0;
	(!ft_strncmp(format, "{green}", 7)) ? i = 1 : 0;
	(!ft_strncmp(format, "{yellow}", 8)) ? i = 1 : 0;
	(!ft_strncmp(format, "{blue}", 6)) ? i = 1 : 0;
	(!ft_strncmp(format, "{purple}", 8)) ? i = 1 : 0;
	(!ft_strncmp(format, "{cyan}", 6)) ? i = 1 : 0;
	(!ft_strncmp(format, "{eoc}", 5)) ? i = 1 : 0;
	return (i);
}
