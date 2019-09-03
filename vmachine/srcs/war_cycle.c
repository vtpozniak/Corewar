/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:06:29 by vpelivan          #+#    #+#             */
/*   Updated: 2019/08/07 13:06:30 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/ncurs.h"

void		set_op_code(t_carr *carriage)
{
	if (carriage->op_code < 1 || carriage->op_code > 16)
	{
		carriage->pc = get_pos(carriage->pc);
		carriage->op_code = g_data.arena[carriage->pc].c;
		if (carriage->op_code < 1 || carriage->op_code > 16)
		{
			carriage->op_code = 0;
			carriage->cycles_to_op = 0;
			carriage->pc = get_pos(carriage->pc + 1);
		}
		else
			carriage->cycles_to_op = g_op_tab[carriage->op_code].cycles_to_op;
	}
}

short		check_codage(t_carr *carriage)
{
	if (carriage->op_code == 2 || carriage->op_code == 13)
		return (op_codage_ld_lld(carriage));
	else if (carriage->op_code == 3)
		return (op_codage_st(carriage));
	else if (carriage->op_code == 4 || carriage->op_code == 5)
		return (op_codage_add_sub(carriage));
	else if (carriage->op_code == 6 || carriage->op_code == 7
	|| carriage->op_code == 8)
		return (op_codage_and_or_xor(carriage));
	else if (carriage->op_code == 10 || carriage->op_code == 14)
		return (op_codage_ldi_lldi(carriage));
	else if (carriage->op_code == 11)
		return (op_codage_sti(carriage));
	else if (carriage->op_code == 16)
		return (op_codage_aff(carriage));
	else
		return (0);
}

void		change_cycles_to_die(void)
{
	t_player *player;

	player = g_data.champs;
	g_data.cycles_to_die -= CYCLE_DELTA;
	g_data.last_mod_c_to_d = g_data.cycles_to_die;
	g_data.checks_num = 0;
	g_data.live_in_current = 0;
	while (player)
	{
		player->lives = 0;
		player = player->next;
	}
	(g_data.v2_flag == 1) ? ft_printf("Cycle to die is now %d\n",
	g_data.cycles_to_die) : 0;
}

static void	perform_check(void)
{
	t_carr	*carriage;
	t_carr	*next;

	carriage = g_data.carrs;
	g_data.checks_num++;
	while (carriage)
	{
		if (g_data.total_cycles - carriage->last_live_cycle >=
		g_data.cycles_to_die || g_data.cycles_to_die <= 0)
		{
			next = carriage->next;
			delete_carriage(carriage);
			carriage = next;
			continue ;
		}
		carriage = carriage->next;
	}
	if (g_data.live_total >= NBR_LIVE || (g_data.checks_num == MAX_CHECKS
	&& g_data.last_mod_c_to_d == g_data.cycles_to_die))
		change_cycles_to_die();
	g_data.cycles_to_check = g_data.cycles_to_die;
	g_data.live_total = 0;
}

void		start_war(void)
{
	t_carr	*carriage;

	while ("forty two")
	{
		if (g_data.dump_flag && g_data.nbr_cycles == g_data.total_cycles)
			dump_arena();
		g_data.total_cycles++;
		g_data.cycles_to_check--;
		(g_data.v2_flag == 1) ? ft_printf("It is now cycle %d\n",
				g_data.total_cycles) : 0;
		carriage = g_data.carrs;
		while (carriage)
		{
			(!carriage->op_code) ? set_op_code(carriage) : 0;
			(carriage->cycles_to_op > 0) ? carriage->cycles_to_op-- : 0;
			(carriage->cycles_to_op == 0 && carriage->op_code) ?
			parse_op_arg(carriage) : 0;
			carriage = carriage->next;
		}
		if (g_data.cycles_to_check == 0 || g_data.cycles_to_die <= 0)
			perform_check();
		if (g_data.ncurses_flag)
			nc_main();
		g_data.carrs == NULL ? game_over() : 0;
	}
}
