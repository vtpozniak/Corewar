/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 21:29:20 by vpelivan          #+#    #+#             */
/*   Updated: 2019/08/31 21:29:22 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static t_carr	*new_element(int num, uint32_t poz)
{
	t_carr *new;

	new = (t_carr *)ft_memalloc(sizeof(t_carr));
	new->pl_num = num;
	new->id = ++g_i;
	new->pc = get_pos(poz);
	new->pc_start = new->pc;
	new->reg[0] = -num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			new_carriage(int num, uint32_t poz)
{
	t_carr *new;

	new = new_element(num, poz);
	if (!g_data.carrs)
	{
		g_data.carrs = new;
		g_data.carrs_num++;
		return ;
	}
	g_data.carrs->prev = new;
	new->next = g_data.carrs;
	g_data.carrs = new;
	g_data.carrs_num++;
}

void			delete_carriage(t_carr *elm)
{
	t_carr *to_free;

	to_free = elm;
	if (g_data.v8_flag)
		ft_printf("Process %d hasn't lived for %d cycles"
		"(CTD %d)\n", elm->id, g_data.total_cycles -
		elm->last_live_cycle, g_data.cycles_to_die);
	if (elm->prev && elm->next)
	{
		elm->prev->next = elm->next;
		elm->next->prev = elm->prev;
	}
	else if (!elm->prev && elm->next)
	{
		elm->next->prev = NULL;
		g_data.carrs = elm->next;
	}
	else if (elm->prev && !elm->next)
		elm->prev->next = NULL;
	else if (!elm->prev && !elm->next)
		g_data.carrs = NULL;
	free(to_free);
	g_data.carrs_num--;
}
