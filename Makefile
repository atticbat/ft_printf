# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 14:12:23 by khatlas           #+#    #+#              #
#    Updated: 2022/08/10 04:21:48 by khatlas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

VPATH	=	Bonus Mandatory
LDIR 	=	Libft/
MDIR 	=	Mandatory/
BDIR 	=	Bonus/
LNAME	=	libft.a
NAME 	=	libftprintf.a
MFUNCTS	=	ft_itoa_base_u.c ft_printf.c ft_parse.c ft_parse_x.c ft_format_i.c \
			ft_parse_u.c ft_parse_s.c ft_parse_pp.c ft_parse_p.c ft_parse_i.c \
			ft_parse_c.c ft_format_c.c ft_format_x.c ft_format_s.c \
			ft_format_pp.c
BFUNCTS	=	ft_format_c_bonus.c ft_format_i_bonus.c ft_format_s_bonus.c \
			ft_format_x_bonus.c ft_parse_bonus.c ft_format_pp_bonus.c \
			ft_itoa_base_u_bonus.c ft_parse_c_bonus.c ft_parse_i_bonus.c \
			ft_parse_p_bonus.c ft_parse_pp_bonus.c ft_parse_s_bonus.c \
			ft_parse_u_bonus.c ft_parse_x_bonus.c ft_printf_bonus.c
MOBJS	=	$(MFUNCTS:.c=.o)
BOBJS	=	$(BFUNCTS:.c=.o)
MPATH	=	$(addprefix $(MDIR),$(MOBJS))
BPATH	=	$(addprefix $(BDIR),$(BOBJS))
LIBFT	=	$(addprefix $(LDIR),$(LNAME))
CC 		= 	cc
ARCC 	= 	ar -rcs
CFLAGS 	= 	-Wall -Wextra -Werror
RM 		= 	/bin/rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(MPATH)
	@cp $(LIBFT) $@
	@$(ARCC) $@ $(MPATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c -I . $^ -o $@

bonus: $(LIBFT) $(BPATH)
	@cp $(LIBFT) $(NAME)
	@$(ARCC) $(NAME) $(BPATH)

$(LIBFT):
	@make -C $(LDIR)

clean:
	@make clean -C $(LDIR)
	@$(RM) $(MPATH)
	@$(RM) $(BPATH)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LDIR)

re: fclean all

.PHONY: all bonus clean fclean re
