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
	ht_puts.c\
	key_int/int_cmp.c\
	key_int/int_hash.c\
	key_string/djb2_hash.c

INC = -I../libft/ -I../ft_printf/ -I./

FLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o : %.c hash_tables.h | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) obj/key_int obj/key_string

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
