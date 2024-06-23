# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 16:25:12 by fbelotti          #+#    #+#              #
#    Updated: 2024/06/23 16:26:38 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
AUTHOR = Florent Belotti

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./Includes -I./Includes/42_cursus_libft -I/opt/homebrew/Cellar/readline/8.2.10/include
LIBS = ./Includes/42_cursus_libft/libft.a -L/opt/homebrew/Cellar/readline/8.2.10/lib -lreadline -lhistory

SRCDIR = Src
OBJDIR = obj

SRC = $(shell find $(SRCDIR) -name \*.c -type f -print)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

DEPS = $(OBJ:.o=.d)

all: announce intro libft $(NAME)

announce:
	@echo "\n==================================="
	@echo "Project: $(NAME)\n"
	@echo "Author: $(AUTHOR)"
	@echo "===================================\n"

intro:
	@echo "Starting the build process...\n"

$(NAME): $(OBJ)
	@echo "\nphilosophers:	Creating library..."
	@$(MAKE) -C ./Includes/42_cursus_libft > /dev/null
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(INCLUDES) -o $@
	@echo "philosophers:	Executable $@ created."

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "philosophers: Src: compiling file $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

libft:
	@$(MAKE) -C ./Includes/42_cursus_libft > /dev/null

-include $(DEPS)

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C ./Includes/42_cursus_libft clean > /dev/null
	@echo "Cleaned."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./Includes/42_cursus_libft fclean > /dev/null
	@echo "Fully cleaned."

re: fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re libft announce intro
