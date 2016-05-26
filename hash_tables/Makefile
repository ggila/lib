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

NAME = hash_tables.a

CC = gcc

SRC = ht_free.c\
	ht_freem.c\
	ht_get.c\
	ht_getnextkv.c\
	ht_init.c\
	ht_isset.c\
	ht_print.c\
	ht_print_all.c\
	ht_puts.c\
	key_int/int_cmp.c\
	key_int/int_hash.c\
	key_string/djb2_hash.c

SRC_TEST = test_ht.c\
		   test_func.c

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
	$(CC) $(FLAGS) -o test $(INC) $(NAME) $(SRC_TEST) $(LIB_A)
	./test

$(LIB_A):
	@echo 'build $(notdir $@)'
	@make -C $(dir $@)
	@make clean -C $(dir $@)

$(OBJ_DIR)/%.o : %.c hash_tables.h | $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) obj/key_int obj/key_string

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
