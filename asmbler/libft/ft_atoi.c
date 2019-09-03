/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:25:41 by vpozniak          #+#    #+#             */
/*   Updated: 2018/10/29 18:01:31 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		j;

	i = 0;
	nb = 0;
	j = 1;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		j = -1;
		if (str[i] == 43)
			j = 1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		if (9223372036854775807 - nb < str[i] - '0')
			return (j == -1 ? 0 : -1);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * j);
}
