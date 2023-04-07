# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csenand <csenand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:11:55 by csenand           #+#    #+#              #
#    Updated: 2023/04/07 13:58:31 by csenand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Executable's name -- #
NAME		=	libft.a

# -- Compilation Flag -- #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# -- Remove and Archive -- #
RM			= 	rm -rf
AR			= 	ar rcs 

# -- SRC Files -- #
SRCS_DIR	=	./src/
SRCS_LST	= 	ft_atof.c \
				ft_atoi.c \
				ft_atol.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_putendl_fd.c \
				ft_strnstr.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strchr.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_split.c \
				ft_strrchr.c \
				ft_substr.c \
				ft_strncmp.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_strlcat.c \
				ft_strdup.c \
				ft_tolower.c \
				ft_toupper.c 
				
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

# -- OBJ Files -- #
OBJS_DIR	=	./obj/
OBJS_LST	=	$(patsubst %.c, %.o, $(SRCS_LST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LST))

# -- HEADER Files -- #
HEADER_DIR	=	./include/
HEADER_LST	=	libft.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LST))

# -- Colors -- #
RESET		= 	\033[0m
RED			= 	\033[0;31m
GREEN		= 	\033[0;32m
YELLOW		= 	\033[0;33m
BLUE		= 	\033[0;34m
PURPLE		= 	\033[0;35m
CYAN		= 	\033[0;36m
ERASE_LINE 	= 	\033[2K\r


# -- Executable's creation -- #
all : dir $(NAME)

# -- Compile library -- #
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(ERASE_LINE)✅ $(GREEN)Libft successfully created.				✅$(RESET)"

# -- Create all files .o (object) from files .c (source code) -- #
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "$(ERASE_LINE)🎛️  $(PURPLE)Compiling$(YELLOW) $(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# -- Create directory for *.o files -- #
dir:
	@mkdir -p $(OBJS_DIR)

# -- Removes objects -- #
clean :
	@printf "💥 $(RED)Removing $(NAME)'s objects...$(RESET)			💥\n"
	@$(RM) $(OBJS_DIR)
	@printf "🗑️  $(CYAN)libft's object successfully deleted.$(RESET) 		🗑️\n"

# -- Removes objects (with clean) and executable -- #
fclean : clean
	@printf "💥 $(RED)Removing $(NAME)'s executable...$(RESET)		💥\n"
	@$(RM) $(NAME)
	@printf "🗑️  $(CYAN)Executable(s) and archive(s) successfully deleted.$(RESET) 🗑️\n"

# -- Removes objects and executable then remakes all -- #
re : fclean all

# -- Avoid file-target name conflicts -- #
.PHONY: all bonus clean fclean re