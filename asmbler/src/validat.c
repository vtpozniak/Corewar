/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:56:21 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 20:06:17 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static void		kl_bt(t_bot **st, t_func *nuch, t_var *var, int i)
{
	nuch = (*st)->func;
	while (nuch)
	{
		nuch->number_bt = i;
		var = nuch->varr;
		i = rtmas(var, i);
		i = i + nuch->kode + 1;
		nuch = nuch->next;
	}
}

static int		poshuk_l(t_bot *st, char *name, int num, int i)
{
	t_func		*nuch;
	t_mark		*mark;

	nuch = st->func;
	while (nuch && i == -1)
	{
		mark = nuch->marks;
		while (mark && i == -1)
		{
			!ft_strcmp(mark->name, name) ? i = nuch->number_bt : 0;
			mark = mark->next;
		}
		nuch = nuch->next;
	}
	i == -1 ? ft_putstr(name) : 0;
	i == -1 ? error_message(" exist", 0) : 0;
	num > i ? i = -(num - i) : 0;
	num <= i ? i -= num : 0;
	return (i);
}

static void		p_kod(t_func **c, t_var *vars, int kode, int i)
{
	int			s;

	s = 2;
	vars = (*c)->varr;
	while (++i < 3)
	{
		if (vars)
		{
			kode += vars->bin;
			vars = vars->next;
		}
		kode <<= s;
	}
	(*c)->kode = kode;
}

static void		com_chack(t_func *a, t_func *nuch, int count)
{
	nuch = a;
	count = nuchcoutn(nuch, 0);
	!count ? error_message("No commands", 0) : 0;
}

void			validat(int fd, t_bot **st, char *n)
{
	t_func		*nuch;
	t_var		*var;

	check_val(fd, st, NULL, n);
	com_chack((*st)->func, NULL, 0);
	kl_bt(st, NULL, NULL, 0);
	nuch = (*st)->func;
	while (nuch)
	{
		var = nuch->varr;
		nuch->kode ? p_kod(&nuch, NULL, 0, -1) : 0;
		while (var)
		{
			(int)var->value == -1 && var->name_mark ? var->value =
					poshuk_l(*st, var->name_mark, nuch->number_bt, -1) : 0;
			var = var->next;
		}
		nuch = nuch->next;
	}
}
