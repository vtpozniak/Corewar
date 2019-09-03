/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekc_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:41:43 by vpozniak          #+#    #+#             */
/*   Updated: 2019/09/03 18:56:45 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

void		ftreg(int i, int *vars)
{
	i == 7 ? vars[0] = -1 : 0;
	i == T_DIR ? vars[0] = T_DIR : 0;
	i == T_REG ? vars[0] = T_REG : 0;
	i == T_IND ? vars[0] = T_IND : 0;
	vars[2] = 0;
}

static void	available_args(int func, int iter, int *vars)
{
	int		i;

	i = g_operations[func].vars[iter];
	if (i == 3)
	{
		vars[0] = T_DIR;
		vars[1] = T_REG;
	}
	else if (i == 6)
	{
		vars[0] = T_DIR;
		vars[1] = T_IND;
	}
	else if (i == 5)
	{
		vars[0] = T_REG;
		vars[1] = T_IND;
	}
	ftreg(i, vars);
}

static int	check_valid_arg(char *line, int func, int iter)
{
	int		vars[4];
	int		var;
	int		i;

	var = -1;
	available_args(func, iter, vars);
	line[0] == DIRECT_CHAR ? var = T_DIR : 0;
	line[0] == 'r' ? var = T_REG : 0;
	ft_isdigit(line[0]) || (line[0] == '-' && ft_isdigit(line[1]))
			|| line[0] == LABEL_CHAR ? var = T_IND : 0;
	var == -1 ? error_message("Not var", line) : 0;
	i = -1;
	while (++i < 3 && vars[i])
		if (var == vars[i] || vars[0] == -1)
			break ;
	!vars[i] ? error_message("This com can't contain this var?", line) : 0;
	return (var);
}

static void	parse_arg_reg(char *line, int func, int iter, t_func **b)
{
	int		i;
	t_var	*a;

	i = 1;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	iter + 1 != g_operations[func].kol_a && line[i] != 0 ?
	error_message("not valid symbol near 'r'", line) : 0;
	iter + 1 == g_operations[func].kol_a ? chk_error(line + i) : 0;
	i > 3 ? error_message("Big value 'r'", line) : 0;
	a = (t_var*)malloc(sizeof(t_var));
	a->rozm = 1;
	i == 1 ? error_message("not valid symbol near 'r'", line) : 0;
	a->value = ft_atoi(line + 1);
	a->name_mark = 0;
	a->bin = 1;
	tetr(&(*b)->varr, a);
}

int			check_argument(char *line, t_func **b, int func)
{
	int		i;
	char	**args;
	int		valid;

	args = check_str(line, 0, 0, 0);
	(*b)->varr = 0;
	i = -1;
	while (args[++i])
	{
		ft_mtrim(args[i], ';', COMMENT_CHAR);
		if (args[i][0] == COMMENT_CHAR)
			break ;
		valid = check_valid_arg(args[i], func, i);
		if (valid == T_REG)
			parse_arg_reg(args[i], func, i, b);
		else if (valid == T_IND)
			t_ind(args[i], func, i, b);
		else
			t_dir(args[i], func, i, b);
	}
	free_matr(args);
	return (1);
}
