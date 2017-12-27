# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gnegri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 15:59:01 by gnegri            #+#    #+#              #
#    Updated: 2017/12/13 09:45:20 by gnegri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			fractol

SRCS = 			main.c\
				ft_draw.c\
				ft_mandelbrot.c\
				ft_julia.c\
				ft_burning_ship.c\
				ft_sierpinski.c\
				ft_thunder.c\
				ft_calc.c\
				ft_coton.c\
				ft_check_errors.c\
				ft_key_events.c\
				ft_mouse_events.c\
				ft_color.c\

OBJS = 			$(SRCS:.c=.o)

INC = 			libft.h\
				fractol.h\

CC = 			gcc

FLAGS = 		-Wall -Wextra -Werror

FLAGS2 = 		-lmlx -framework OpenGl -framework AppKit

LIB_PATH = 		libft/

LIB = 			libft/libft.a

.PHONY: all clean fclean re

all : 	lib $(NAME) 		

lib :
	@make -C $(LIB_PATH)

$(NAME) : $(OBJS)
	@echo "\033[1;91mCompilation... Fractol\033[0m"
	@$(CC) $(FLAGS) -c $(SRCS)
	@$(CC) $(FLAGS) $(FLAGS2) -o $(NAME) $(OBJS) $(LIB) -Wunused-command-line-argument
	@echo "\033[1;91mCompilation complete !\033[0m" 

$(OBJS): $(SRCS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OBJS)
	@echo "\033[1;91m$(OBJS) removed !\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -f $(NAME)
	@echo "\033[1;91m$(NAME) removed !\033[0m"

re: fclean all

