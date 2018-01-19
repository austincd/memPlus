#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/13 17:05:32 by adaly             #+#    #+#              #
#    Updated: 2017/11/24 14:32:47 by adaly            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = memPlus

SRCS = \
		alloc.c			\
		free.c			\
		diag.c			\
		init.c			\
		kill.c

all: $(NAME)

$(NAME): lib

	@cd src && clang -Wall -Wextra -Werror -c $(SRCS) -g
	cd src && clang $(SRCS:.c=.o) -g -L../libft -lftprintf -o $(NAME)
	mv src/memPlus .

lib:
	@cd libft && make

clean:
	@cd libft && make clean
	@cd src && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@/bin/rm -f $(NAME)

re: fclean all
