# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:03:21 by ialashqa          #+#    #+#              #
#    Updated: 2024/06/02 15:18:32 by ismailalash      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
SRC =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_substr.c ft_striteri.c  ft_strlcat.c \
		ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_strcmp.c ft_putnbr_fd.c \
		ft_split.c ft_strnstr.c ft_itoa.c ft_putendl_fd.c ft_strdup.c\
		ft_printfchar.c ft_printfhex.c ft_printfint.c ft_printfpointer.c \
		ft_printfstr.c ft_printfunit.c ft_printf.c ft_formatcheck.c\

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	
OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY = all bonus clean fclean re