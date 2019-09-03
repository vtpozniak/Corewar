/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:09:07 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:09:09 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pars_u_x(const char *pars, t_print *la, int i)
{
	pars[i] == 'u' ? la->q.base = 10 : 0;
	pars[i] == 'o' ? la->q.base = 8 : 0;
	pars[i] == 'x' || pars[i] == 'X' ? la->q.base = 16 : 0;
	pars[i] == 'p' ? la->q.base = 16 : 0;
}

int		ft_type(const char *pars, t_print *la, va_list *list, int i)
{
	pars_u_x(pars, la, i);
	if (pars[i] == 'c')
		pro_c(la, *list);
	if (pars[i] == 's')
		pro_s(la, *list);
	if (pars[i] == 'd' || pars[i] == 'i')
		pro_d_i(la, *list);
	if (pars[i] == 'o' || pars[i] == 'u' || pars[i] == 'x' || pars[i] == 'X')
	{
		pars[i] == 'X' ? la->q.xl++ : 0;
		pars[i] == 'o' ? la->q.o++ : 0;
		pars[i] == 'x' ? la->q.x++ : 0;
		la->q.flag++;
		pro_o_u_x(la, *list);
	}
	if (pars[i] == '%')
		pro_prots(la);
	if (pars[i] == 'p')
		pro_p(la, *list);
	if (pars[i] == 'f' || pars[i] == 'F')
	{
		la->q.f++;
		pro_f(la, *list);
	}
	return (++i);
}

int		ft_toch_wp(const char *pars, t_print *la, int i, va_list *list)
{
	if (pars[i] == '*')
	{
		la->q.width = va_arg(*list, intmax_t);
		i++;
	}
	if (ft_isdigit(pars[i]))
		la->q.width = ft_atoi(&pars[i]);
	while (ft_isdigit(pars[i]))
		i++;
	if (pars[i] == '.')
	{
		la->q.t++;
		la->q.p = ft_atoi(&pars[++i]);
	}
	else
		la->q.p = -1;
	while (ft_isdigit(pars[i]))
		i++;
	return (ft_check_hl(pars, la, i));
}

int		ft_flags(const char *pars, t_print *la, int c)
{
	int		i;

	i = c;
	while (pars[++i] == ' ' || pars[i] == '#' ||
	pars[i] == '-' || pars[i] == '+' || pars[i] == '0')
	{
		pars[i] == '#' ? la->q.hesh = 1 : 0;
		pars[i] == '0' ? la->q.zero = 1 : 0;
		pars[i] == '-' ? la->q.min = 1 : 0;
		pars[i] == '+' ? la->q.plus = 1 : 0;
		pars[i] == ' ' ? la->q.space = 1 : 0;
	}
	la->q.plus == 1 ? la->q.space = 0 : 0;
	la->q.min == 1 ? la->q.zero = 0 : 0;
	return (i);
}

int		parsing(const char *pars, t_print *la, va_list *list, int c)
{
	int i;

	i = ft_flags(pars, la, c);
	i = ft_toch_wp(pars, la, i, list);
	return (ft_type(pars, la, list, i));
}
