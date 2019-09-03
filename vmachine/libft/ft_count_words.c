/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:10:50 by vpelivan          #+#    #+#             */
/*   Updated: 2018/11/05 13:52:38 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(char const *s, char c)
{
	size_t	words;
	char	*tmp;

	tmp = (char *)s;
	words = 0;
	if (!tmp)
		return (0);
	if (*tmp != c && *tmp != '\0')
		words++;
	while (*tmp)
	{
		if (*tmp == c && *tmp + 1 != c && *tmp + 1 != 0)
			words++;
		tmp++;
	}
	return (words);
}
