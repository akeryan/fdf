NAME = fdf 

SOURCES = main.c   
LIBFT_DIR = libft
BUILD_DIR = build
MINILIBX_DIR = minilibx
INCLUDE = fdf.h

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = #-Wall -Wextra -Werror
LINKS = -I ./libft -L ./libft \
    	-I ./minilibx -L ./minilibx \
    	-l mlx -l ft -framework OpenGL -framework Appkit

all: submodules libft_build minilibx_build $(NAME)

%.o: %.c
	cc -c $(FLAGS) $(LINKS) $< -o $@

$(NAME): $(OBJECTS) $(INCLUDE) 
	cc $(SOURCES) $(FLAGS) $(LINKS) -o $(NAME) 

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
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re