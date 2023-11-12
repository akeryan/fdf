NAME = fdf 

SOURCES = main.c   
LIBFT_DIR = libft
BUILD_DIR = build
MINILIBX_DIR = minilibx

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = #-Wall -Wextra -Werror
LINKS = -I ./libft -L ./libft \
    	-I ./minilibx -L ./minilibx \
    	-l mlx -l ft -framework OpenGL -framework Appkit

all: libft_build minilibx_build $(NAME)

%.o: %.c
	cc -c $(FLAGS) $(LINKS) $< -o $@

$(NAME): $(OBJECTS)
	cc $(SOURCES) $(FLAGS) $(LINKS) -o $(NAME) 

minilibx_build:
	@$(MAKE) -C $(MINILIBX_DIR)

libft_build:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -f $(OBJECTS)
	
fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MINILIBX_DIR) clean
	rm -f $(NAME)