#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/05 19:06:01 by vpelivan          #+#    #+#              #
#    Updated: 2019/02/23 18:46:00 by vpelivan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SOURCE = ft_printf.c\
specif_lst_create.c\
create_list_parsers.c\
calc.c\
different.c\
ft_itoa_base_p.c\
print_char_str_type.c\
print_digit_type.c\
print_float_type.c\
print_hex_oct_uns_ptr_type.c\
set_digit.c\
../ft_strlen.c\
../ft_bzero.c\
../ft_strcat.c\
../ft_strchr.c\
../ft_strdup.c\
../ft_strncmp.c

HEADER = ft_printf.h

LIB = ft_printf.o\
specif_lst_create.o\
create_list_parsers.o\
calc.o\
different.o\
ft_itoa_base_p.o\
print_char_str_type.o\
print_digit_type.o\
print_float_type.o\
print_hex_oct_uns_ptr_type.o\
set_digit.o\
ft_strlen.o\
ft_bzero.o\
ft_strcat.o\
ft_strchr.o\
ft_strdup.o\
ft_strncmp.o

FLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SOURCE)
	gcc $(FLAGS) $(SOURCE) -I $(HEADER)
	ar rc $(NAME) $(LIB)

clean:
	@/bin/rm -f $(LIB)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIB)

re: fclean all
