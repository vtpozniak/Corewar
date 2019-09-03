/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:31:51 by vpozniak          #+#    #+#             */
/*   Updated: 2019/08/31 20:00:55 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H
# define SYMBOL "r%0123456789:"
# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct			s_mark
{
	char				*name;
	struct s_mark		*next;
}						t_mark;

typedef struct			s_var
{
	int					bin;
	int					rozm;
	unsigned int		value;
	char				*name_mark;
	struct s_var		*next;
}						t_var;

typedef struct			s_func
{
	char				*name;
	int					kode;
	int					kol_a;
	int					mark_size;
	int					vars[3];
	int					dir;
	t_mark				*marks;
	int					number_bt;
	t_var				*varr;
	struct s_func		*next;
	int					k;
}						t_func;

typedef struct			s_bot
{
	char				*name;
	char				*comment;
	t_func				*func;
	struct s_bot		*next;
}						t_bot;

typedef struct			s_flag
{
	int					flag;
	int					sz;
}						t_flag;

t_func				g_operations[17];

int						g_fllag;
int						mcheck(t_func *func);
int						size_code(t_bot *a);
int						rozm(char *str, char c);
int						rtmas(t_var *var, int i);
int						nuchcoutn(t_func *nuch, int count);
int						kop(char *line, char **line2, int len, int size);
int						check_argument(char *line, t_func **b, int command);
char					*ft_strndup(char const *str, size_t n);
char					*new_free(char *line, char *line2, int flag);
char					**pars_nc(int fd, t_bot **st, char	*fl, char *n);
char					*myfunc1(int q, char *fl2, char *fl, int fl3);
void					chk_error(char *line);
void					free_matr(char **matrix);
void					ft_end(char *tmp, char *fl, char *n);
void					tetr(t_var **a, t_var *b);
void					error_message(char *line, char *error);
void					chk_error(char *line);
void					record_byt(int fd, int a, int count_bytes, int	j);
void					name_mark(char *line, char *nuch);
void					check_com(char *line, t_bot **a,
						t_mark *labels, int func);
void					rozm_comm(t_func *func, t_var *vars, t_flag *flag);
char					**check_str(char *fl, int i, int j, int k);
void					end_com(t_bot **a, t_func *command);
void					t_dir(char *line, int c, int i, t_func **b);
void					t_ind(char *line, int c, int i, t_func **b);
void					check_val(int fd, t_bot **st, char	**mass, char *n);
void					validat(int fd, t_bot **a, char *n);
void					record_file(t_bot *st, char **str, int i, t_bot *nuch);
void					flag_a(t_bot *a);
#endif
