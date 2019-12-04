# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 22:26:36 by oelaina           #+#    #+#              #
#    Updated: 2019/11/19 20:40:06 by oelaina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = oelaina.filler

LIB = library

FILL_DIR = ./srcs/

FILL_SRCS = main.c \
			scan.c \
			write.c \
			init.c \
			create_arr.c \
			tools.c \
			list_func.c \
			placeable.c \
			get_result.c \
			manhat.c \
			diagonal.c \

OBJ = $(FILL_SRCS:.c=.o)

FILL_HEADER = ./srcs/filler.h

all: $(LIB) $(NAME)

$(LIB):
	@make -C ./lib/

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(addprefix $(FILL_DIR), $(FILL_SRCS)) -I $(FILL_HEADER)
	@gcc -Wall -Wextra -Werror -o$(NAME) $(addprefix $(FILL_DIR), $(FILL_SRCS)) -I $(FILL_HEADER)  -L./lib/ -lftprintf

%.o: $(FILL_DIR)/%.c
	@gcc -Wall -Wextra -Werror -o$(NAME) $(addprefix $(FILL_DIR), $(FILL_SRCS)) -I $(FILL_HEADER)  -L./lib/ -lftprintf

copy:	
	@rm -rf ../visual/assets/players/oelaina.filler
	@cp oelaina.filler ../visual/assets/players/oelaina.filler
	@cd ../visual/assets/ && ./filler_vm -f maps/map02 -p1 players/oelaina.filler -p2 players/abarriel.filler | ../visualisateur/visualisateur

copy2:	
	@rm -rf ../visual/assets/players/oelaina.filler 
	@cp oelaina.filler ../visual/assets/players/oelaina.filler
	@cd ../visual/assets/ && ./filler_vm -f maps/map02 -p1 players/lcharvol.filler -p2 players/oelaina.filler | ../visualisateur/visualisateur
clean:
	@make clean -C ./lib
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./lib
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
