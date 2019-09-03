#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 13:39:28 by vpozniak          #+#    #+#              #
#    Updated: 2018/10/23 15:33:01 by vpozniak         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
HEADER      =   ft_printf.h
FILES		=	ft_printf.c\
parsing.c\
pro_c.c\
pro_s.c\
pro_d_i.c\
free_f.c\
ft_itoa.c\
ft_check_type.c\
funckd_i.c\
pars_func.c\
pro_o_u_x.c\
pro_o_u_x.c\
pro_prots.c\
pro_p.c\
pro_f.c\
prof_f.c\
funck_f.c\
ft_itoa_base_p.c\
libfan1.c\
ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_strlen.c\
ft_strdup.c\
ft_strcpy.c\
ft_strncpy.c\
ft_strcat.c\
ft_strncat.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_strstr.c\
ft_strnstr.c\
ft_strcmp.c\
ft_strncmp.c\
ft_atoi.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_memalloc.c\
ft_memdel.c\
ft_strnew.c\
ft_strdel.c\
ft_strclr.c\
ft_striter.c\
ft_striteri.c\
ft_strmap.c\
ft_strmapi.c\
ft_strequ.c\
ft_strnequ.c\
ft_strsub.c\
ft_strjoin.c\
ft_strtrim.c\
ft_strsplit.c\
ft_itoa.c\
ft_putchar.c\
ft_putstr.c\
ft_putendl.c\
ft_putnbr.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_lstnew.c\
ft_lstdelone.c\
ft_lstdel.c\
ft_lstadd.c\
ft_lstiter.c\
ft_intlen.c\
ft_lstmap.c\
get_next_line.c\
ft_mas.c\
ft_mtrim.c\
ft_wordlen.c\
new_free.c\
ft_count_word.c

OBJS		= 	$(FILES:.c=.o)
	
all: $(NAME)

$(NAME): $(HEADER) $(OBJS)
		@ar rc $(NAME) $(OBJS)
		
clean:
		@rm -rf $(OBJS)

fclean:
		@rm -rf $(OBJS) $(NAME)

re: fclean all