/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:38:46 by vpelivan          #+#    #+#             */
/*   Updated: 2019/09/03 12:38:48 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		error(char *arg)
{
	if (arg)
		ft_printf("{red}%s{eoc}\n", arg);
	exit(1);
}

static void	init_data(void)
{
	g_data.players_num = 0;
	g_data.max_n_number = 0;
	g_data.dump_flag = 0;
	g_data.ncurses_flag = 0;
	g_data.nbr_cycles = 0;
	g_data.champs = NULL;
	g_data.arena = NULL;
	g_data.last_live_player = 0;
	g_data.last_live_cycle = 0;
	g_data.live_in_current = 0;
	g_data.live_total = 0;
	g_data.total_cycles = 0;
	g_data.carrs_num = 0;
	g_data.cycles_to_die = CYCLE_TO_DIE;
	g_data.cycles_to_check = g_data.cycles_to_die;
	g_data.last_mod_c_to_d = g_data.cycles_to_die;
	g_data.checks_num = 0;
	g_data.ncur_stealth = 0;
}

void		print_usage(void)
{
	ft_printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", USG_1, USG_2, USG_3, USG_4,
	USG_5, USG_6, USG_7, USG_8, USG_9, USG_10, USG_11, USG_12, USG_13, USG_14,
	USG_15, USG_16);
	exit(0);
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		init_data();
		validate_args(av);
		parse_champs();
		sort_players();
		create_arena();
		intro();
		start_war();
	}
	else
		print_usage();
	return (0);
}
