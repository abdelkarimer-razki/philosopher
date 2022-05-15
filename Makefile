# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 23:11:08 by aer-razk          #+#    #+#              #
#    Updated: 2022/04/14 23:11:09 by aer-razk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FILES = philosopher.c ./libft/ft_atoi.c create.c sleeping.c args_pro.c eating.c

INCLUDE = philosopher.h

CC = cc 

CFLAGS = -Wall -Wextra -Werror

OBJS = ${FILES:.c=.o}

all:$(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $(NAME)
	@echo "SUUUUUUUUIIIIIII"

%.o : %.c $(INCLUDE)
	gcc  $(CFLAGS) -o $@ -c $<

clean:
	@rm -f ${OBJS}
	@echo "SUUUUUUUUIIIIIII"

fclean: clean
	@rm -f ${NAME}
	@rm -f fdf_bonus
	@echo "SUUUUUUUUIIIIIII"

re: fclean all
