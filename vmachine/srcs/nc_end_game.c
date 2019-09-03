/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:00:08 by vdanyliu          #+#    #+#             */
/*   Updated: 2019/09/02 17:48:49 by vdanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ncurs.h"

void			nc_end_game(t_ncurses *ncurs, int *x, int *y)
{
	t_player *player;

	player = g_data.champs;
	while (player->next && player->num != g_data.last_live_player)
		player = player->next;
	turn_color(ncurs, g_data.last_live_player, 1, 2);
	mvwprintw(ncurs->menu, *y, *x += 5, "Player %i (%s) won",
			g_data.last_live_player, player->data->prog_name);
	turn_color(ncurs, g_data.last_live_player, 0, 2);
	mvwprintw(ncurs->menu, *y + 2, *x, "Press any key to exit");
	wrefresh(ncurs->menu);
	timeout(-1);
	getch();
	endwin();
	exit(0);
}
