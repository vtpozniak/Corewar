/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:37:54 by vpelivan          #+#    #+#             */
/*   Updated: 2018/10/31 17:35:30 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*tmp1;

	i = ft_strlen(src);
	tmp = (char *)src;
	if (!tmp)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (i + 1));
	tmp1 = str;
	if (!str)
		return (NULL);
	while (*tmp)
		*str++ = *tmp++;
	*str = 0;
	return (tmp1);
}
