/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:54:53 by vpelivan          #+#    #+#             */
/*   Updated: 2019/08/12 15:22:07 by vdanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COREWAR_H
# define COREWAR_COREWAR_H

# include "../libft/libft.h"
# include "op.h"
# include <ncurses.h>

# define USG_1 "Usage: ./corewar [-dump N | -l N | -v --stealth] [[-n number]"
# define USG_2 "champion1.cor] ...\n"
# define USG_3 "		-n N      : Sets the N number of the next player\n"
# define USG_4 "		-dump N   : Dumps memory after N cycles then exits\n"
# define USG_5 "		-v        : Ncurses output mode\n"
# define USG_6 "		--stealth : Hides the real contents of the memory\n"
# define USG_7 "		-l N      : Verbosity levels, can be added together"
# define USG_8 " to enable several\n"
# define USG_9 "			  - 0 : Show only essentials\n"
# define USG_10 "			  - 1 : Show lives\n"
# define USG_11 "			  - 2 : Show cycles\n"
# define USG_12 "			  - 4 : Show operations (Params are NOT"
# define USG_13 " litteral ...)\n"
# define USG_14 "			  - 8 : Show deaths\n"
# define USG_15 "			  - 16 : Show PC movements"
# define USG_16 " (Except for jumps)\n"
# define ERR_N_FILE "Player file after -n number doesn't exist"
# define ERR_PL_FILES "Player files in arguments missing"
# define ERR_EXT "Wrong file extension"
# define ERR_ONE_V "There can only be one -v flag"
# define ERR_ONE_L "There can only be one -l flag"
# define ERR_L_N "Wrong number of verbosity levels in -l flag"
# define ERR_ONE_DUMP "There can only be one -dump flag"
# define ERR_DUMP_N "Wrong number of cycles in -dump flag"
# define ERR_DUMP_N_2 "Cycles number after -dump flag missing"
# define ERR_N_NUM "Number after -n flag is more than total players number"
# define ERR_N_NUM_2 "Player number after -n flag is not valid"
# define ERR_N_NUM_3 "Player number after -n flag is missing"
# define ERR_READ "Can't read file"
# define ERR_MAGIC "Magic number in player file is wrong"
# define ERR_NULL_NAME "There is no NULL after player name in COR file"
# define ERR_NULL_COMM "There is no NULL after player comment in COR file"
# define ERR_PROG_SIZE "Size of the player is more than maximum size"
# define ERR_READ_SIZE "Size of comment or name in COR file is too small"
# define REG	 		64
# define REG_REG_DIR	88
# define REG_REG		80
# define REG_REG_REG	84
# define REG_DIR_REG	100
# define REG_DIR_DIR	104
# define REG_IND		112
# define REG_IND_REG	116
# define REG_IND_DIR	120
# define DIR_REG		144
# define DIR_REG_REG	148
# define DIR_DIR_REG	164
# define DIR_IND_REG	180
# define IND_REG		208
# define IND_REG_REG	212
# define IND_DIR_REG	228
# define IND_IND_REG 	244

typedef struct		s_ncurses
{
	WINDOW			*border;
	WINDOW			*menu;
	int				status;
}					t_ncurses;

typedef struct		s_player
{
	int				fd;
	char			*file_name;
	int				num;
	t_header		*data;
	unsigned char	*code;
	int				last_live;
	int				lives;
	struct s_player *next;
}					t_player;

typedef struct		s_carr
{
	int				id;
	int				pl_num;
	short			carry;
	int				op_code;
	int32_t			codage;
	int				last_live_cycle;
	int				cycles_to_op;
	int32_t			pc;
	int32_t			pc_start;
	int32_t			reg[REG_NUMBER];
	short			error;
	struct s_carr	*prev;
	struct s_carr	*next;
}					t_carr;

typedef struct		s_data
{
	short			dump_flag;
	short			ncurses_flag;
	short			ncur_stealth;
	short			v0_flag;
	short			v1_flag;
	short			v2_flag;
	short			v4_flag;
	short			v8_flag;
	short			v16_flag;
	int				nbr_cycles;
	int				players_num;
	int				max_n_number;
	t_player		*champs;
	t_carr			*carrs;
	struct s_arena	*arena;
	short			last_live_player;
	int				last_live_cycle;
	int				live_in_current;
	int				live_total;
	int				total_cycles;
	int				cycles_to_die;
	int				cycles_to_check;
	int				carrs_num;
	int				checks_num;
	int				last_mod_c_to_d;
	t_ncurses		*ncurs;
}					t_data;

typedef struct		s_arg
{
	t_arg_type		type;
	uint32_t		size;
	int32_t			value;
	int32_t			reg_num;
}					t_arg;

typedef struct		s_op
{
	char			*op_name;
	short			args_num;
	t_arg			args[3];
	uint8_t			op_code;
	uint32_t		cycles_to_op;
	char			*desc;
	uint8_t			codage_flag;
	uint8_t			carry;
	uint32_t		label_size;
}					t_op;

typedef struct		s_arena
{
	unsigned char	c;
	int				player;
	int				turns;
}					t_arena;

t_data				g_data;
int					g_i;
t_op				g_op_tab[17];

void				error(char *arg);
void				print_usage(void);
void				validate_args(char **av);
void				check_verbosity(char **av);
void				set_flags(void);
t_player			*new_player(int num, char *file_name);
void				add_player_end(t_player *champ);
void				parse_champs(void);
void				sort_players(void);
void				create_arena(void);
void				dump_arena(void);
void				new_carriage(int num, uint32_t poz);
void				delete_carriage(t_carr *elm);
void				intro(void);
void				game_over(void);
void				start_war(void);
void				set_op_code(t_carr *carriage);
void				perform_codage_op(t_carr *carriage);
void				parse_op_arg(t_carr *carriage);
int					get_pos(int pos);
int32_t				get_n_bytes(uint32_t size, int pos);
void				write_n_bytes(int32_t value, uint32_t size, int pos,
					t_carr *carriage);
void				op_live(t_carr *carriage);
void				op_ld(t_carr *carriage);
short				op_codage_ld_lld(t_carr *carriage);
void				op_st(t_carr *carriage);
short				op_codage_st(t_carr *carriage);
void				op_add(t_carr *carriage);
short				op_codage_add_sub(t_carr *carriage);
void				op_sub(t_carr *carriage);
void				op_and(t_carr *carriage);
short				op_codage_and_or_xor(t_carr *carriage);
void				op_or(t_carr *carriage);
void				op_xor(t_carr *carriage);
void				op_zjmp(t_carr *carriage);
void				op_ldi(t_carr *carriage);
short				op_codage_ldi_lldi(t_carr *carriage);
void				op_sti(t_carr *carriage);
short				op_codage_sti(t_carr *carriage);
void				op_fork(t_carr *carriage);
void				op_lld(t_carr *carriage);
void				op_lldi(t_carr *carriage);
void				op_lfork(t_carr *carriage);
void				op_aff(t_carr *carriage);
short				op_codage_aff(t_carr *carriage);
short				check_codage(t_carr *carriage);
void				print_movement(t_carr *carriage);

#endif
