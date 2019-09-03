/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:35:26 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/06 18:03:06 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *tmp;

	tmp = (char *)s;
	if (!tmp)
		return (NULL);
	while (*tmp)
	{
		if (*tmp == c)
			return ((char*)&*tmp);
		tmp++;
	}
	if (c == '\0')
		return ((char*)&*tmp);
	return (NULL);
}
