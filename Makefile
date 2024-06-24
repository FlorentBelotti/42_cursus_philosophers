# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 16:25:12 by fbelotti          #+#    #+#              #
#    Updated: 2024/06/24 12:06:07 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
AUTHOR = Florent Belotti

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./Includes -I/opt/homebrew/Cellar/readline/8.2.10/include
LIBS = -L/opt/homebrew/Cellar/readline/8.2.10/lib -lreadline -lhistory

SRCDIR = Src
OBJDIR = obj

SRC = $(shell find $(SRCDIR) -name \*.c -type f -print)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

DEPS = $(OBJ:.o=.d)

all: announce intro $(NAME)

announce:
	@echo "\n==================================="
	@echo "Project: $(NAME)\n"
	@echo "Author: $(AUTHOR)"
	@echo "===================================\n"

intro:
	@echo "Starting the build process...\n"

$(NAME): $(OBJ)
	@echo "\nphilosophers: Creating library..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(INCLUDES) -o $@
	@echo "philosophers: Executable $@ created."

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "philosophers: Src: compiling file $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEPS)

clean:
	@$(RM) $(OBJ)
	@echo "Cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "Fully cleaned."

re: fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re announce intro

