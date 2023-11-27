# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 20:46:05 by akeryan           #+#    #+#              #
#    Updated: 2023/11/27 22:37:25 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

FLAGS = #-Wall -Wextra -Werror
LINKS = -I ./libft -L ./libft \
    	-I ./minilibx -L ./minilibx \
    	-l mlx -l ft -framework OpenGL -framework Appkit

LIBFT_DIR = libft
BUILD_DIR = build
SRC_DIR = src
MINILIBX_DIR = minilibx

all: submodules libft_build minilibx_build $(NAME)

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

$(BUILD_DIR)/%.o: | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	cc $(FLAGS) $(LINKS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	cc -c $(FLAGS) -c -o $@ $< 

submodules:
	git submodule init
	git submodule update

minilibx_build:
	@$(MAKE) -C $(MINILIBX_DIR) CFLAGS="$(FLAGS) -Wno-deprecated-declarations"

libft_build:
	@$(MAKE) -C $(LIBFT_DIR)

bonus: submodules minilibx_build libft_build  $(SOURCES) 
	cc -D BONUS_AVAILABLE=1 $(FLAGS) $(LINKS) bonus.c $(SOURCES) -o fdf 

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -f $(OBJECTS)
	rm -fr $(BUILD_DIR)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: submodules libft_build minilibx_build bonus all clean fclean re
