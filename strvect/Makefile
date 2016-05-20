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

NAME = strvect.a

CC = gcc

SRC =  _strvect_extend.c\
	strvect_init.c\
	strvect_push_char.c\
	strvect_push_str.c

SRC_TEST = test.c

INC = -I../inc

LIB = libft\
	  ft_printf
LIB_DIR = $(addsuffix /, $(addprefix ../, $(LIB)))
LIB_INC = $(addprefix -I./, $(LIB_DIR))
LIB_A = $(join $(LIB_DIR), $(addsuffix .a, $(LIB)))

FLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_TEST = $(addprefix $(OBJ_DIR)/, $(SRC_TEST:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc  $(NAME) $(OBJ)
	@ranlib $(NAME)

test: $(LIB_A) $(NAME) $(OBJ_TEST)
	$(CC) $(FLAGS) $(INC) $(NAME) $(LIB_A) $(SRC_TEST)

$(LIB_A):
	@echo 'build $(notdir $@)'
	@make -C $(dir $@)
	@make clean -C $(dir $@)

$(OBJ_DIR)/%.o : %.c strvect.h | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
