# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/01/07 17:16:03 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#/******************* DIRECTORIES *******************/
SRC_PATH =  ./
OBJ_PATH =	obj
INC_PATH =	./ \
		  	libft

#/******************* COMPILATION *******************/
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra

#/********************* PREFIXES ********************/
LIBFT =		-Llibft/ -lft

#/********************** BINARY *********************/
NAME =		get_next_line

#/********************** SOURCE *********************/
SRC =		get_next_line.c\
OBJ =		$(SRC:.c=.o)

#/********************** PATH  *********************/
OBJP =		$(addprefix $(OBJ_PATH)/,$(OBJ))
INCP =		$(foreach dir, $(INC_PATH), -I$(dir))


###################################################
#/********************** RULES *********************/

all : $(NAME)

$(NAME) : $(OBJP)
	make -C ./libft
	$(CC) $(INCP) $(LIBFT) -o $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH) 2 /dev/null || true
	make clean -C libft/

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all
