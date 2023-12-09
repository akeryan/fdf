# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 20:46:05 by akeryan           #+#    #+#              #
#    Updated: 2023/12/09 17:36:41 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

FLAGS =  -Wall -Wextra -Werror 
LINKS = -Ilibft -Llibft \
    	-Iminilibx -Lminilibx \
		-L/usr/lib \
    	-lmlx -lft -lm -lz \
		-framework OpenGL -framework AppKit

CC = cc

LIBFT_DIR = libft
MINILIBX_DIR = minilibx
SRC_DIR = src

all: $(NAME)

SOURCES = $(wildcard $(SRC_DIR)/*.c)

$(NAME): sublibs 
	if [ ! -f fdf ]; then \
		cc $(SOURCES) $(FLAGS) $(LINKS) -o $@; \
	fi

submodules:
	git submodule init
	git submodule update

minilibx_build:
	if [ ! -f $(MINILIBX_DIR)/libmlx.a ]; then \
		/Library/Developer/CommandLineTools/usr/bin/make -C $(MINILIBX_DIR) CFLAGS=-Wno-deprecated; \
	fi

libft_build:
	if [ ! -f $(LIBFT_DIR)/libft.a ]; then \
		/Library/Developer/CommandLineTools/usr/bin/make -C $(LIBFT_DIR); \
	fi

bonus: sublibs 
	$(CC) -D BONUS_AVAILABLE=1 $(SOURCES) $(FLAGS) $(LINKS) bonus.c -o $(NAME)

sublibs: submodules libft_build minilibx_build

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -fr $(BUILD_DIR)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MINILIBX_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: submodules sublibs libft_build minilibx_build bonus all clean fclean re
