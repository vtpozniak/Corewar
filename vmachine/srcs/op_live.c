/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:53:40 by vpelivan          #+#    #+#             */
/*   Updated: 2019/09/01 17:53:41 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	change_player_data(t_carr *carriage, int32_t arg)
{
	t_player	*player;

	player = g_data.champs;
	while (player->num != carriage->pl_num)
		player = player->next;
	if (g_data.v1_flag)
		ft_printf("Player %d (%s) is said to be alive\n",
		carriage->pl_num, player->data->prog_name);
	g_data.last_live_player = arg;
	g_data.last_live_cycle = carriage->last_live_cycle;
	player->last_live = g_data.total_cycles;
	g_data.live_in_current++;
	player->lives++;
}

void		op_live(t_carr *carriage)
{
	int32_t		arg;

	arg = get_n_bytes(4, carriage->pc + 1);
	carriage->pc = get_pos(carriage->pc + g_op_tab[1].label_size);
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d\n", carriage->id, g_op_tab[1].op_name, arg);
	carriage->last_live_cycle = g_data.total_cycles;
	(arg < 0) ? arg *= -1 : 0;
	if (arg > 0 && arg <= g_data.players_num)
		change_player_data(carriage, arg);
	g_data.arena[carriage->pc_start].turns = 50;
	g_data.live_total++;
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
	carriage->pc = get_pos(carriage->pc + 1);
}
