/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:25:47 by vpozniak          #+#    #+#             */
/*   Updated: 2018/11/12 11:09:13 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *index;

	while (!alst || !del)
		return ;
	while (*alst)
	{
		index = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = index;
	}
	*alst = (NULL);
	return ;
}
