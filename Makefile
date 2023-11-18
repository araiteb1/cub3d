# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 13:24:40 by ahaloui           #+#    #+#              #
#    Updated: 2023/11/18 22:10:15 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
INCLUDES=.
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
LIBMLX = $(HOME)/MLX42
LIBS   = libmlx42/libmlx42.a -ldl -lglfw -pthread -lm

NAME_FRAME_WORK = -framework Cocoa -framework OpenGL -framework IOKit

GLFWLIB := $(HOME)/.brew/opt/glfw/lib

get_next_line = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS = main.c parsing/file1.c parsing/file2.c parsing/file3.c parsing/file4.c parsing/file5.c parsing/file6.c  parsing/file7.c parsing/file8.c

SRCS_ALL_FILES = $(SRCS) $(get_next_line)

OBJS = $(SRCS_ALL_FILES:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(LIBS) $(NAME_FRAME_WORK) -L$(GLFWLIB) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all	