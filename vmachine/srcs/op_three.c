/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:40:24 by vpelivan          #+#    #+#             */
/*   Updated: 2019/08/15 16:40:27 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	op_fork(t_carr *carriage)
{
	int32_t	adr;
	int32_t	adr2;
	int		i;

	i = -1;
	adr = get_n_bytes(g_op_tab[12].label_size, carriage->pc + 1);
	carriage->pc = get_pos(carriage->pc + g_op_tab[12].label_size);
	adr2 = adr % IDX_MOD;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d (%d)\n", carriage->id, g_op_tab[12].op_name,
		adr, adr2 + carriage->pc_start);
	new_carriage(carriage->pl_num, get_pos(adr2 + carriage->pc_start));
	g_data.carrs->carry = carriage->carry;
	g_data.carrs->last_live_cycle = carriage->last_live_cycle;
	while (++i < REG_NUMBER)
		g_data.carrs->reg[i] = carriage->reg[i];
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
	carriage->pc = get_pos(carriage->pc + 1);
}

void	op_lld(t_carr *carriage)
{
	int32_t adr;
	int32_t value;
	t_arg	*args;

	args = g_op_tab[13].args;
	if (args[0].type == DIR_CODE)
		carriage->reg[args[1].reg_num] = args[0].value;
	else if (args[0].type == IND_CODE)
	{
		adr = get_pos(carriage->pc_start + args[0].value);
		value = get_n_bytes(4, adr);
		carriage->reg[args[1].reg_num] = value;
	}
	carriage->carry = (!carriage->reg[args[1].reg_num]) ? 1 : 0;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d r%d\n", carriage->id, g_op_tab[13].op_name,
		args[0].value, args[1].reg_num + 1);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_lldi(t_carr *carriage)
{
	int32_t adr;
	t_arg	*args;

	args = g_op_tab[14].args;
	if (args[0].type == IND_CODE)
	{
		adr = get_pos(carriage->pc_start + (args[0].value % IDX_MOD));
		args[0].value = get_n_bytes(4, adr);
	}
	adr = get_pos(carriage->pc_start + args[0].value + args[1].value);
	carriage->reg[args[2].reg_num] = get_n_bytes(4, adr);
	carriage->carry = (!carriage->reg[args[2].reg_num]) ? 1 : 0;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d %d r%d\n       | -> load from %d + %d = %d "
		"(with pc and mod %d)\n", carriage->id, g_op_tab[14].op_name,
		args[0].value, args[1].value, args[2].reg_num + 1, args[0].value,
		args[1].value, args[0].value + args[1].value, adr);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_lfork(t_carr *carriage)
{
	int32_t	adr;
	int		i;

	i = -1;
	adr = get_n_bytes(g_op_tab[15].label_size, carriage->pc + 1);
	carriage->pc = get_pos(carriage->pc + g_op_tab[15].label_size);
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d (%d)\n", carriage->id, g_op_tab[15].op_name,
		adr, adr + carriage->pc_start);
	new_carriage(carriage->pl_num, get_pos(adr + carriage->pc_start));
	g_data.carrs->carry = carriage->carry;
	g_data.carrs->last_live_cycle = carriage->last_live_cycle;
	while (++i < REG_NUMBER)
		g_data.carrs->reg[i] = carriage->reg[i];
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
	carriage->pc = get_pos(carriage->pc + 1);
}

void	op_aff(t_carr *carriage)
{
	int32_t	value;

	value = g_op_tab[16].args[0].value;
	if (!g_data.ncurses_flag)
		ft_printf("%c\n", (char)(value % 256));
	if (g_data.v4_flag)
		ft_printf("P%5d | %s\n", carriage->id, g_op_tab[16].op_name);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}
