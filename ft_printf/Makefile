# **************************************************************************** #
#                __  __   _   _  _____ ___ ___ _    ___                        # 
#               |  \/  | /,\ | |/ / __| __|_ _| |  | __|                       #
#               | |\/| |/ - \| ' <| _|| _| | || |__| _|                        # 
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

NAME = ft_printf.a

CC = gcc

SRC = ft_printf.c\
	ft_printf_fd.c\
	ft_putnbr_fd.c\
	my_printf.c\
	my_write.c\
	read_number.c\
	write_arg.c\
	write_float.c\
	write_hex.c\
	write_ptr.c\
	key_print.c

INC = ../inc

FLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc  $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o : %.c ft_printf.h | $(OBJ_DIR)
	@$(CC) $(FLAGS) -I $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
