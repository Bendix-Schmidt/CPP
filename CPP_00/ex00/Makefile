# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 13:59:37 by bschmidt          #+#    #+#              #
#    Updated: 2024/08/18 13:59:46 by bschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS FOR PRINTING
GREEN = \033[0;32m
RESET = \033[0m

# EXECUTABLE NAME
NAME		=	megaphone

# SOURCE FILES
SRCS		=	megaphone.cpp

# COMPILER
CC			=	c++

# COMPILATION FLAGS
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# COMMANDS
RM			=	rm -f

# OBJECT FILES
OBJS		=	$(SRCS:.cpp=.o)

# RULES
%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

fclean		: clean
	@$(RM) $(NAME)

clean		:
	@$(RM) $(OBJS)

re			:	fclean all

.PHONY		:	all clean fclean re