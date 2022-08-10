# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khatlas <khatlas@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 14:12:23 by khatlas           #+#    #+#              #
#    Updated: 2022/04/25 07:12:05 by khatlas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

NAME 	= 	libft.a
FUNCTS 	= 	ft_atoi.c ft_itoa.c ft_memcpy.c ft_memset.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_strlen.c ft_strchr.c ft_isdigit.c
OBJECTS	=	ft_atoi.o ft_itoa.o ft_memcpy.o ft_memset.o ft_putchar_fd.o \
			ft_putstr_fd.o ft_strlen.o ft_strchr.o ft_isdigit.o
CC 		= 	cc
ARCC	=	ar -rcs
CFLAGS 	= 	-Wall -Wextra -Werror
RM		=	/bin/rm -f

all: $(NAME)

$(NAME): comp
	@$(ARCC) $@ $(OBJECTS)

comp:
	@$(CC) $(CFLAGS) -c $(FUNCTS)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

bonus: all
	
.PHONY: all clean fclean re bonus comp

