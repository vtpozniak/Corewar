/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 21:31:37 by vpelivan          #+#    #+#             */
/*   Updated: 2019/08/31 21:31:39 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int32_t	get_n_bytes(uint32_t size, int pos)
{
	uint8_t		bytes[4];
	int32_t		num;
	uint32_t	i;

	i = -1;
	num = 0;
	while (++i < size)
		bytes[i] = g_data.arena[get_pos(pos + i)].c;
	if (size == 1)
		return ((unsigned char)bytes[0]);
	else if (size == 2)
	{
		num |= (unsigned char)bytes[0] << 8;
		num |= (unsigned char)bytes[1];
		return ((short)num);
	}
	else if (size == 4)
	{
		num = (unsigned char)bytes[0] << 24;
		num |= (unsigned char)bytes[1] << 16;
		num |= (unsigned char)bytes[2] << 8;
		num |= (unsigned char)bytes[3];
		return ((int32_t)num);
	}
	return (0);
}

void	write_n_bytes(int32_t value, uint32_t size, int pos, t_carr *carriage)
{
	uint32_t	i;
	int			write_pos;
	uint8_t		bytes[size];
	int			bit_move;

	i = -1;
	bit_move = (size * 8) - 8;
	ft_bzero(bytes, size);
	while (++i < size)
	{
		bytes[i] = value >> bit_move;
		write_pos = get_pos(pos + i);
		g_data.arena[write_pos].c = bytes[i];
		g_data.arena[write_pos].player = carriage->pl_num;
		bit_move -= 8;
		g_data.arena[write_pos].turns = 50;
	}
}

int		get_pos(int pos)
{
	if (pos >= 0 && pos < MEM_SIZE)
		return (pos);
	else if (pos >= MEM_SIZE)
		return (pos % MEM_SIZE);
	else if (pos < 0)
	{
		if (ft_abs(pos) < MEM_SIZE)
			return (pos + MEM_SIZE);
		else if (ft_abs(pos) == MEM_SIZE)
			return (0);
		else
			return (pos % MEM_SIZE);
	}
	else
		return (pos);
}

void	print_movement(t_carr *carriage)
{
	int len;
	int byte;
	int i;

	i = -1;
	byte = carriage->pc_start;
	len = carriage->pc > carriage->pc_start ? carriage->pc : carriage->pc
	+ MEM_SIZE;
	len = (len - carriage->pc_start) % MEM_SIZE + 1;
	ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", len, carriage->pc_start,
	carriage->pc_start + len);
	while (++i < len)
	{
		ft_printf("%.2x ", g_data.arena[byte].c);
		byte = get_pos(byte + 1);
	}
	ft_printf("\n");
}

void	perform_codage_op(t_carr *carriage)
{
	(carriage->op_code == 2) ? op_ld(carriage) : 0;
	(carriage->op_code == 3) ? op_st(carriage) : 0;
	(carriage->op_code == 4) ? op_add(carriage) : 0;
	(carriage->op_code == 5) ? op_sub(carriage) : 0;
	(carriage->op_code == 6) ? op_and(carriage) : 0;
	(carriage->op_code == 7) ? op_or(carriage) : 0;
	(carriage->op_code == 8) ? op_xor(carriage) : 0;
	(carriage->op_code == 10) ? op_ldi(carriage) : 0;
	(carriage->op_code == 11) ? op_sti(carriage) : 0;
	(carriage->op_code == 13) ? op_lld(carriage) : 0;
	(carriage->op_code == 14) ? op_lldi(carriage) : 0;
	(carriage->op_code == 16) ? op_aff(carriage) : 0;
}
