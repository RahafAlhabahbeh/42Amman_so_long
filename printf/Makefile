SRCS = ft_printf.c ft_putnbr_hexa.c ft_putnbr.c ft_putstr.c \
       ft_putptr.c ft_putchar.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	 ${LIBC} $@ $?

%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
