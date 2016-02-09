
# **************************************************************************** #
#                __  __   _   _  _____ ___ ___ _    ___                        # 
#               |  \/  | /_\ | |/ / __| __|_ _| |  | __|                       #
#               | |\/| |/ _ \| ' <| _|| _| | || |__| _|                        # 
#               |_|  |_/_/ \_\_|\_\___|_| |___|____|___|                       #
#                                                                    ggilaber  #
# **************************************************************************** #

####
# Variables internes:
#    $@ -> nom cible
#    $< -> nom premiere dependance
#    $^ -> liste dependance
#    $? -> liste depandances plus recentes que cible
#    $* -> nom fichier sans suffixe
###

.PHONY: all clean fclean re

# Project name
NAME = printf

# Source

FILE =  ft_printf.c\
		ft_printf_fd.c\
		my_printf.c\
		ft_putnbr_fd.c\
		lib/ft_strlen.c\
		lib/ft_memcpy.c\
		lib/ft_bzero.c\
		my_write.c\
		read_number.c\
		write_arg.c\
		write_float.c\
		write_ptr.c\
		main.c

# Obj directory
O_DIR = obj

O_FILE = $(addprefix $(O_DIR)/, $(FILE:.c=.o))

# C compiler
CC = gcc

# C flags
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(O_FILE)
	$(CC) $(FLAGS) -o $@ $(O_FILE)

$(O_DIR)/%.o: %.c $(INC) | $(O_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(O_DIR):
	mkdir -p obj/lib

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
