/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:13:07 by vpelivan          #+#    #+#             */
/*   Updated: 2018/10/31 17:32:48 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char *tmp;
	char *tmp1;

	tmp = dest;
	tmp1 = (char *)src;
	if (!tmp || !tmp1)
		return (NULL);
	while (*tmp1)
	{
		*tmp++ = *tmp1++;
	}
	*tmp = '\0';
	return (dest);
}
