/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:08:58 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:08:58 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_hl(const char *pars, t_print *la, int i)
{
	if (pars[i] == 'l' && pars[i + 1] != 'l')
	{
		la->q.l = 1;
		return (i += 1);
	}
	if (pars[i] == 'h' && pars[i + 1] != 'h')
	{
		la->q.h = 1;
		return (i += 1);
	}
	if (pars[i] == 'l' && pars[i + 1] == 'l')
	{
		la->q.ll = 1;
		return (i += 2);
	}
	if (pars[i] == 'h' && pars[i + 1] == 'h')
	{
		la->q.hh = 1;
		return (i += 2);
	}
	return (ft_check_jzl(pars, la, i));
}

int		ft_check_jzl(const char *pars, t_print *la, int i)
{
	if (pars[i] == 'j')
	{
		la->q.j = 1;
		return (i += 1);
	}
	if (pars[i] == 'z')
	{
		la->q.z = 1;
		return (i += 1);
	}
	if (pars[i] == 'L')
	{
		la->q.lzl = 1;
		return (i += 1);
	}
	return (i);
}
