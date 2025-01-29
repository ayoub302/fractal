RESET			= "\033[0m"
PURPLE			= "\033[20m"
BISQUE			= "\033[21m"
SNOW			= "\033[22m"
IVORY			= "\033[23m"
GREEN			= "\033[24m"
RED				= "\033[25m"
WHITE			= "\033[26m"
GREY			= "\033[27m"

NAME			= fractol
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
OS				= $(shell uname)
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
LINKER			= -lft -L $(LIBFT_DIR)

INCLUDES_DIR	= includes
INCLUDES_FLAG	= -I$(INCLUDES_DIR) \
				  -I$(LIBFT_DIR) \

INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) \
				  $(LIBFT_DIR)/libft.h \

SRC_FILES		= main.c \
				  utils.c \
				  events.c \
				  render.c \
				  fractals.c \
				  mandelbox.c \
				  make_engine.c \

SRCS			= $(addprefix $(SRCS_DIR), $(SRC_FILES))

OBJS_DIR		= objs/
OBJS_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_FILES))

ifeq ($(OS), Linux)
	MLX_DIR		  = mlx_linux
	MLX			  = $(MLX_DIR)/libmlx.a
	LINKER		  += -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
	INCLUDES_FLAG += -I$(MLX_DIR)
else
	MLX_DIR		  = mlx_macos
	MLX			  = $(MLX_DIR)/libmlx.a
	LINKER		  += -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
	INCLUDES_FLAG += -I$(MLX_DIR)
endif


all : $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(LIBFT) :
	@echo $(PURPLE) "libft in process..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(PURPLE) "libft DONE" $(RESET)

$(MLX) :
	@echo $(WHITE) "MLX in process..." $(RESET)
	@$(MAKE) $(MLX_DIR)
	@echo $(PURPLE) "MLX DONE" $(RESET)

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

$(NAME) : $(OBJS) Makefile
	@echo $(PURPLE) "Compailing $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)
	@echo $(GREEN) " - Compiling FINISHED SUCCESFULLY" $(RESET)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJS_DIR)
	@echo $(IVORY) " - HAS Cleaned!" $(IVORY)

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) $(MLX_DIR) clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(RED) "FULL CLEANED!" $(RESET)

re: fclean all

.PHONY: 	ll clean fcleane re 
