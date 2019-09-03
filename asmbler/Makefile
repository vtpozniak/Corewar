# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpozniak <vpozniak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 12:21:09 by vpozniak          #+#    #+#              #
#    Updated: 2019/08/29 12:21:21 by vpozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
INC = include/
LIBDIR = ./libft/
LIBFT = $(LIBDIR)libft.a
SRCDIR = src/
LSTDIR = src/coords_lst/
SRC = check_com.c check_str.c check_val.c \
      chekc_argument.c end_com.c flag.c kop.c \
      main.c pars_nc.c record_file.c rozm.c \
      t_dir.c t_ind.c tetr.c validat.c

SRCO = $(addprefix $(SRCDIR), $(SRC:.c=.o))
FLAGS = -Wall -Wextra -Werror -o
all: $(NAME)

$(LIBFT):
	make -C $(LIBDIR) --silent

$(NAME): $(LIBFT) $(SRCO) $(LSTO)
	gcc $(FLAGS) $(NAME) $(SRCO) $(LSTO) -L $(LIBDIR) -lft -I $(INC)

$(SRCDIR)%.o: $(SRCDIR)%.c
	gcc -c $(FLAGS) $@ $< -I $(INC)

$(LSTDIR)%.o: $(LSTDIR)%.c
	gcc -c $(FLAGS) $@ $< -I $(INC)

clean:
	make -C $(LIBDIR) clean --silent
	/bin/rm -f $(SRCO) $(LSTO)

fclean: clean
	make -C $(LIBDIR) fclean --silent
	/bin/rm -f $(NAME)

re: fclean all

rf: fclean all clean
