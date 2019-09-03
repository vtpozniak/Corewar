/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:20:48 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 17:42:01 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_tab_u(const char *str, int size, uintmax_t value, int base)
{
	char		*tab;
	uintmax_t	tmp;

	tmp = value;
	while (tmp /= base)
		size++;
	size++;
	if (!(tab = (char *)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	tab[size] = '\0';
	while (size > 0)
	{
		tab[size - 1] = str[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (tab);
}

static char		*ft_tab(const char *str, int size, intmax_t value, int base)
{
	char		*tab;
	intmax_t	tmp;

	tmp = value;
	while (tmp /= base)
		size++;
	size++;
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	while (size > 0)
	{
		tab[size - 1] = str[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (tab);
}

char			*ft_itoa_base_p(t_lst *l, intmax_t v1, uintmax_t v2, int base)
{
	char	*str;
	char	*tab;
	int		size;

	size = 0;
	str = "0123456789";
	(l->type == 'x' || l->type == 'p') ? (str = "0123456789abcdef") : 0;
	(l->type == 'o') ? (str = "01234567") : 0;
	(l->type == 'X') ? (str = "0123456789ABCDEF") : 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (l->type == 'x' || l->type == 'X' || l->type == 'u' || l->type == 'o'
	|| l->type == 'p' || l->type == 'f' || l->type == 'F')
		tab = ft_tab_u(str, size, v2, base);
	else
		tab = ft_tab(str, size, v1, base);
	if (!tab)
		return (NULL);
	return (tab);
}
