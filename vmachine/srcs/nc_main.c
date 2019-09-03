/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:48:35 by vdanyliu          #+#    #+#             */
/*   Updated: 2019/08/30 13:52:40 by vdanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ncurs.h"

void	nc_create_color(void)
{
	init_pair(1, COLOR_CYAN, 0);
	init_pair(2, 3, 0);
	init_pair(3, COLOR_RED, 0);
	init_pair(4, 2, 0);
	init_pair(5, 0, COLOR_CYAN);
	init_pair(6, 0, 3);
	init_pair(7, 0, COLOR_RED);
	init_pair(8, 0, 2);
	init_pair(9, COLOR_WHITE, COLOR_CYAN);
	init_pair(10, COLOR_WHITE, 3);
	init_pair(11, COLOR_WHITE, COLOR_RED);
	init_pair(12, COLOR_WHITE, 2);
}

void	nc_create_border(t_ncurses *ncurs)
{
	start_color();
	ncurs->border = newwin(68, 195, 0, 0);
	ncurs->menu = newwin(68, 68, 0, 194);
	refresh();
	wattron(ncurs->border, A_STANDOUT);
	wattron(ncurs->menu, A_STANDOUT);
	wborder(ncurs->border, 1, 1, 1, 1, 1, 1, 1, 1);
	wborder(ncurs->menu, 1, 1, 1, 1, 1, 1, 1, 1);
	wattroff(ncurs->border, A_STANDOUT);
	wattroff(ncurs->menu, A_STANDOUT);
	wrefresh(ncurs->border);
	wrefresh(ncurs->menu);
}

void	nc_init(void)
{
	g_data.ncurs = (t_ncurses*)ft_memalloc(sizeof(t_ncurses));
	initscr();
	noecho();
	raw();
	cbreak();
	nc_create_border(g_data.ncurs);
	nc_create_color();
	g_timeout = 100;
}

void	turn_color(t_ncurses *ncurs, int i, int mod, int window)
{
	int player;

	player = window == 1 ? g_data.arena[i].player : i;
	if (window == 1)
	{
		if (mod)
		{
			wattron(ncurs->border, COLOR_PAIR(player));
			if (g_data.arena[i].turns != 0)
				wattron(ncurs->border, A_BOLD);
		}
		else
			wattrset(ncurs->border, A_NORMAL);
	}
	else if (window == 2)
	{
		if (mod)
			wattron(ncurs->menu, COLOR_PAIR(player));
		else
			wattrset(ncurs->menu, A_NORMAL);
	}
}

int		nc_main(void)
{
	static int init = 0;

	if (init == 0)
	{
		init++;
		nc_init();
		getch();
		nc_fill_arena(g_data.ncurs);
		nc_fill_menu(g_data.ncurs);
		getch();
	}
	eternity_test();
	return (0);
}
