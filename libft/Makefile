# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 11:03:06 by axcallet          #+#    #+#              #
#    Updated: 2022/12/08 15:46:00 by axcallet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRCS =	ft_atof.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

SRCS_BONUS =	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

CFLAGS =	-Wall -Wextra -Werror

ifdef VAR
	SRCS +=	$(SRCS_BONUS)
endif

OBJS =		$(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.c.o:
			gcc -g $(CFLAGS) -c $< -o $@

RM =		rm -f

$(NAME) : 	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

all :		$(NAME)

bonus :		$(OBJS_BONUS)
			make VAR=1

clean :
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all

so:
			gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS)

.PHONY : all clean fclean re
