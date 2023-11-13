NAME = fdf 

FLAGS = #-Wall -Wextra -Werror
LINKS = -I ./libft -L ./libft \
    	-I ./minilibx -L ./minilibx \
    	-l mlx -l ft -framework OpenGL -framework Appkit

LIBFT_DIR = libft
BUILD_DIR = build
SRC_DIR = src
MINILIBX_DIR = minilibx
INCLUDE = fdf.h

all: submodules libft_build minilibx_build $(NAME)

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

$(BUILD_DIR)/%.o: | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#%.o: %.c
#	cc -c $(FLAGS) $(LINKS) $< -o $@
$(NAME): $(OBJECTS) $(INCLUDE) 
	cc $(FLAGS) $(LINKS) $(OBJECTS) -o $(NAME) 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) | $(BUILD_DIR)
	cc -c $(FLAGS) $(LINKS) -c -o $@ $< 

submodules:
	git submodule init
	git submodule update

minilibx_build:
	@$(MAKE) -C $(MINILIBX_DIR) CFLAGS="$(FLAGS) -Wno-deprecated-declarations"

libft_build:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -f $(OBJECTS)
	rm -fr $(BUILD_DIR)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re