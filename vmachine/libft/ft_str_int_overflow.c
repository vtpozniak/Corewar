/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_int_overflow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:46:16 by vpelivan          #+#    #+#             */
/*   Updated: 2019/07/30 18:46:19 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_int_overflow(const char *str)
{
	int					i;
	uintmax_t			a;
	int					b;

	i = 0;
	a = 0;
	b = 1;
	if (!str)
		return (0);
	if (str[i] == '-')
		b = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - '0');
		if (a > 2147483647U && b == 1)
			return (1);
		else if (a > 2147483648U && b == -1)
			return (1);
		i++;
	}
	return (0);
}
