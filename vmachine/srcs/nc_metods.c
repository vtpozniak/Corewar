/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_metods.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:44:37 by vdanyliu          #+#    #+#             */
/*   Updated: 2019/08/27 17:59:54 by vdanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ncurs.h"

void		nc_clean_menu(void)
{
	int x;
	int y;

	y = 1;
	while (y < 64)
	{
		x = 1;
		wmove(g_data.ncurs->menu, y, x);
		while (x++ < 16)
			wprintw(g_data.ncurs->menu, "    ");
		y++;
	}
}
