# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 13:59:37 by bschmidt          #+#    #+#              #
#    Updated: 2024/10/29 18:28:45 by bschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS FOR PRINTING
GREEN = \033[0;32m
RESET = \033[0m

# DIRECTORIES
OBJ_DIR = obj
SRC_DIR = src

# EXECUTABLE NAME
NAME		=	 adress

# SOURCE FILES
SRCS		=	main.cpp \
				
# OBJECT FILES
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# COMPILER
CC			=	c++

# COMPILATION FLAGS
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

# COMMANDS
RM = rm -f
MKDIR = mkdir -p

# DIRECTORIES
INCL_DIR = incl

# RULES
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR) $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCL_DIR) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -I $(INCL_DIR) $^ -o $(NAME)
	@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) -r $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re
