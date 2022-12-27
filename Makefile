NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = -rcs

RM = rm

RMFLAGS = -f

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

SRC = \
./libft/ft_printf.c \
./libft/ft_putstr.c \
./libft/ft_putchar.c \
./libft/ft_pformat.c \
./libft/ft_putnbr.c \
./libft/ft_putunsigned.c \
./libft/ft_put_hexa.c \
./libft/ft_putsign.c \
./libft/ft_putptr.c \
./libft/ft_atoi.c \
./libft/ft_memset.c \
./libft/ft_bzero.c \

OBJECTS = $(SRC:.c=.o)

bonus : $(NAME)
	$(CC) $(CFLAGS) server_bonus.c $< -o $(SERVER_BONUS)
	$(CC) $(CFLAGS) client_bonus.c $< -o $(CLIENT_BONUS)

all : $(NAME) bonus 
	$(CC) $(CFLAGS) server.c $< -o $(SERVER)
	$(CC) $(CFLAGS) client.c $< -o $(CLIENT)

$(NAME) : $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

$(libft)/%.o : $(libft)/%.c
	$(CC) -c $< -o $@

clean : 
	$(RM) $(RMFLAGS) $(OBJECTS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) $(SERVER)
	$(RM) $(RMFLAGS) $(CLIENT)
	$(RM) $(RMFLAGS) $(SERVER_BONUS)
	$(RM) $(RMFLAGS) $(CLIENT_BONUS)

re : fclean all

.PHONY : all clean fclean re