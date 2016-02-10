NAME = libft.a

INC = .

SRC =

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft.h
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c libft.h
	gcc -c $(FLAGS) $^ -I $(INC)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
