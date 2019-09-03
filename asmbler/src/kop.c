/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:10:14 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/29 11:22:04 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static	void	length(char *fl, int roz, char **fl2, int q)
{
	char	*buf;

	if (q == 0)
	{
		if ((int)ft_strlen(fl) - 2 > roz)
		{
			ft_strdel(&fl);
			(roz == 2048) ? error_message("Error length > 2048", 0) : 0;
			error_message("Error length > 128", 0);
		}
	}
	if (q == 1)
	{
		buf = ft_strndup(*fl2, ft_strlen(*fl2) - 1);
		ft_strdel(fl2);
		*fl2 = ft_strdup(buf);
		ft_strdel(&buf);
	}
}

static int		kinec(char *fl, int fl3, char **fl2)
{
	if (fl[fl3 + rozm(fl + fl3, '"') - 1] == '"')
	{
		length(NULL, 0, fl2, 1);
		ft_strdel(&fl);
		return (1);
	}
	return (0);
}

void			kop_nc(char *fl, int c, int i)
{
	if (ft_strstr(fl, ".comment"))
	{
		while (fl[i] != '\0')
			i++;
		while (i != 0)
		{
			fl[i] == '"' ? c++ : 0;
			i--;
		}
		c != 2 ? error_message(fl, "not valid") : 0;
	}
	i = 0;
	c = 0;
	if (ft_strstr(fl, ".name"))
	{
		while (fl[i] != '\0')
			i++;
		while (i != 0)
		{
			fl[i] == '"' ? c++ : 0;
			i--;
		}
		c != 2 ? error_message(fl, "not valid") : 0;
	}
}

int				kop(char *fl, char **fl2, int len, int roz)
{
	int		fl3;

	fl3 = 0;
	if (len == 1)
		while (fl[fl3] && fl[fl3] != '"')
			fl3++;
	len == 1 ? fl3++ : 0;
	rozm(fl + fl3, '"') == 1 ? *fl2 = myfunc1(0, *fl2, fl, fl3) : 0;
	rozm(fl + fl3, '"') != 1 ? *fl2 = myfunc1(1, *fl2, fl, fl3) : 0;
	length(*fl2, roz, NULL, 0);
	if (kinec(fl, fl3, fl2) == 1)
		return (1);
	kop_nc(fl, 0, 0);
	ft_strdel(&fl);
	return (0);
}
