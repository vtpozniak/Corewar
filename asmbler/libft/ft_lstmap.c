/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:17:44 by vpozniak          #+#    #+#             */
/*   Updated: 2018/11/12 11:52:34 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *a;
	t_list *b;

	if (!lst || !f)
		return (NULL);
	b = f(lst);
	a = b;
	while (lst->next)
	{
		lst = lst->next;
		if (!(b->next = f(lst)))
		{
			free(b->next);
			return (NULL);
		}
		b = b->next;
	}
	return (a);
}
