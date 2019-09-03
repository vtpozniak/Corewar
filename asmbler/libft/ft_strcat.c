/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:46:28 by vpozniak          #+#    #+#             */
/*   Updated: 2018/10/30 12:53:37 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *des, const char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (des[i] != '\0')
		i++;
	while (str[j] != '\0')
	{
		des[i] = str[j];
		i++;
		j++;
	}
	des[i] = '\0';
	return (des);
}
