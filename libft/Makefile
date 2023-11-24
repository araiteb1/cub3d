# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 13:44:31 by ahaloui           #+#    #+#              #
#    Updated: 2023/11/24 11:12:15 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =   ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_toupper.c ft_tolower.c \
		ft_isprint.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
		ft_substr.c ft_strtrim.c ft_split.c ft_strdup.c ft_atoi.c
			
OBJECT = $(SRC:.c=.o)


CC = cc

ARCHIVE = ar -rc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT) 
	$(ARCHIVE) $(NAME) $(OBJECT)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@


clean :
	$(RM) $(OBJECT)

fclean : clean
	$(RM) $(NAME)

re : fclean all