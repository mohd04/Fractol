# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpatel <mpatel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 12:00:03 by mpatel            #+#    #+#              #
#    Updated: 2021/12/19 12:15:28 by mpatel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = srcs/ft_fractol.c srcs/hook.c srcs/main.c

INCL = -I ./includes/ft_fractol.h
OPENGL = ./minilibx_opengl_20191021

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
		@$(MAKE) -C $(OPENGL)
		$(CC) $(CFLAGS) -o $@ $(OBJS) -lmlx -framework OpenGL -framework AppKit -L $(OPENGL)

all: $(NAME)

.Phony: re clean fclean

clean:
		@$(MAKE) -C $(OPENGL) clean
		$(RM) $(OBJS)

fclean: clean
		@$(MAKE) -C $(OPENGL) clean
		$(RM) $(NAME)

re: fclean all
