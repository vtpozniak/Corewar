NAME_F = corewar

NAME_A = asm

all: $(NAME_F) $(NAME_A)

$(NAME_F):
	@make -C vmachine/

$(NAME_A):
	@make -C asmbler/

clean:
	@make -C vmachine/ clean
	@make -C asmbler/ clean

fclean: clean
	@make -C vmachine/ fclean
	@make -C asmbler/ fclean

re: fclean all

