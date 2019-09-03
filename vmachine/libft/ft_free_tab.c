/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:08:56 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/28 18:09:02 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	char **tmp;

	tmp = tab;
	if (!tmp)
		return ;
	while (*tmp != 0)
	{
		free(*tmp);
		tmp++;
	}
	free(tab);
}
