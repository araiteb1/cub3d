# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 22:30:35 by araiteb           #+#    #+#              #
#    Updated: 2023/11/05 22:30:36 by araiteb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=cub3D
CC=gcc
CFLAGS=-Wall -Werror -Wextra -fsanitize=address -g
INCLUDES=.
LDIR=-L /usr/local/lib/
LIBS=-lmlx -framework OpenGL -framework AppKit
SRCS = main.c draw.c func_key_hook.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME) : $(OBJS) cub3d.h defkey.h
		$(CC) -o $(NAME) -I$(INCLUDES) $(filter-out %.h, $^) $(CFLAGS) $(LDIR) $(LIBS)
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all  