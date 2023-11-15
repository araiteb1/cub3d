# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 13:24:40 by ahaloui           #+#    #+#              #
#    Updated: 2023/11/15 19:09:04 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
INCLUDES=.
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
# LIBMLX = $(HOME)/MLX42
# LIBS   = libmlx42/libmlx42.a -ldl -lglfw -pthread -lm

LDIR=-L /usr/local/lib/
LIBS=-lmlx -framework OpenGL -framework AppKit

# NAME_FRAME_WORK = -framework Cocoa -framework OpenGL -framework IOKit


GLFWLIB := $(HOME)/.brew/opt/glfw/lib

get_next_line = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS = main.c parsing/file_error.c parsing/init_map.c parsing/file_parsing.c parsing/file_parsing_1.c parsing/file_parsing_2.c parsing/file_parsing_3.c parsing/file_parsing_4.c\
		mlx/init_mlx.c mlx/utils.c mlx/utils1.c mlx/player_move.c  execution/function_raycas.c execution/draw.c execution/func_key_hook.c

SRCS_ALL_FILES = $(SRCS) $(get_next_line)

OBJS = $(SRCS_ALL_FILES:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(LDIR) $(LIBS) -I$(GLFWLIB) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all	