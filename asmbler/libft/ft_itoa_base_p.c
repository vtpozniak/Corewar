/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:07:11 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:07:12 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	base_len(uintmax_t n, uintmax_t base)
{
	uintmax_t		count;

	count = 0;
	while ((n = n / base))
		++count;
	return (++count);
}

char				*ft_itoa_base(t_print *la, uintmax_t n, int base)
{
	char			*out;
	uintmax_t		len;

	len = base_len(n, base);
	out = (char *)malloc(sizeof(char) * len + 1);
	out[len] = '\0';
	while (len--)
	{
		if (la->q.xl > 0)
			out[len] = "0123456789ABCDEF"[n % base];
		else
			out[len] = "0123456789abcdef"[n % base];
		n /= base;
	}
	return (out);
}
