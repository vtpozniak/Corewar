/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:59:02 by vpelivan          #+#    #+#             */
/*   Updated: 2019/05/21 18:59:05 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_gettype(const char *fmt, char s)
{
	int	i;

	i = -1;
	while (fmt[++i])
	{
		fmt[i] == 's' ? s = 's' : 0;
		fmt[i] == 'c' ? s = 'c' : 0;
		fmt[i] == 'i' || fmt[i] == 'd' ? s = 'd' : 0;
		fmt[i] == 'u' || fmt[i] == 'o' || fmt[i] == 'x' || fmt[i] == 'X' ?
				s = 'u' : 0;
	}
	return (s);
}

void		ft_lstprint(t_list *head, char *fmt)
{
	t_list	*tmp;
	char	s;

	tmp = head;
	s = 0;
	s = ft_gettype(fmt, s);
	while (tmp != NULL)
	{
		if (s == 0)
			return ;
		s == 's' ? ft_printf(fmt, (char *)tmp->content) : 0;
		s == 'c' ? ft_printf(fmt, (char)tmp->content) : 0;
		s == 'd' ? ft_printf(fmt, (int)tmp->content) : 0;
		s == 'u' ? ft_printf(fmt, (unsigned int)tmp->content) : 0;
		tmp = tmp->next;
	}
}
