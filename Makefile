# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:54:36 by axcallet          #+#    #+#              #
#    Updated: 2022/12/13 15:57:43 by axcallet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########### ARGUMENTS ##########

NAME		= fract-ol
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3 -O3
MLXFLAGS	= -Imlx_linux -lXext -lX11 -lm -lz

########## SOURCES ##########

SRCS		= main.c \
			fractol.c \
			utils.c \
			window.c \
			error.c \
			events.c

OBJS		= $(SRCS:.c=.o)
LIBFT		= libft
MLX			= minilibx

########## RULES ##########

RM			= rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) lib
	$(CC) $(CFLAGS) -L $(LIBFT) -L $(MLX) -o $(NAME) $(OBJS) -l:libft.a -l:libmlx.a $(MLXFLAGS)

lib:
	@ $(MAKE) -C $(MLX)
	@ $(MAKE) -C $(LIBFT) bonus

clean:
	@ $(RM) $(OBJS)
	@ $(MAKE) -C $(LIBFT) clean
	@ $(MAKE) -C $(MLX) clean

fclean: clean
	@ $(RM) $(NAME)
	@ $(MAKE) -C $(LIBFT) fclean
	@ $(MAKE) -C $(MLX) clean

re: fclean $(NAME)

.PHONY: all lib clean fclean re
