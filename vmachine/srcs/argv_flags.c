/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:46:41 by vpelivan          #+#    #+#             */
/*   Updated: 2019/07/31 20:46:45 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	check_dump(char **av)
{
	if (g_data.dump_flag == 1)
		error(ERR_ONE_DUMP);
	if (g_data.players_num || g_data.ncurses_flag || g_data.v0_flag
	|| g_data.v1_flag || g_data.v2_flag || g_data.v4_flag || g_data.v8_flag
	|| g_data.v16_flag)
		print_usage();
	if (ft_strcmp(av[1], "-dump"))
		print_usage();
	if (!av[2] || !ft_strisdigit(av[2]))
		error(ERR_DUMP_N_2);
	g_data.nbr_cycles = ft_atoi(av[2]);
	if (g_data.nbr_cycles < 0 || ft_str_int_overflow(av[2]))
		error(ERR_DUMP_N);
	g_data.dump_flag = 1;
	g_i += 2;
}

static void	check_player(char *str, int num)
{
	int			len;
	t_player	*new;

	len = ft_strlen(str);
	g_data.players_num++;
	if (g_data.players_num > MAX_PLAYERS)
	{
		ft_printf("{red}The number of player files exceeds %i{eoc}\n",
		MAX_PLAYERS);
		error(NULL);
	}
	if (ft_strcmp(&str[len - 4], ".cor"))
		error(ERR_EXT);
	new = new_player(num, str);
	add_player_end(new);
	g_i++;
}

static void	check_number(char **av)
{
	t_player	*tmp;
	int			num;

	num = 0;
	tmp = g_data.champs;
	(!av[g_i + 1]) ? error(ERR_N_NUM_3) : 0;
	(av[g_i + 1]) ? num = ft_atoi(av[g_i + 1]) : 0;
	num > MAX_PLAYERS ? error(ERR_N_NUM) : 0;
	(num <= 0 || !ft_strisdigit(av[g_i + 1])) ? error(ERR_N_NUM_2) : 0;
	while (tmp)
	{
		if (tmp->num == num)
		{
			ft_printf("{red}-n flag number \"%i\" is used more than once{eoc}"
			"\n", num);
			error(NULL);
		}
		tmp = tmp->next;
	}
	g_data.max_n_number < num ? g_data.max_n_number = num : 0;
	if (!av[g_i + 2])
		error(ERR_N_FILE);
	check_player(av[g_i + 2], num);
	g_i += 2;
}

static void	check_visualiser(char **av)
{
	if (g_data.ncurses_flag)
		error(ERR_ONE_V);
	if (g_data.players_num)
		print_usage();
	if (g_data.dump_flag == 1 && ft_strcmp(av[g_i], "-v"))
		print_usage();
	if (g_data.dump_flag == 0 && ft_strcmp(av[g_i], "-v"))
		print_usage();
	g_data.ncurses_flag = 1;
	if (av[g_i + 1] && !ft_strcmp(av[g_i + 1], "--stealth"))
	{
		g_data.ncur_stealth = 1;
		g_i++;
	}
	g_i++;
}

void		validate_args(char **av)
{
	g_i = 1;
	while (av[g_i])
	{
		if (!ft_strcmp(av[g_i], "-dump"))
			check_dump(av);
		else if (!ft_strcmp(av[g_i], "-l"))
			check_verbosity(av);
		else if (!ft_strcmp(av[g_i], "-v"))
			check_visualiser(av);
		else if (!ft_strcmp(av[g_i], "-n"))
			check_number(av);
		else if (ft_strstr(av[g_i], ".cor"))
			check_player(av[g_i], 0);
		else
			print_usage();
	}
	g_data.players_num == 0 ? error(ERR_PL_FILES) : 0;
	if (g_data.players_num < g_data.max_n_number)
	{
		ft_printf("{red}The number after -n \"%i\" can't be more than total"
		" players number{eoc}\n", g_data.max_n_number);
		error(NULL);
	}
	set_flags();
}
