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

NAME = set.a

CC = gcc

SRC =  set_free.c\
		set_freem.c\
		set_getnextelem.c\
		set_init.c\
		set_isin.c\
		set_print.c\
		set_puts.c

INC = -I../inc

LIB = libft\
	ft_printf
LIB_DIR = $(addsuffix /, $(addprefix ../, $(LIB)))
LIB_INC = $(addprefix -I./, $(LIB_DIR))
LIB_A = $(join $(LIB_DIR), $(addsuffix .a, $(LIB)))

FLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc  $(NAME) $(OBJ)
	@ranlib $(NAME)

$(LIB_A):
	@echo 'build $(notdir $@)'
	@make -C $(dir $@)
	@make clean -C $(dir $@)

$(OBJ_DIR)/%.o : %.c set.h | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) obj/key_int obj/key_string

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
