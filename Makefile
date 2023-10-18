NAME = fractol
FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -Ofast
SRC =	main.c libft_utils.c inits.c my_pixel_put.c \
		julia.c mandelbrot.c lets_draw.c events.c \
		events2.c errors.c atoi_d.c my_fract.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

#$(NAME) : $(OBJ)
#	@gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@
$(NAME) : $(OBJ)
	@gcc $(FLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : re fclean clean all