# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:11:35 by vboulang          #+#    #+#              #
#    Updated: 2024/04/06 12:10:44 by vboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program names
NAME		=	push_swap

#Compiling variables
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address

#Directories
LIBDIR			=	libft
SRCDIR			=	src
INCDIR			=	inc
OBJDIR			=	obj

#Colors
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#Library names
LIBFT		=	$(LIBDIR)/libft.a

#.h files name
INC			=	$(INCDIR)/push_swap.h

#Command lines
RM			=	rm -rf
MK			=	mkdir -p

#Source files
SRC			= 	push_swap.c 	\
				moves_s_p.c 	\
				moves_rr.c		\
				moves_r.c		\
				stack.c			\
				misc.c			\
				push_swap_a.c	\
				push_swap_b.c

VPATH		=	$(SRCDIR)

#Object files
OBJ			=	$(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
	@make -C $(LIBDIR)
	@echo "$(COLOUR_GREEN)Compiling push_swap...$(COLOUR_END)"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(COLOUR_GREEN)Creating Libft Archive...$(COLOUR_END)"

$(OBJDIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/inc -c $< -o $@

$(OBJDIR):
	@$(MK) $(OBJDIR)

clean:
	@echo "$(COLOUR_GREEN)Cleaning push_swap...$(COLOUR_END)"
	@$(RM) $(OBJDIR)
	@echo "$(COLOUR_GREEN)push_swap Cleaned$(COLOUR_END)"
	@make -C $(LIBDIR) clean

fclean: clean
	@echo "$(COLOUR_GREEN)Removing push_swap...$(COLOUR_END)"
	@$(RM) $(NAME)
	@echo "$(COLOUR_GREEN)push_swap Removed$(COLOUR_END)"
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
