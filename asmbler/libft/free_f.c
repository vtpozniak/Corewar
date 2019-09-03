/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:15:08 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 15:15:11 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free(char **arr, int len)
{
	int		i;

	i = len;
	if (len == 0)
		while (arr[i])
			free(arr[i++]);
	else
		while (i != -1 && arr[i])
			free(arr[i--]);
	free(arr);
}
