/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:06:14 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/08 14:48:28 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_w_len(char c, char **tmp)
{
	size_t len;

	len = 0;
	while (**tmp != c && **tmp != '\0')
	{
		len++;
		(*tmp)++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*tmp;
	size_t	i;
	size_t	words;

	i = -1;
	tmp = (char *)s;
	words = ft_count_words(s, c);
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (++i < words)
	{
		while (*tmp == c)
			tmp++;
		if (!(str[i] = ft_strsub(tmp, 0, (ft_w_len(c, &tmp)))))
			return (NULL);
	}
	str[i] = 0;
	return (str);
}
