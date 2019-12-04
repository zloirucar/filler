# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 11:23:44 by skrabby           #+#    #+#              #
#    Updated: 2019/11/06 15:39:49 by oelaina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTF_DIR = ./srcs/ft_printf/
LIBFT_DIR = ./srcs/libft/
OBJ_DIR = ./object/

PRINTF_SRCS = ft_printf.c \
	   flags.c \
	   type_checker.c \
	   adapt_charflags.c \
	   adapt_gridflag.c \
	   adapt_nbflags.c \
	   ll_itoa_base_func.c \
	   ll_itoa_base.c \
	   llu_itoa_base.c \
	   finalstr.c \
	   color.c \
	   ld_handler.c \
	   str_multiplier.c \
	   return_result.c \
	   new_functions.c \
	   type_checker_func.c \
	   clear_create_flags.c \
	   grid_types.c \
	   ld_optimize.c \
	   ld_round.c \
	   ld_precision.c \
	   egflag_handler.c \
	   check_star.c \

LIB_SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_itoa.c \
	   ft_putendl.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_strndup.c \
	   ft_strreverse.c \
	   ft_lstcount.c \
	   ft_lstaddlast.c \
	   ft_lstreverse.c \
	   ft_module.c \
	   ft_nblen.c \
	   ft_strempty_symb.c \
	   ft_negativezero.c \
	   ft_putstr_null.c \
	   get_next_line.c \

OBJ = ${LIB_SRCS:.c=.o} ${PRINTF_SRCS:.c=.o}
LIB_HEADER = ./srcs/libft/libft.h
PRINTF_HEADER = ./include/ft_printf.h

all: $(NAME)
 
$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(addprefix $(LIBFT_DIR), $(LIB_SRCS)) -I $(LIB_HEADER)
	@gcc -Wall -Wextra -Werror -c $(addprefix $(PRINTF_DIR), $(PRINTF_SRCS)) -I $(PRINTF_HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@tput setaf 6; tput bold; echo "DONE LIB"
	
%.o: $(LIBFT_DIR)/%.c 
	@gcc -Wall -Wextra -Werror -c $<

%.o: $(PRINTF_DIR)/%.c
	@gcc -Wall -Wextra -Werror -c $<

clean:
	@rm -f $(OBJ)
	@tput setaf 6; tput bold; echo "DONE Clean!"

fclean: clean
	@rm -f $(NAME)
	@tput setaf 6; tput bold; echo "DONE Fclean!"

re: fclean all

.PHONY: all clean fclean re
