/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:51:25 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/23 18:39:27 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE "\x1b[34m"
# define PURPLE	"\x1b[35m"
# define CYAN "\x1b[36m"
# define EOC "\x1b[0m"

# include "../libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_lst
{
	char		hash_flag;
	char		prior_space;
	char		prior_plus;
	char		flags;
	int			width;
	char		width_as_arg;
	int			precision;
	char		precision_as_arg;
	char		*size;
	char		big_l_size;
	char		type;
}				t_lst;

int				g_len;
int				g_count;
int				g_flag;
int				g_fl_sign;
char			g_buff[8192];

int				ft_printf(const char *format, ...);
void			ft_fill_buff(const char *str, int len);
void			create_list(const char *s, size_t *i, va_list ptr, t_lst *list);
int				create_list_precision(const char *s, size_t *i, t_lst *list);
int				create_list_width(const char *s, size_t *i, t_lst *list,
				va_list ptr);
void			create_list_size(const char *s, size_t *i, t_lst *list);
void			create_list_flags(const char *s, size_t *i, t_lst *list);
char			create_list_type(const char *s, size_t *i);
int				ft_atoi_i(const char *str, size_t *i);
void			print_format_no_spec(const char *format, size_t *i);
void			read_specif(t_lst *lst, va_list ptr);
void			ft_print_percent(t_lst *lst);
void			ft_print_char(t_lst *lst, va_list ptr);
void			ft_print_width_char(t_lst *lst, int width);
void			ft_print_str(t_lst *lst, va_list ptr);
void			ft_print_str_of_char(int len, char c);
void			ft_print_i_d(t_lst *lst, va_list ptr);
char			*ft_itoa_base_p(t_lst *lst, intmax_t v1, uintmax_t v2,
				int base);
void			ft_print_hex_oct_uns_p(t_lst *lst, va_list ptr);
void			ft_print_flag(t_lst *lst, intmax_t i);
void			ft_print_width_digit(t_lst *lst, intmax_t i);
void			ft_print_precision_digit(t_lst *lst, intmax_t i, int j);
int				set_flag(t_lst *lst, intmax_t i);
void			set_arg(t_lst *lst, va_list ptr);
intmax_t		set_size(t_lst *lst, va_list ptr);
uintmax_t		set_size_unsigned(t_lst *lst, va_list ptr);
long double		set_size_float(t_lst *lst, va_list ptr);
size_t			ft_print_buff(char *str);
void			ft_print_float(t_lst *lst, va_list ptr, long double i);
int				check_minus_zero(double i);
char			*format_nonprc(char *str);
char			*get_nonprc_str(const char *str, int j, int len, char *tmp);
int				check_colors(const char *format);
void			get_color(const char *format, size_t *j, size_t len);
void			get_color2(const char *format, size_t *j, size_t len);
void			fill_nan_inf(long double i, t_lst *lst);

#endif
