/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:40:00 by vpelivan          #+#    #+#             */
/*   Updated: 2019/08/15 16:40:02 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	op_ld(t_carr *carriage)
{
	int32_t adr;
	t_arg	*args;

	args = g_op_tab[2].args;
	if (args[0].type == DIR_CODE)
		carriage->reg[args[1].reg_num] = args[0].value;
	else if (args[0].type == IND_CODE)
	{
		args[0].value %= IDX_MOD;
		adr = get_pos(carriage->pc_start + (args[0].value % IDX_MOD));
		args[0].value = get_n_bytes(4, adr);
		carriage->reg[args[1].reg_num] = args[0].value;
	}
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d r%d\n", carriage->id, g_op_tab[2].op_name,
			args[0].value, args[1].reg_num + 1);
	if (args[0].value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_st(t_carr *carriage)
{
	int32_t adr;
	t_arg	*args;

	args = g_op_tab[3].args;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s r%d %d\n", carriage->id, g_op_tab[3].op_name,
			args[0].reg_num + 1, args[1].value);
	if (args[1].type == REG_CODE)
		carriage->reg[args[1].reg_num] = args[0].value;
	else if (args[1].type == IND_CODE)
	{
		args[1].value %= IDX_MOD;
		adr = get_pos(carriage->pc_start + (args[1].value % IDX_MOD));
		write_n_bytes(args[0].value, REG_SIZE, adr, carriage);
	}
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_add(t_carr *carriage)
{
	int32_t value;
	t_arg	*args;

	args = g_op_tab[4].args;
	value = args[0].value + args[1].value;
	carriage->reg[args[2].reg_num] = value;
	carriage->carry = (value == 0) ? 1 : 0;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s r%d r%d r%d\n", carriage->id, g_op_tab[4].op_name,
		args[0].reg_num + 1, args[1].reg_num + 1, args[2].reg_num + 1);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_sub(t_carr *carriage)
{
	int32_t value;
	t_arg	*args;

	args = g_op_tab[5].args;
	value = args[0].value - args[1].value;
	carriage->reg[args[2].reg_num] = value;
	carriage->carry = (value == 0) ? 1 : 0;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s r%d r%d r%d\n", carriage->id, g_op_tab[5].op_name,
		args[0].reg_num + 1, args[1].reg_num + 1, args[2].reg_num + 1);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_and(t_carr *carriage)
{
	int32_t	value;
	int32_t	adr;
	t_arg	*args;

	args = g_op_tab[6].args;
	if (args[0].type == IND_CODE)
	{
		args[0].value %= IDX_MOD;
		adr = get_pos(carriage->pc_start + (args[0].value % IDX_MOD));
		args[0].value = get_n_bytes(4, adr);
	}
	if (args[1].type == IND_CODE)
	{
		args[1].value %= IDX_MOD;
		adr = get_pos(carriage->pc_start + (args[1].value % IDX_MOD));
		args[1].value = get_n_bytes(4, adr);
	}
	value = args[0].value & args[1].value;
	carriage->reg[args[2].reg_num] = value;
	carriage->carry = (value == 0) ? 1 : 0;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d %d r%d\n", carriage->id, g_op_tab[6].op_name,
		args[0].value, args[1].value, args[2].reg_num + 1);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}
