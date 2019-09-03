/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:47:27 by vpelivan          #+#    #+#             */
/*   Updated: 2019/07/31 20:47:28 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		dump_arena(void)
{
	int i;
	int j;

	i = 0;
	ft_printf("0x");
	while (i < MEM_SIZE)
	{
		j = 0;
		ft_printf("%#.4x : ", i);
		while (j < 63)
		{
			ft_printf("%.2x ", g_data.arena[i].c);
			i++;
			j++;
		}
		ft_printf("%.2x\n", g_data.arena[i].c);
		i++;
	}
	exit(0);
}

static void	copy_code(t_player *champ, uint32_t poz)
{
	unsigned int i;

	i = 0;
	while (i < champ->data->prog_size)
	{
		g_data.arena[poz + i].c = champ->code[i];
		g_data.arena[poz + i].player = champ->num;
		i++;
	}
}

void		create_arena(void)
{
	t_player	*champ;
	uint32_t	champ_offset;
	uint32_t	poz;

	champ_offset = MEM_SIZE / g_data.players_num;
	champ = g_data.champs;
	if (!(g_data.arena = (t_arena*)ft_memalloc(sizeof(t_arena)
	* MEM_SIZE)))
		return ;
	g_i = 0;
	while (champ)
	{
		poz = (champ_offset * champ->num) - champ_offset;
		copy_code(champ, poz);
		new_carriage(champ->num, poz);
		set_op_code(g_data.carrs);
		champ = champ->next;
	}
}

void		intro(void)
{
	t_player	*champ;

	champ = g_data.champs;
	if (!g_data.ncurses_flag)
	{
		ft_printf("Introducing contestants...\n");
		while (champ)
		{
			ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
			champ->num, champ->data->prog_size, champ->data->prog_name,
			champ->data->comment);
			champ = champ->next;
		}
	}
}

void		game_over(void)
{
	t_player *winner;

	winner = g_data.champs;
	if (!g_data.ncurses_flag)
	{
		while (winner->next && winner->num != g_data.last_live_player)
			winner = winner->next;
		ft_printf("Player %i (%s) won\n", winner->num,
		winner->data->prog_name);
	}
	exit(0);
}
