/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:58:31 by vpozniak          #+#    #+#             */
/*   Updated: 2018/11/02 11:09:01 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*index;

	index = (t_list *)malloc(sizeof(t_list));
	if (!index)
		return (NULL);
	if (!content)
	{
		index->content_size = 0;
		index->content = NULL;
	}
	else
	{
		if (!(index->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(index->content, content, content_size);
		index->content_size = content_size;
	}
	index->next = NULL;
	return (index);
}
