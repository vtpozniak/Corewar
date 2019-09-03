/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_arguments_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 21:10:16 by vpelivan          #+#    #+#             */
/*   Updated: 2019/08/09 21:10:17 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		get_register(t_carr *carriage, t_arg *args)
{
	int32_t num;

	args->size = 1;
	carriage->pc = get_pos(carriage->pc + 1);
	num = get_n_bytes(args->size, carriage->pc);
	if (num >= 1 && num <= 16)
	{
		args->value = carriage->reg[num - 1];
		args->reg_num = num - 1;
	}
	else
		carriage->error = 1;
}

static void		set_arg_type(t_carr *carriage)
{
	int		i;
	t_arg	*args;

	i = -1;
	carriage->error = 0;
	args = g_op_tab[carriage->op_code].args;
	while (++i < g_op_tab[carriage->op_code].args_num)
	{
		if (args[i].type == DIR_CODE)
		{
			args[i].size = g_op_tab[carriage->op_code].label_size;
			args[i].value = get_n_bytes(args[i].size,
			get_pos(carriage->pc + 1));
			carriage->pc = get_pos(carriage->pc + args[i].size);
		}
		else if (args[i].type == IND_CODE)
		{
			args[i].size = IND_SIZE;
			args[i].value = get_n_bytes(args[i].size,
			get_pos(carriage->pc + 1));
			carriage->pc = get_pos(carriage->pc + args[i].size);
		}
		else if (args[i].type == REG_CODE)
			get_register(carriage, &args[i]);
	}
}

static void		codage_perform(t_carr *carriage, int op_code)
{
	int32_t		code;

	carriage->pc = get_pos(carriage->pc + 1);
	code = (unsigned char)g_data.arena[carriage->pc].c;
	carriage->codage = code;
	g_op_tab[op_code].args[0].type = code >> 6 & 0x03;
	g_op_tab[op_code].args[1].type = code >> 4 & 0x03;
	g_op_tab[op_code].args[2].type = code >> 2 & 0x03;
	set_arg_type(carriage);
	if (check_codage(carriage) == 1 && !carriage->error)
		perform_codage_op(carriage);
	else if (!check_codage(carriage) || carriage->error)
		(g_data.v16_flag == 1) ? print_movement(carriage) : 0;
	carriage->pc = get_pos(carriage->pc + 1);
}

void			parse_op_arg(t_carr *carriage)
{
	int			op_code;

	op_code = carriage->op_code;
	if (op_code > 0 && op_code < 17)
	{
		carriage->pc_start = carriage->pc;
		if (g_op_tab[op_code].codage_flag == 0)
		{
			(carriage->op_code == 1) ? op_live(carriage) : 0;
			(carriage->op_code == 9) ? op_zjmp(carriage) : 0;
			(carriage->op_code == 12) ? op_fork(carriage) : 0;
			(carriage->op_code == 15) ? op_lfork(carriage) : 0;
		}
		else
			codage_perform(carriage, op_code);
		carriage->op_code = 0;
	}
	else if (carriage->op_code < 1 || carriage->op_code > 16)
		carriage->pc = get_pos(carriage->pc + 1);
}
