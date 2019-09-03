/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:09:40 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:09:41 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*iter(t_print *la)
{
	char			*str1;
	char			*str2;

	str2 = NULL;
	if (la->q.lens > 0)
		str1 = ft_strjoin(la->who, ".");
	else
		str1 = ft_strjoin(la->who, "");
	str2 = ft_strjoin(str1, la->str);
	if (str1)
		free(str1);
	return (str2);
}

static char		*ft_strdrob(t_print *la, long double drob)
{
	char			*str;
	int				i;

	drob < 0 ? drob *= -1 : 0;
	i = 0;
	la->q.p < 0 ? la->q.p = 6 : 0;
	str = (char*)ft_memalloc(sizeof(char) * (la->q.p + 1));
	while (la->q.p + 1 > i)
	{
		str[i] = drob * 10 + '0';
		drob = drob * 10;
		drob -= (intmax_t)drob;
		i++;
	}
	return (str);
}

static char		*tochn(intmax_t *whole, t_print *la, int i, long double drob)
{
	la->q.p ? i = la->q.p : 0;
	tochnf(whole, la, i, drob);
	if (la->q.p == 1 && la->str[0] == '2' && la->str[1] == '5' && drob == 0.25)
	{
		la->str[la->q.p] = '\0';
		return (la->str);
	}
	if (i >= 0 && la->str[i] >= '5')
	{
		if (la->str[i] == '9')
		{
			while (la->str[i] == '9')
			{
				(i == 0 && la->str[i] == '9') ? *whole = *whole + 1 : 0;
				la->str[i--] = '0';
			}
			la->str[i] += 1;
		}
		else
			la->str[i - 1] += 1;
	}
	la->str[la->q.p] = '\0';
	return (la->str);
}

void			pro_f(t_print *la, va_list list)
{
	long double		src;
	long double		drob;
	intmax_t		whole;
	int				i;

	i = 0;
	src = check_type_3(la, list);
	if (la->q.lzl > 0)
		whole = (uintmax_t)src;
	else
		whole = (intmax_t)src;
	src < 0 ? la->q.dr++ : 0;
	if (src == 0)
		minzero(src) == 1 && whole == 0 ? check_bf(la, '-') : 0;
	drob = src - whole;
	la->q.p <= 0 && la->q.t ? la->q.p = 0 : 0;
	la->str = ft_strdrob(la, drob);
	tochn(&whole, la, i, drob);
	ft_flo(src, la, whole);
	prof_f(la, la->tmp, drob);
	free(la->tmp);
	free(la->who);
	free(la->str);
	ft_bzero(&(la->q), sizeof(t_flags_list));
}
