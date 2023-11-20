# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araiteb <araiteb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 13:24:40 by ahaloui           #+#    #+#              #
#    Updated: 2023/11/20 03:53:06 by araiteb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
INCLUDES=.
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

LDIR=-L /usr/local/lib/
LIBS=-lmlx -framework OpenGL -framework AppKit

GLFWLIB := $(HOME)/.brew/opt/glfw/lib

get_next_line = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS = main.c parsing/file1.c parsing/file2.c parsing/file3.c parsing/file4.c parsing/file5.c parsing/file6.c \
	parsing/file7.c parsing/file8.c execution/draw.c execution/func_key_hook.c execution/function_raycas.c \
	execution/data_texture.c execution/map_to_int.c execution/data_mlx.c

SRCS_ALL_FILES = $(SRCS) $(get_next_line)

OBJS = $(SRCS_ALL_FILES:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(LDIR) $(LIBS) -I$(GLFWLIB) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all	