# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberedda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 17:07:47 by mberedda          #+#    #+#              #
#    Updated: 2015/12/26 12:06:23 by ldaubie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re exe norme

CXX = gcc

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

OBJ_PATH = ./obj/

INC_PATH = ./include/

LIB_PATH = ./lib/

SRC_NAME = check_file.c openfile.c supp_line.c coutnmap.c filltab.c stocktetri.c createelem.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB_NAME = -lft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = $(addprefix -L, $(LIB_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(LIB) $(LIB_NAME) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CXX) $(FLAGS) $(INC) -c $< -o $@

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -fv $(NAME)

re: fclean all

exec: re
	./$(NAME) ./test/map

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*
