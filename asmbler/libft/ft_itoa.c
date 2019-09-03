/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:06:56 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:06:58 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t	ftlen(intmax_t n)
{
	intmax_t		i;
	intmax_t		k;

	k = 0;
	if (n < 0)
		k = 1;
	i = 1;
	while (n /= 10)
		i++;
	return (i + k);
}

char			*ft_itoa(intmax_t n)
{
	char			*str;
	intmax_t		len;
	uintmax_t		num;

	len = ftlen(n);
	num = n;
	if (n < 0)
		num = n * -1;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
