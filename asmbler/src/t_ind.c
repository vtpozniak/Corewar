/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:58:53 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 20:05:28 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static void		a_mark(char *line, int c, int i, t_var **var)
{
	if (i + 1 == g_operations[c].kol_a
			&& ft_strchr(line, COMMENT_CHAR))
		(*var)->name_mark =
			ft_strndup(line + 1, rozm(line + 1, COMMENT_CHAR) - 1);
	else
		(*var)->name_mark = ft_strdup(line + 1);
	name_mark((*var)->name_mark, NULL);
	(*var)->value = -1;
}

void			fttt(int c, char *line, int i, t_var *st)
{
	int		j;

	j = 0;
	line[0] == '-' ? j += 1 : 0;
	while (line[j] && ft_isdigit(line[j]))
		j++;
	i + 1 != g_operations[c].kol_a
	&& line[j] ? error_message("not valid symbol near 't_ind'", line) : 0;
	i + 1 == g_operations[c].kol_a ? chk_error(line + j) : 0;
	st->value = ft_atoi(line);
	st->name_mark = 0;
}

void			t_ind(char *line, int c, int i, t_func **b)
{
	t_var	*st;

	ft_mtrim(line, ';', COMMENT_CHAR);
	st = (t_var*)malloc(sizeof(t_var));
	line[0] == LABEL_CHAR ? a_mark(line, c, i, &st) : 0;
	line[0] != LABEL_CHAR ? fttt(c, line, i, st) : 0;
	st->rozm = IND_SIZE;
	st->bin = 3;
	tetr(&(*b)->varr, st);
}

t_func	g_operations[17] =
{
	{"live", 0, 1, 4, {T_DIR}, 0x01, 0, 0, 0, 0, 0},
	{"ld", 1, 2, 4, {T_DIR | T_IND, T_REG}, 0x02, 0, 0, 0, 0, 0},
	{"st", 1, 2, 4, {T_REG, T_REG | T_IND}, 0x03, 0, 0, 0, 0, 0},
	{"add", 1, 3, 4, {T_REG, T_REG, T_REG}, 0x04, 0, 0, 0, 0, 0},
	{"sub", 1, 3, 4, {T_REG, T_REG, T_REG}, 0x05, 0, 0, 0, 0, 0},
	{"and", 1, 3, 4, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		0x06, 0, 0, 0, 0, 0},
	{"or", 1, 3, 4,
		{T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		0x07, 0, 0, 0, 0, 0},
	{"xor", 1, 3, 4,
		{T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		0x08, 0, 0, 0, 0, 0},
	{"zjmp", 0, 1, 2, {T_DIR}, 0x09, 0, 0, 0, 0, 0},
	{"ldi", 1, 3, 2, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		0x0a, 0, 0, 0, 0, 0},
	{"sti", 1, 3, 2, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		0x0b, 0, 0, 0, 0, 0},
	{"fork", 0, 1, 2, {T_DIR}, 0x0c, 0, 0, 0, 0, 0},
	{"lld", 1, 2, 4, {T_DIR | T_IND, T_REG}, 0x0d, 0, 0, 0, 0, 0},
	{"lldi", 1, 3, 2, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		0x0e, 0, 0, 0, 0, 0},
	{"lfork", 0, 1, 2, {T_DIR}, 0x0f, 0, 0, 0, 0, 0},
	{"aff", 1, 1, 4, {T_REG}, 0x10, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, {0}, 0, 0, 0, 0, 0, 0}
};
