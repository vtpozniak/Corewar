/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:57:19 by vpozniak          #+#    #+#             */
/*   Updated: 2018/10/30 11:27:47 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	char *str;

	str = 0;
	while (*s != '\0')
	{
		if (*s == ch)
			str = (char *)s;
		s++;
	}
	if (*s == ch)
		str = (char *)s;
	return (str);
}
