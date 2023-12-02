# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 20:46:05 by akeryan           #+#    #+#              #
#    Updated: 2023/12/02 11:47:50 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

FLAGS = #-Wall -Wextra -Werror
LINKS = -Ilibft -Llibft \
    	-Iminilibx -Lminilibx \
		-L/usr/lib \
    	-lmlx -lft -lXext -lX11 -lm -lz

LIBFT_DIR = libft
MINILIBX_DIR = minilibx
SRC_DIR = src

all:  sublibs $(NAME)

SOURCES = $(wildcard $(SRC_DIR)/*.c)

$(NAME): 
	cc $(SOURCES) $(LINKS)  $^ -o $@

submodules:
	git submodule init
	git submodule update

minilibx_build:
	@$(MAKE) -C $(MINILIBX_DIR) -Wno-deprecated-declarations

libft_build:
	@$(MAKE) -C $(LIBFT_DIR)

bonus: sublibs 
	cc -D BONUS_AVAILABLE=1 $(SOURCES) $(LINKS) bonus.c -o $(NAME)

sublibs: submodules libft_build minilibx_build

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -fr $(BUILD_DIR)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: submodules sublibs libft_build minilibx_build bonus all clean fclean re
