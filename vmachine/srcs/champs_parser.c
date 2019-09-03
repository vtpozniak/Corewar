/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:46:58 by vpelivan          #+#    #+#             */
/*   Updated: 2019/07/31 20:47:01 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static uint32_t	get_int(int fd, t_player *champ)
{
	uint8_t		buff[4];
	uint32_t	res;
	int			len;

	len = read(fd, &buff, 4);
	if (len < 4)
	{
		ft_printf("{red}%s \"%s\"{eoc}\n", ERR_READ, champ->file_name);
		error(NULL);
	}
	res = (unsigned char)buff[0] << 24;
	res |= (unsigned char)buff[1] << 16;
	res |= (unsigned char)buff[2] << 8;
	res |= (unsigned char)buff[3];
	return (res);
}

static void		get_char(int fd, int size, t_player *champ, short flag)
{
	int		read_size;
	char	*buf;

	buf = (char*)ft_memalloc(sizeof(char) * size + 1);
	read_size = read(fd, buf, size);
	if (read_size == -1)
	{
		ft_printf("{red}%s \"%s\"{eoc}\n", ERR_READ, champ->file_name);
		error(NULL);
	}
	if ((flag == 1 || flag == 2) && read_size < size)
		error(ERR_READ_SIZE);
	if (flag == 3 && ((read(fd, buf, 1) > 0) || read_size < size))
	{
		ft_printf("{red}Size of code in \"%s\" is not the same as specified in"
		" this file{eoc}\n", champ->file_name);
		error(NULL);
	}
	flag == 1 ? ft_strcpy(champ->data->prog_name, buf) : 0;
	flag == 2 ? ft_strcpy(champ->data->comment, buf) : 0;
	flag == 3 ? ft_memcpy(champ->code, buf, champ->data->prog_size) : 0;
	free(buf);
}

static void		get_champ_num(t_player *champ)
{
	t_player	*tmp;
	int			i;

	i = 1;
	tmp = g_data.champs;
	while (tmp)
	{
		if (i == tmp->num)
			i++;
		tmp = tmp->next;
	}
	champ->num = i;
}

void			parse_champs(void)
{
	t_player	*champ;

	champ = g_data.champs;
	while (champ)
	{
		(!champ->num) ? get_champ_num(champ) : 0;
		champ->data->magic = get_int(champ->fd, champ);
		champ->data->magic != COREWAR_EXEC_MAGIC ? error(ERR_MAGIC) : 0;
		get_char(champ->fd, PROG_NAME_LENGTH, champ, 1);
		(get_int(champ->fd, champ) != 0) ? error(ERR_NULL_NAME) : 0;
		champ->data->prog_size = get_int(champ->fd, champ);
		(champ->data->prog_size > CHAMP_MAX_SIZE) ? error(ERR_PROG_SIZE) : 0;
		get_char(champ->fd, COMMENT_LENGTH, champ, 2);
		(get_int(champ->fd, champ) != 0) ? error(ERR_NULL_COMM) : 0;
		champ->code = (unsigned char *)ft_memalloc(sizeof(unsigned char) *
		champ->data->prog_size);
		get_char(champ->fd, champ->data->prog_size, champ, 3);
		champ = champ->next;
	}
}
