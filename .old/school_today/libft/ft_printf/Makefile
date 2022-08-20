NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
HEADER		=	ft_printf.h
LIBFT_SRCS	=	
TYPE_SCRS	=	$(addprefix utils/,	ft_putchar_fd.c		ft_putnbr_fd.c	\
				ft_strlen.c			typechar.c			typehexlow.c	\
				typehexup.c			typeint.c			typepointer.c	\
				typestring.c		typeunsigneddec.c)
SRCS		=	$(TYPE_SCRS)	ft_printf.c
OBJS		=	$(SRCS:.c=.o)
LIBFT		=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
