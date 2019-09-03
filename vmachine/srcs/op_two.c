/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:40:14 by vpelivan          #+#    #+#             */
/*   Updated: 2019/08/15 16:40:17 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	op_or(t_carr *carriage)
{
	int32_t	value;
	int32_t	adr;
	t_arg	*args;

	args = g_op_tab[7].args;
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
	value = args[0].value | args[1].value;
	carriage->reg[args[2].reg_num] = value;
	carriage->carry = (value == 0) ? 1 : 0;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d %d r%d\n", carriage->id, g_op_tab[7].op_name,
		args[0].value, args[1].value, args[2].reg_num + 1);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_xor(t_carr *carriage)
{
	int32_t	value;
	int32_t	adr;
	t_arg	*args;

	args = g_op_tab[8].args;
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
	value = args[0].value ^ args[1].value;
	carriage->reg[args[2].reg_num] = value;
	carriage->carry = (value == 0) ? 1 : 0;
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d %d r%d\n", carriage->id, g_op_tab[8].op_name,
		args[0].value, args[1].value, args[2].reg_num + 1);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_zjmp(t_carr *carriage)
{
	short	arg;

	arg = get_n_bytes(g_op_tab[9].label_size, carriage->pc + 1);
	carriage->pc = get_pos(carriage->pc + g_op_tab[9].label_size);
	if (carriage->carry == 1)
	{
		if (g_data.v4_flag)
			ft_printf("P%5d | %s %d OK\n", carriage->id, g_op_tab[9].op_name,
			arg);
		arg %= IDX_MOD;
		carriage->pc = carriage->pc_start;
		carriage->pc = get_pos(carriage->pc + arg);
	}
	else
	{
		if (g_data.v4_flag)
			ft_printf("P%5d | %s %d FAILED\n", carriage->id,
			g_op_tab[9].op_name, arg);
		(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
		carriage->pc = get_pos(carriage->pc + 1);
	}
}

void	op_ldi(t_carr *carriage)
{
	int32_t adr;
	t_arg	*args;

	args = g_op_tab[10].args;
	if (args[0].type == IND_CODE)
	{
		adr = get_pos(carriage->pc_start + (args[0].value % IDX_MOD));
		args[0].value = get_n_bytes(4, adr);
	}
	adr = carriage->pc_start + ((args[0].value + args[1].value) % IDX_MOD);
	carriage->reg[args[2].reg_num] = get_n_bytes(4, adr);
	if (g_data.v4_flag)
		ft_printf("P%5d | %s %d %d r%d\n       | -> load from %d + %d = %d"
		" (with pc and mod %d)\n", carriage->id, g_op_tab[10].op_name,
		args[0].value, args[1].value, args[2].reg_num + 1, args[0].value,
		args[1].value, args[0].value + args[1].value, adr);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}

void	op_sti(t_carr *carriage)
{
	int32_t adr;
	t_arg	*args;

	args = g_op_tab[11].args;
	if (args[1].type == IND_CODE)
	{
		args[0].value %= IDX_MOD;
		adr = get_pos(carriage->pc_start + (args[1].value % IDX_MOD));
		args[1].value = get_n_bytes(4, adr);
	}
	adr = carriage->pc_start + ((args[1].value + args[2].value) % IDX_MOD);
	if (g_data.v4_flag == 1)
		ft_printf("P%5d | %s r%d %d %d\n       | -> store to %d + %d = %d"
		" (with pc and mod %d)\n", carriage->id, g_op_tab[11].op_name,
		args[0].reg_num + 1, args[1].value, args[2].value, args[1].value,
		args[2].value, args[1].value + args[2].value, adr);
	write_n_bytes(args[0].value, 4, adr, carriage);
	(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
}
