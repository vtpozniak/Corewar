/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_fill_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:57:00 by vdanyliu          #+#    #+#             */
/*   Updated: 2019/08/30 13:41:23 by vdanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ncurs.h"

void	nc_write_status(t_ncurses *ncurs, int *x, int *y)
{
	if (!(ncurs->status))
	{
		mvwprintw(ncurs->menu, *y, *x += 5,
				"Press f to pay respect or any key to start");
		ncurs->status += 1;
	}
	else if (g_timeout == -1)
	{
		mvwprintw(ncurs->menu, *y, *x += 5, "** PAUSED **");
	}
	else
	{
		mvwprintw(ncurs->menu, *y, *x += 5, "** SPEED: %d%% **",
				100 - ((g_timeout) / 10));
	}
	mvwprintw(ncurs->menu, *y += 3, *x, "Cycle: %d", g_data.total_cycles);
	*x = 2;
}

void	nc_write_debug_info(t_ncurses *ncurs, int *x, int *y)
{
	mvwprintw(ncurs->menu, (*y) += 2, *x += 5, "Processes: %d",
	g_data.carrs_num);
	mvwprintw(ncurs->menu, (*y) += 5, *x, "CYCLE_TO_DIE: %d",
			g_data.cycles_to_die);
	mvwprintw(ncurs->menu, (*y) += 2, *x, "CYCLE_DELTA: %d",
			CYCLE_DELTA);
	mvwprintw(ncurs->menu, (*y) += 2, *x, "NBR_LIVE: %d", NBR_LIVE);
	mvwprintw(ncurs->menu, (*y) += 2, *x, "MAX_CHECKS: %d", MAX_CHECKS);
	*x = 2;
	*y += 5;
}

void	nc_write_players(t_ncurses *ncurs, int *x, int *y)
{
	t_player	*temp;
	int			p;

	p = 1;
	temp = g_data.champs;
	while (temp)
	{
		turn_color(ncurs, p, 1, 2);
		mvwprintw(ncurs->menu, (*y)++, *x = 7, "Player %d : %.40s",
				p, temp->data->prog_name);
		turn_color(ncurs, p++, 0, 2);
		*x = 10;
		mvwprintw(ncurs->menu, (*y)++, *x, "Last live: %d", temp->last_live);
		mvwprintw(ncurs->menu, (*y)++, *x, "Lives in current period: %d",
		temp->lives);
		*x = 2;
		*y += 2;
		temp = temp->next;
	}
}

void	nc_fill_menu(t_ncurses *ncurs)
{
	static int x = 2;
	static int y = 2;

	if (!g_data.carrs)
		nc_end_game(ncurs, &x, &y);
	x = 2;
	y = 2;
	nc_clean_menu();
	nc_write_status(ncurs, &x, &y);
	nc_write_debug_info(ncurs, &x, &y);
	nc_write_players(ncurs, &x, &y);
	wrefresh(ncurs->menu);
}
