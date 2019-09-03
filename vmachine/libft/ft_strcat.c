/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:21:38 by vpelivan          #+#    #+#             */
/*   Updated: 2018/10/31 17:19:55 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *tmp;
	char *tmp1;

	tmp = dest;
	tmp1 = (char *)src;
	while (*tmp)
		tmp++;
	while (*tmp1)
		*tmp++ = *tmp1++;
	*tmp = '\0';
	return (dest);
}
