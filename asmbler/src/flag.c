/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:46:58 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/29 11:21:53 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static void	print_flag_l(t_var *arg, t_func *funcs, int byte, t_flag *flag)
{
	t_func	*start;
	t_mark	*label;
	int		i;

	i = flag->flag;
	start = funcs;
	while (start)
	{
		label = start->marks;
		while (label)
		{
			if (!ft_strcmp(label->name, arg->name_mark))
				ft_printf("{%d %d} ", byte, start->number_bt);
			if (flag->flag > i)
				break ;
			label = label->next;
		}
		if (flag->flag > i)
			break ;
		start = start->next;
	}
}

t_var		*print_flag_vr(t_func *func, t_flag *flag, t_var *vars, t_bot *a)
{
	vars->bin == 1 ? ft_printf("|%s%d", "r", vars->value) : 0;
	if (vars->bin == 2)
	{
		if (vars->name_mark)
			ft_printf("%%:%s ", vars->name_mark);
		else
			ft_printf("|%%%d", vars->value);
	}
	if (vars->bin == 3)
	{
		if (vars->name_mark)
			ft_printf(":%s |", vars->name_mark);
		else
			ft_printf("%d ", vars->value);
	}
	if (vars->name_mark)
	{
		ft_printf("");
		print_flag_l(vars, a->func, func->number_bt, flag);
	}
	else
		ft_printf(" %d| ", vars->value);
	vars = vars->next;
	return (vars);
}

static void	print_flag_v(t_func *func, t_bot *a, t_flag *flag)
{
	t_var	*vars;

	vars = func->varr;
	flag->flag = ft_printf("->%d ", func->dir);
	if (func->kode)
		ft_printf("%d ", func->kode);
	else
		ft_printf("");
	while (vars)
		vars = print_flag_vr(func, flag, vars, a);
}

static void	print_flag_c(t_func *func, t_flag *flag)
{
	t_mark	*labels;

	labels = func->marks;
	if (labels)
		while (labels)
		{
			ft_printf("%s ", labels->name);
			ft_printf("\n");
			labels = labels->next;
		}
	rozm_comm(func, NULL, flag);
	ft_printf("%d (%d) ", func->number_bt, flag->sz);
	ft_printf("%s", func->name);
}

void		flag_a(t_bot *a)
{
	t_func *start;
	t_flag flag;

	flag.flag = 0;
	flag.sz = 0;
	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", size_code(a));
	ft_printf("Name : %s\"\n", a->name);
	ft_printf("Comment : %s\"\n\n", a->comment);
	ft_printf("<----------------------------------------------------->\n");
	start = a->func;
	while (start)
	{
		print_flag_c(start, &flag);
		print_flag_v(start, a, &flag);
		start = start->next;
		ft_printf("\n");
		ft_printf("<----------------------------------------------------->\n");
	}
}
