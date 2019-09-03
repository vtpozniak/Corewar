/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:18:06 by vpozniak          #+#    #+#             */
/*   Updated: 2018/10/31 16:52:24 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*rez;
	unsigned char	*help;
	unsigned int	i;

	i = 0;
	rez = malloc(size);
	if (rez == NULL)
		return (rez);
	help = rez;
	while (i < size)
	{
		help[i] = '\0';
		i++;
	}
	return (help);
}
