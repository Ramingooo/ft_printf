NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes

SRCS		= srcs/ft_printf.c \
			  srcs/ft_putchar.c \
			  srcs/ft_putstr.c \
			  srcs/ft_putnbr.c \
			  srcs/ft_putunbr.c \
			  srcs/ft_puthex.c \
			  srcs/ft_putptr.c

OBJS		= $(SRCS:.c=.o)

RM			= rm -f
AR			= ar rcs

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
