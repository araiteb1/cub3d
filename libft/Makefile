# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 13:44:31 by ahaloui           #+#    #+#              #
#    Updated: 2022/11/12 13:43:11 by ahaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =   ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_memset.c ft_bzero.c ft_isascii.c ft_strlen.c ft_toupper.c ft_tolower.c \
		ft_isprint.c ft_memcpy.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strmapi.c ft_striteri.c \
		ft_memcmp.c ft_memmove.c ft_memchr.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_substr.c ft_strtrim.c \
		ft_strjoin.c ft_strlcpy.c ft_strlcat.c ft_split.c ft_strdup.c ft_striteri.c ft_calloc.c ft_atoi.c ft_itoa.c 

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c
			
OBJECT = $(SRC:.c=.o)

BONUS_OBJECT = $(BONUS_SRC:.c=.o)

CC = cc

ARCHIVE = ar -rc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT) 
	$(ARCHIVE) $(NAME) $(OBJECT)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(OBJECT) $(BONUS_OBJECT) 
	$(ARCHIVE) $(NAME) $(OBJECT) $(BONUS_OBJECT)

clean :
	$(RM) $(OBJECT) $(BONUS_OBJECT)

fclean : clean
	$(RM) $(NAME)

re : fclean all