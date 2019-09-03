/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:21:24 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/25 12:38:55 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	__int128_t		*t_bzero_s;
	unsigned char	*uchar_s;
	size_t			i;

	if (!s)
		return ;
	t_bzero_s = (__int128_t *)s;
	uchar_s = (unsigned char *)s;
	i = n - (n % sizeof(__int128_t));
	while (i < n)
		uchar_s[i++] = 0;
	n /= sizeof(__int128_t);
	while (n)
		t_bzero_s[--n] = 0;
}
