/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:07:42 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/29 11:00:33 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

void	end_com(t_bot **st, t_func *func)
{
	t_func	*nuch;

	if (!(*st)->func)
	{
		func->next = (*st)->func;
		(*st)->func = func;
	}
	else
	{
		nuch = (*st)->func;
		while (nuch->next)
			nuch = nuch->next;
		nuch->next = func;
		func->next = 0;
	}
}

void	rozm_comm(t_func *func, t_var *vars, t_flag *flag)
{
	flag->sz = 1;
	func->kode ? flag->sz++ : 0;
	vars = func->varr;
	while (vars)
	{
		flag->sz += vars->rozm;
		vars = vars->next;
	}
}

int		nuchcoutn(t_func *nuch, int count)
{
	while (nuch)
	{
		nuch = nuch->next;
		count++;
	}
	return (count);
}

int		rtmas(t_var *var, int i)
{
	while (var)
	{
		i = i + var->rozm;
		var = var->next;
	}
	return (i);
}

char	*myfunc1(int q, char *fl2, char *fl, int fl3)
{
	char	*buf;

	q == 0 ? fl2 = new_free(fl2, "", 0) : 0;
	if (q == 1)
	{
		buf = ft_strndup(fl + fl3, rozm(fl + fl3, '"') - 1);
		fl2 = new_free(fl2, buf, 1);
	}
	return (fl2);
}
