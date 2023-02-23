NAME	:= fractol
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -O3

SRCS	:= src/pixel_input.c src/color.c src/fractol.c src/julia.c src/additional_funcs.c src/burningship.c src/mandelbrot.c 

OBJS	:= $(SRCS:.c=.o)

%.o: %.c
	@ $(CC) -c $(CFLAGS) $< -o ${<:.c=.o}

RM		    := rm -f

$(NAME): $(OBJS)
	@ echo "\033[1;31mcompiling"
	@ $(MAKE) -C mlx all >/dev/null 2>&1
	@ cp ./mlx/libmlx.a .
	@ echo "\033[1;31m		..."
	@ $(MAKE) -C libft all >/dev/null 2>&1
	@ cp ./libft/libft.a .
	@ echo "\033[1;33m			..."
	@ $(CC) $(CFLAGS) -Ofast -o $(NAME) $(OBJS) libft.a libmlx.a -lm -framework OpenGL -framework AppKit
	@ echo "\033[1;32m				finished compiling."
	@ echo " "
	@ echo "\033[1;34mUse ./fractol Mandelbrot || Julia || Burning ship to run the progam"

all:		${NAME}


clean:
	@ ${RM} $(OBJS)
	@ make clean -C ./libft
	@ make clean -C ./mlx

fclean:	clean
	@ ${RM} ${NAME}
	@ make fclean -C ./libft
	@ ${RM} libmlx.a
	@ ${RM} libft.a

re:			fclean all

fract: all
	@ echo " "
	@ make clean

.PHONY:		all clean fclean re fract
