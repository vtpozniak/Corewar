/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbosity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:52:05 by vpelivan          #+#    #+#             */
/*   Updated: 2019/09/01 15:52:06 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		set_flags(void)
{
	if (g_data.ncurses_flag)
	{
		g_data.dump_flag = 0;
		g_data.v0_flag = 0;
		g_data.v1_flag = 0;
		g_data.v2_flag = 0;
		g_data.v4_flag = 0;
		g_data.v8_flag = 0;
		g_data.v16_flag = 0;
	}
	else if (g_data.dump_flag && !g_data.ncurses_flag)
	{
		g_data.v0_flag = 0;
		g_data.v1_flag = 0;
		g_data.v2_flag = 0;
		g_data.v4_flag = 0;
		g_data.v8_flag = 0;
		g_data.v16_flag = 0;
	}
}

static void	parse_v_number(char *av)
{
	int i;

	i = ft_atoi(av);
	if (i == 0)
		g_data.v0_flag = 1;
	if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13
		|| i == 15 || i == 17 || i == 19 || i == 21 || i == 23 || i == 25
		|| i == 27 || i == 29 || i == 30 || i == 31)
		g_data.v1_flag = 1;
	if (i == 2 || i == 3 || i == 6 || i == 7 || i == 10 || i == 11
		|| i == 14 || i == 15 || i == 18 || i == 19 || i == 22 || i == 23
		|| i == 26 || i == 27 || i == 30 || i == 31)
		g_data.v2_flag = 1;
	if (i == 4 || i == 5 || i == 6 || i == 7 || i == 12 || i == 13 || i == 14
		|| i == 15 || i == 20 || i == 21 || i == 22 || i == 23 || i == 28
		|| i == 29 || i == 30 || i == 31)
		g_data.v4_flag = 1;
	if (i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13
		|| i == 14 || i == 15 || i == 24 || i == 25 || i == 26 || i == 27
		|| i == 28 || i == 29 || i == 30 || i == 31)
		g_data.v8_flag = 1;
	if (i >= 16 && i <= 31)
		g_data.v16_flag = 1;
	if (i > 31)
		error(ERR_L_N);
}

static void	check_v_number(char *av)
{
	int i;

	i = -1;
	(!av) ? error(ERR_L_N) : 0;
	while (av[++i])
		(!ft_isdigit(av[i])) ? error(ERR_L_N) : 0;
	parse_v_number(av);
}

void		check_verbosity(char **av)
{
	if (g_data.v0_flag == 1 || g_data.v1_flag == 1 || g_data.v2_flag == 1
	|| g_data.v4_flag == 1 || g_data.v8_flag == 1 || g_data.v16_flag == 1)
		error(ERR_ONE_L);
	if (g_data.players_num || g_data.ncurses_flag)
		print_usage();
	if ((((g_data.ncurses_flag && !g_data.dump_flag)
	|| (!g_data.ncurses_flag && g_data.dump_flag)) && g_i > 3)
	|| (g_data.ncurses_flag && g_data.dump_flag && g_i > 4)
	|| (!g_data.ncurses_flag && !g_data.dump_flag && g_i > 1))
		print_usage();
	check_v_number(av[g_i + 1]);
	g_i += 2;
}
