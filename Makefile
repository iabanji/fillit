# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/05 19:17:19 by anestor           #+#    #+#              #
#    Updated: 2017/11/13 16:41:58 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
ODIR = bin/
OBJ = $(SRC:.c=.o)
CC = gcc
LIB = libft/libft.a
SRC =

SRC += fillit.c
SRC += ft_read.c
SRC += ft_lst.c
SRC += ft_print.c
SRC += ft_arrays.c

O = $(addprefix $(ODIR), $(OBJ))

all: $(NAME)

subdirs:
	@$(MAKE) -C libft/

$(NAME): $(O)
	@echo " ░  \033[34m████  \033[32m   ██  \033[33m ████ \033[35m██      \033[0m░ "
	@echo " ░  \033[34m  ████\033[32m ██████\033[33m ████ \033[35m██████  \033[0m░ "
	@$(CC) $(FLAGS) $(O) -o $(NAME) $(LIB)

$(ODIR)%.o: %.c
	@echo " ░          \033[96mcompiling\033[0m          ░ " 
	@$(CC) $(FLAGS) -c $< -o $@

$(O): | ./bin subdirs

./bin:
	@mkdir $(ODIR)

clean_obj:
	@echo " ░          \033[96mcleaning \033[0m          ░ " 
	@rm -f bin/*.o
	@rm -f libft/bin/*.o

clean: clean_obj
	@rm -rf bin/
	@rm -rf libft/bin/

fclean: clean
	@echo " ░          \033[96mfcleaning\033[0m          ░ "
	@rm -f libft/libft.a
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re subdirs clean_obj
.NOTPARALLEL:

