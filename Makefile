# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gpirro <gpirro@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/25 10:42:17 by gpirro        #+#    #+#                  #
#    Updated: 2022/03/25 10:42:19 by gpirro        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap
VPATH =			./src/ ./include/ ./sorting/ ./utils/ ./parsing/
SRCS = 			push_swap.c\
				parsing.c\
				exit.c\
				bubblesort.c\
				actions.c\
				sort_small.c\
				radix.c
INCL_DIR		= ./include/
OBJS			= $(SRCS:.c=.o)
CFLAGS			= -Wall -Wextra -I$(INCL_DIR)
LIBFT			= libft/libft.a
CC				= gcc -g

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) $(LIBFT)

re:	fclean $(NAME)

.PHONY: all clean fclean re
