NAME_F	= corewar

SRC_F	= srcs/argv_flags.c\
		srcs/carriages.c\
		srcs/champs_parser.c\
		srcs/different.c\
		srcs/init_mem_field.c\
		srcs/main.c\
		srcs/nc_end_game.c\
		srcs/nc_fill_arena.c\
		srcs/nc_fill_menu.c\
		srcs/nc_main.c\
		srcs/nc_metods.c\
		srcs/nc_parcer.c\
		srcs/op.c\
		srcs/op_arguments_parser.c\
		srcs/op_codage_one.c\
		srcs/op_codage_two.c\
		srcs/op_live.c\
		srcs/op_one.c\
		srcs/op_three.c\
		srcs/op_two.c\
		srcs/players.c\
		srcs/verbosity.c\
		srcs/war_cycle.c

OBJ_F	= $(patsubst srcs/%.c,obj_vmachine/%.o,$(SRC_F))

all: $(NAME_F)

$(NAME_F): $(OBJ_F)
	@make -C libft/
	@gcc -Wall -Wextra -Werror -L libft/ -lft -lncurses $(OBJ_F) -o $(NAME_F)
	@printf '\033[32m[ ✔ ] %s %s\n\033[0m' "Create" $(NAME_F)

obj_vmachine/%.o: srcs/%.c
	@mkdir -p obj_vmachine
	@gcc -Wall -Wextra -Werror -c $< -o $@
	@printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	@/bin/rm -rf obj_vmachine
	@make -C libft/ clean
	@printf '\033[31m[ ✔ ] %s %s %s\n\033[0m' "Clean" $(NAME_F) $(NAME_V)

fclean: clean
	@/bin/rm -f $(NAME_F)
	@make -C libft/ fclean
	@printf '\033[31m[ ✔ ] %s %s %s\n\033[0m' "Fclean" $(NAME_F) $(NAME_V)

re: fclean all
