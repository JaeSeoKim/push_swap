# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 21:07:58 by jaeskim           #+#    #+#              #
#    Updated: 2021/03/20 14:45:20 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
NAME = $(PUSH_SWAP) $(CHECKER)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS := -g3 -fsanitize=address
ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

RM = rm
RMFLAGS = -f

INC_DIR = include
CFLAGS += -I $(INC_DIR)
SRC_DIR = src
OBJ_DIR = obj

# libft
LIBFT = libft.a
LIBFT_DIR = lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_INC_DIR)

HEADERS = $(wildcard $(INC_DIR)/*.h)

STACK_DIR = $(SRC_DIR)/stack
STACK_SRCS = $(wildcard $(STACK_DIR)/*.c)

CHECKER_DIR = $(SRC_DIR)/checker
CHECKER_SRCS = $(wildcard $(CHECKER_DIR)/*.c)

PUSH_SWAP_DIR = $(SRC_DIR)/push_swap
PUSH_SWAP_SRCS = $(wildcard $(PUSH_SWAP_DIR)/*.c)

CHECKER_SRCS := $(STACK_SRCS)
PUSH_SWAP_SRCS := $(STACK_SRCS)

vpath %.c \
	$(SRC_DIR) \
	$(STACK_DIR) \
	$(CHECKER_DIR)	\
	$(PUSH_SWAP_DIR)

CHECKER_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(CHECKER_SRCS:.c=.o)))
PUSH_SWAP_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(PUSH_SWAP_SRCS:.c=.o)))

# Color
CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF= \n$(LF)

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJS)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"

re : fclean all

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(LIBFT_FILE) | $(OBJ_DIR)
	@$(CC) $(CDEBUG) $(CFLAGS) -c $< -o $@
	@printf "$(LF)🚧 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(CHECKER) : $(LIBFT_FILE) $(HEADERS) $(CHECKER_OBJS) $(SRC_DIR)/checker.c
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@$(FG_TEXT)!\n"
	@$(CC) $(CDEBUG) $(CFLAGS) $(LIBFT_FLAGS) $(CHECKER_OBJS) $(SRC_DIR)/checker.c -o $@
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

$(PUSH_SWAP) : $(LIBFT_FILE) $(HEADERS) $(PUSH_SWAP_OBJS) $(SRC_DIR)/push_swap.c
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@$(FG_TEXT)!\n"
	@$(CC) $(CDEBUG) $(CFLAGS) $(LIBFT_FLAGS) $(PUSH_SWAP_OBJS) $(SRC_DIR)/push_swap.c -o $@
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

# libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFT)_clean :
	@make --no-print-directory -C $(LIBFT_DIR) clean

$(LIBFT)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean


.PHONY: all clean fclean re test \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean
