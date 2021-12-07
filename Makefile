SRC		=	handle_input.c\
	 		push_swap.c\
			sort_small.c
LIBFT 	=	libft/ft_atoi.c\
	 		libft/ft_isalnum.c\
	 		libft/ft_isdigit.c\
	 		libft/ft_memchr.c\
	 		libft/ft_memmove.c\
	 		libft/ft_putendl_fd.c\
	 		libft/ft_split.c\
	 		libft/ft_striteri.c\
	 		libft/ft_strlcpy.c\
	 		libft/ft_strncmp.c\
	 		libft/ft_strtrim.c\
	 		libft/ft_toupper.c\
	 		libft/ft_bzero.c\
	 		libft/ft_isalpha.c\
	 		libft/ft_isprint.c\
	 		libft/ft_memcmp.c\
	 		libft/ft_memset.c\
	 		libft/ft_putnbr_fd.c\
	 		libft/ft_strchr.c\
	 		libft/ft_strjoin.c\
	 		libft/ft_strlen.c\
	 		libft/ft_strnstr.c\
	 		libft/ft_substr.c\
	 		libft/ft_calloc.c\
	 		libft/ft_isascii.c\
	 		libft/ft_itoa.c\
	 		libft/ft_memcpy.c\
	 		libft/ft_putchar_fd.c\
	 		libft/ft_putstr_fd.c\
	 		libft/ft_strdup.c\
	 		libft/ft_strlcat.c\
	 		libft/ft_strmapi.c\
	 		libft/ft_strrchr.c\
	 		libft/ft_tolower.c
LIST	=	list/list.c\
			list/list2.c
ACTIONS	=	actions/actions.c\
			actions/actions2.c
PRINTF	=	printf/conversions/int_to_hex.c\
			printf/conversions/void_to_hex.c\
			printf/srcs/ft_printf.c\
			printf/tools/ft_putchar.c\
			printf/tools/ft_putnbr.c\
			printf/tools/ft_putnbru.c\
			printf/tools/ft_putstr.c\
			printf/tools/ft_rev_int_tab.c\
			printf/tools/ft_strlowcase.c
COMB	=	${SRC} ${LIBFT} ${LIST} ${ACTIONS} ${PRINTF}
OBJS	=	${COMB:.c=.o}
NAME	=	push_swap

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	gcc -o $(NAME) ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o