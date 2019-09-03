/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:26:07 by vpozniak          #+#    #+#             */
/*   Updated: 2019/04/05 12:26:12 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include <ctype.h>
# include <limits.h>
# include "libft.h"

typedef struct		s_flags_list
{
	int				hh;
	int				h;
	int				ll;
	int				l;
	int				z;
	int				j;
	int				lzl;
	int				lll;
	int				zero;
	int				hesh;
	int				min;
	int				plus;
	int				space;
	int				len;
	int				width;
	int				p;
	int				p2;
	int				flag;
	int				lens;
	int				dr;
	int				lens1;
	int				it;
	int				it1;
	int				base;
	int				t;
	int				x;
	int				xl;
	int				o;
	int				f;
	char			symvol;
}					t_flags_list;

typedef struct		s_print
{
	t_flags_list	q;
	int				count;
	size_t			i;
	char			*buf;
	char			*str;
	char			*who;
	char			*tmp;
}					t_print;

void				pro_s(t_print *la, va_list list);
void				pro_c(t_print *la, va_list list);
void				check_bf(t_print *la, char c);
void				prof_f(t_print *la, char *str, long double drob);
void				*ft_memalloc(size_t size);
void				pro_p(t_print *la, va_list list);
void				pro_prots(t_print *la);
void				pro_f(t_print *la, va_list list);
void				pro_o_u_x(t_print *la, va_list list);
void				pars_u_x(const char *pars, t_print *la, int i);
void				ft_put(t_print *la, char str);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *dest, int c, size_t n);
void				pro_d_i(t_print *la, va_list list);
char				*ft_strjoin(char const *s1, char const *s2);
char				ft_re(char *str);
char				*ft_strdup(const char *src);
char				*ft_itoa(intmax_t n);
char				*ft_itoa_base(t_print *la, uintmax_t n, int base);
int					minzero(double src);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					ft_printf(const char *pars, ...);
int					ft_toch_wp(const char *pars, t_print *la, int i,
					va_list *list);
int					ft_check_jzl(const char *pars, t_print *la, int i);
int					parsing(const char *pars, t_print *la,
					va_list *list, int c);
int					ft_type(const char *pars, t_print *la,
					va_list *list, int i);
int					ft_flags(const char *pars, t_print *la, int c);
size_t				ft_strlen(const char *str);
intmax_t			check_type(t_print *la, va_list list);
uintmax_t			check_type_2(t_print *la, va_list list);
long double			check_type_3(t_print *la, va_list list);
void				buf(t_print *la, char *str, int j, intmax_t src);
char				*ft_putdup(t_print *la, intmax_t src, char *str);
void				plusd(t_print *la, char *str, intmax_t src, int j);
void				bufd(t_print *la, int j, intmax_t src);
int					ft_check_hl(const char *pars, t_print *la, int i);
void				plusf(t_print *la, char *str, int j);
void				buff(t_print *la, char *str, int j);
void				bufff(t_print *la, int j);
char				*tochnf(intmax_t *whole, t_print *la, int i,
					long double drob);
char				*iter(t_print *la);
void				ft_flo(long double src, t_print *la, intmax_t whole);
#endif
