/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:47:40 by vpelivan          #+#    #+#             */
/*   Updated: 2019/07/31 20:47:42 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int		get_fd(char *filename)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf("{red}Unable to open \"%s\"{eoc}\n", filename);
		error(NULL);
	}
	return (fd);
}

t_player		*new_player(int num, char *file_name)
{
	t_player *tmp;

	if (!(tmp = (t_player *)ft_memalloc(sizeof(t_player))))
		return (NULL);
	if (!(tmp->data = (t_header *)ft_memalloc(sizeof(t_header))))
		return (NULL);
	if (num)
		tmp->num = num;
	else
		tmp->num = 0;
	tmp->fd = get_fd(file_name);
	tmp->file_name = ft_strdup(file_name);
	tmp->data->magic = 0;
	tmp->data->prog_size = 0;
	ft_bzero(tmp->data->comment, COMMENT_LENGTH + 1);
	ft_bzero(tmp->data->prog_name, PROG_NAME_LENGTH + 1);
	tmp->code = NULL;
	tmp->next = NULL;
	return (tmp);
}

void			add_player_end(t_player *champ)
{
	t_player *tmp;

	tmp = g_data.champs;
	if (!champ)
		return ;
	if (!tmp)
	{
		tmp = champ;
		g_data.champs = tmp;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = champ;
	}
}

static t_player	*swap_players(t_player *champ, t_player *swap)
{
	t_player *to_free;

	champ->fd = champ->next->fd;
	free(champ->file_name);
	champ->file_name = ft_strdup(champ->next->file_name);
	champ->num = champ->next->num;
	champ->data->magic = champ->next->data->magic;
	ft_bzero(champ->data->prog_name, PROG_NAME_LENGTH + 1);
	ft_strcpy(champ->data->prog_name, champ->next->data->prog_name);
	ft_bzero(champ->data->comment, COMMENT_LENGTH + 1);
	ft_strcpy(champ->data->comment, champ->next->data->comment);
	ft_bzero(champ->code, champ->data->prog_size + 1);
	ft_memcpy(champ->code, champ->next->code,
	champ->next->data->prog_size + 1);
	champ->data->prog_size = champ->next->data->prog_size;
	to_free = champ->next;
	champ->next = swap;
	champ = g_data.champs;
	free(to_free->data);
	free(to_free->file_name);
	free(to_free->code);
	free(to_free);
	return (champ);
}

void			sort_players(void)
{
	t_player *champ;
	t_player *swap;

	champ = g_data.champs;
	while (champ->next)
	{
		if (champ->num > champ->next->num)
		{
			swap = new_player(champ->num, champ->file_name);
			swap->fd = champ->fd;
			swap->data->magic = champ->data->magic;
			ft_strcpy(swap->data->prog_name, champ->data->prog_name);
			ft_strcpy(swap->data->comment, champ->data->comment);
			swap->code = (unsigned char *)ft_memalloc(sizeof(unsigned char) *
			champ->data->prog_size);
			ft_memcpy(swap->code, champ->code, champ->data->prog_size + 1);
			swap->data->prog_size = champ->data->prog_size;
			swap->next = champ->next->next;
			champ = swap_players(champ, swap);
		}
		else
			champ = champ->next;
	}
}
