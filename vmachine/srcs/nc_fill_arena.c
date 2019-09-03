/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_fill_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:43:37 by vdanyliu          #+#    #+#             */
/*   Updated: 2019/08/30 13:45:31 by vdanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ncurs.h"

void	nc_fill_arena_carrege(t_ncurses *ncurs, t_carr *carr)
{
	int y;
	int x;

	while (carr)
	{
		if (g_data.arena[carr->pc].turns != 0)
		{
			wattron(ncurs->border, A_BOLD);
			wattron(ncurs->border, COLOR_PAIR(carr->pl_num + 8));
		}
		else
			wattron(ncurs->border, COLOR_PAIR(carr->pl_num + 4));
		y = carr->pc / 64 + 2;
		x = carr->pc % 64 * 3 + 2;
		g_data.ncur_stealth == 0 ? mvwprintw(ncurs->border, y, x, "%.2x",
		g_data.arena[carr->pc].c) : mvwprintw(ncurs->border, y, x, "ff");
		wattrset(ncurs->border, A_NORMAL);
		carr = carr->next;
	}
}

void	nc_fill_arena(t_ncurses *ncurs)
{
	int x;
	int y;
	int i;

	x = 2;
	y = 2;
	i = 0;
	while (y <= 65)
	{
		while (x <= 192)
		{
			turn_color(ncurs, i, 1, 1);
			g_data.ncur_stealth == 1 ? mvwprintw(ncurs->border, y, x, "ff") :
			mvwprintw(ncurs->border, y, x, "%.2x", g_data.arena[i].c);
			x += 3;
			turn_color(ncurs, i, 0, 1);
			g_data.arena[i].turns != 0 ? g_data.arena[i].turns -= 1 : 0;
			i++;
		}
		x = 2;
		y++;
	}
	nc_fill_arena_carrege(ncurs, g_data.carrs);
	wrefresh(ncurs->border);
}

void	eternity_test(void)
{
	nc_fill_menu(g_data.ncurs);
	nc_fill_arena(g_data.ncurs);
	timeout(g_timeout);
	nc_parcer(getch());
}
