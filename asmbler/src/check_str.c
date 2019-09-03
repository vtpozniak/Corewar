/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:06:39 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/29 11:21:32 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cor.h"

static	int	sp(char const *s, int dl, int i)
{
	while (s[i] == ',' || s[i] == '\t' || s[i] == ' ')
		i++;
	while ((s[i] != ',' && s[i] != '\t' && s[i] != ' ') && s[i])
	{
		dl++;
		i++;
	}
	return (dl);
}

static int	st(char const *s, int i, int count)
{
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != ',')
		{
			while (s[i] != ' ' && s[i] != '\t' && s[i] != ',' && s[i])
				i++;
			count++;
		}
		while ((s[i] == '\t' || s[i] == ' ' || s[i] == ',') && s[i])
			i++;
	}
	return (count);
}

char		**check_str(char *fl, int i, int j, int k)
{
	char	**mas;

	if (!fl || !(mas = (char **)malloc(sizeof(*mas) * st(fl, 0, 0) + 1)))
		return (NULL);
	while (i < st(fl, 0, 0))
	{
		k = 0;
		if (!(mas[i] = ft_strnew(sp(&fl[j], 0, 0))))
			return (NULL);
		while (fl[j] == '\t' || fl[j] == ' ' || fl[j] == ',')
			j++;
		while (fl[j] != '\t' && fl[j] != ' ' && fl[j] != ',' && fl[j])
			mas[i][k++] = fl[j++];
		mas[i][k] = '\0';
		i++;
	}
	mas[i] = 0;
	j = 0;
	return (mas);
}
