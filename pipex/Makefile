# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:50:55 by rrimonte          #+#    #+#              #
#    Updated: 2023/05/10 15:17:10 by rrimonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
LIBS_TARGET		:= 	libft/libft.a
HEADERS			=	pipex_mandatory/pipex.h
B_HEADERS		=	pipex_bonus/pipex_bonus.h
SRCS			=	get_next_line/get_next_line_bonus.c \
					get_next_line/get_next_line_utils_bonus.c \
					pipex_mandatory/ft_files.c \
					pipex_mandatory/ft_lst.c \
					pipex_mandatory/ft_parse.c \
					pipex_mandatory/main.c \
					pipex_mandatory/ft_pipes.c 

B_SRCS			=	get_next_line/get_next_line_bonus.c \
					get_next_line/get_next_line_utils_bonus.c \
					pipex_bonus/ft_files_bonus.c \
					pipex_bonus/ft_lst_bonus.c \
					pipex_bonus/ft_parse_bonus.c \
					pipex_bonus/ft_pipes_bonus.c \
					pipex_bonus/main_bonus.c

OBJS			=	$(SRCS:.c=.o)
B_OBJS			=	$(B_SRCS:.c=.o)
CC				=	gcc
GET_NEXT_LINE_FOLDER	=	get_next_line/
LIBFT_FOLDER	=	libft/
LIBFT_NAME		=	libft.a
LIBS			=	$(LIBFT_FOLDER)$(LIBFT_NAME)
AR				=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address
RM				=	rm -rf

$(NAME): $(LIBS) $(OBJS) $(HEADERS)
$(LIBS_TARGET):
	$(MAKE) -C $(LIBFT_FOLDER)
	$(MAKE) $(NAME)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS)  -o $(NAME)
all:
	$(MAKE) -C $(LIBFT_FOLDER)
	$(MAKE) $(OBJS) $(LIBS) $(HEADERS) 
	$(CC) $(CFLAGS) $(LIBS) $(OBJS)  -o $(NAME)
bonus:
	$(MAKE) -C $(LIBFT_FOLDER)
	$(MAKE) $(B_OBJS) $(LIBS) $(B_HEADERS) 
	$(CC) $(CFLAGS) $(LIBS) $(B_OBJS)  -o $(NAME)
clean:
	$(MAKE) -C $(LIBFT_FOLDER) clean
	$(RM) $(OBJS) $(B_OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_FOLDER) fclean
	$(RM) $(NAME) $(NAME_B)
re: fclean all
re_bonus: fclean bonus
