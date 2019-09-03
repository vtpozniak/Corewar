/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:13:10 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 15:13:28 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ad_m(size_t mount)
{
	t_array	*rezult;

	rezult = malloc(sizeof(t_array));
	rezult->arr = malloc(sizeof(t_array) * mount);
	rezult->len = 0;
	rezult->max = mount;
	return (rezult);
}

void	*add_mas(void *dst, void *elem)
{
	t_array	*src;
	t_array	**rez;

	src = (t_array*)dst;
	if (src->len >= src->max)
	{
		src->max *= 2;
		rez = malloc(src->max * sizeof(t_array*));
		ft_memcpy(rez, src->arr, sizeof(t_array*) * src->len);
		free(src->arr);
		src->arr = (void **)rez;
	}
	return ((src->arr[src->len++] = elem));
}
