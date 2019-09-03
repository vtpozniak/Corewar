/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:04:21 by vdanyliu          #+#    #+#             */
/*   Updated: 2019/08/30 13:38:36 by vdanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ncurs.h"

static void	nc_speed_change(char c)
{
	if (g_timeout >= 0)
	{
		if (c == 43 && g_timeout != 0)
		{
			g_timeout -= 10;
		}
		if (c == 45 && g_timeout != 1000)
		{
			g_timeout += 10;
		}
	}
}

void		nc_parcer(char c)
{
	static int	prev_speed = -1;
	int			buff;

	if (c == 32)
	{
		buff = g_timeout;
		g_timeout = prev_speed;
		prev_speed = buff;
	}
	if (c == 43 || c == 45)
		nc_speed_change(c);
}
