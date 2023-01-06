# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 19:28:23 by ekaik-ne          #+#    #+#              #
#    Updated: 2022/07/10 13:44:20 by ekaik-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
GCC = ${CC} ${CFLAGS}
MLX =  -Iminilibx-linux/ -Lminilibx-linux/ -lmlx -lXext -lX11 -lm 

NAME = so_long
LIBFT = Libft/libft.a
SRCS = anim.c check.c events.c init.c layout.c main.c moviment.c render.c utils.c
OBJ = ${SRCS:.c=.o}

.PHONY = all clean fclean re

all: ${NAME}

${NAME}: $(OBJ)
	$(GCC) $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

${OBJ}: | $(LIBFT)

${LIBFT}:
	$(MAKE) bonus -C Libft/

norm:
	norminette -R CheckForBidden anim.c check.c events.c init.c layout.c main.c moviment.c render.c utils.c Libft/

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C Libft/
	rm -f $(NAME)

re: fclean all