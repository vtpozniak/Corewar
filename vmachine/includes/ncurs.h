/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:49:03 by vdanyliu          #+#    #+#             */
/*   Updated: 2019/08/27 17:59:54 by vdanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURS_H
# define NCURS_H
# include "corewar.h"

int				g_timeout;

int				nc_main(void);
void			nc_fill_menu(t_ncurses *ncurs);
void			nc_parcer(char c);
void			eternity_test(void);
void			nc_clean_menu(void);
void			nc_end_game(t_ncurses *ncurs, int *x, int *y);
void			nc_fill_arena(t_ncurses *ncurs);
void			turn_color(t_ncurses *ncurs, int i, int mod, int window);

#endif
