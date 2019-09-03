/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:32:44 by vpozniak          #+#    #+#             */
/*   Updated: 2018/10/30 11:52:10 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *des, const char *str, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (des[i] != '\0')
		i++;
	while (str[j] != '\0' && j < n)
	{
		des[i] = str[j];
		i++;
		j++;
	}
	des[i] = '\0';
	return (des);
}
