/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:06:41 by vpozniak          #+#    #+#             */
/*   Updated: 2018/10/30 15:37:51 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (str2 == str1)
		return (str1);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (str2 < str1)
	{
		i = n;
		while (i-- > 0)
			s1[i] = s2[i];
	}
	else
		i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return ((void *)str1);
}
