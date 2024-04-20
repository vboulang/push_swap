# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboulang <vboulang@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:38:43 by vboulang          #+#    #+#              #
#    Updated: 2024/04/20 09:44:55 by vboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program names
NAME = libft.a

#Directories
SRCDIR		=	src
INCDIR		=	inc
OBJDIR		=	obj

#Colors
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#Source files
SRC = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c	\
	ft_atol.c	\
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strjoin_gnl.c \
	get_next_line.c

#Source files for bonus
SRC_BONUS = \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

VPATH		=	$(SRCDIR)

#Object files
OBJ	= $(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))
OBJ_BONUS = $(addprefix $(OBJDIR)/,$(SRC_BONUS:%.c=%.o))

#Archive variables
AR = ar

#Compiling variables
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

#.h files name
INC	= $(INCDIR)/libft.h

#Command lines
RM = rm -rf
MK = mkdir -p

all: $(NAME)

$(OBJDIR):
	@$(MK) $(OBJDIR)

$(OBJDIR)/%.o: %.c #$(INC)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	$(OBJDIR) $(OBJ)
	@echo "$(COLOUR_GREEN)Creating Libft Archive...$(COLOUR_END)"
	@$(AR) -rcs $(NAME) $(OBJ)
	@echo "$(COLOUR_GREEN)Libft Archive Created$(COLOUR_END)"


bonus: $(OBJDIR) $(OBJ) $(OBJ_BONUS)
	@echo "$(COLOUR_GREEN)Creating Libft_bonus Archive...$(COLOUR_END)"
	$(AR) -r $(NAME) $?
	@echo "$(COLOUR_GREEN)Libft_bonus Archive Created$(COLOUR_END)"

clean:
	@echo "$(COLOUR_GREEN)Cleaning Libft...$(COLOUR_END)"
	@$(RM) $(OBJDIR)
	@echo "$(COLOUR_GREEN)Libft Cleaned$(COLOUR_END)"

fclean: clean
	@echo "$(COLOUR_GREEN)Removing Libft...$(COLOUR_END)"
	@$(RM) $(NAME)
	@echo "$(COLOUR_GREEN)Libft Removed$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
