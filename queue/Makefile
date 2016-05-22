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

NAME = queue.a

CC = gcc

SRC = pop.c\
		push.c\
		queue_init.c\
		print_queue.c

SRC_TEST = basic_test.c

INC = -I../inc

FLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_TEST = $(addprefix $(OBJ_DIR)/, $(SRC_TEST:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc  $(NAME) $(OBJ)
	@ranlib $(NAME)

test: $(LIB_A) $(NAME) $(OBJ_TEST)
	$(CC) $(FLAGS) $(INC) $(NAME) $(SRC_TEST) $(LIB_A)

$(OBJ_DIR)/%.o : %.c queue.h | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
