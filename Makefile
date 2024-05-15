# MINI_RT_PROJECT_MAKEFILE
include libft/.make

NAME			:=	miniRT

CC				:=	cc
CFLAGS			:=	-g -Wall -Wextra -Werror

# PARSING
PARSING_NAME	:=	parsing.c minirt_atod.c args_processing.c minirt_atoi.c range_check.c
PARSING_PATH	:=	parsing/
PARSING_I_NAME	:=	init_ambient_light.c init_camera.c init_light.c init_sphere.c init_plane.c \
					init_cylinder.c init_element.c init_struct.c init_screen.c init_cone.c \
					init_checkerboard.c init_bump.c
PARSING_I_PATH	:=	parsing/inits/
PARSING			:=	$(addprefix $(PARSING_PATH), $(PARSING_NAME)) \
					$(addprefix $(PARSING_I_PATH), $(PARSING_I_NAME))

# CLEANING
CLEANING_NAME	:=	cleaner.c error_throw.c
CLEANING_PATH	:=	cleaning/
CLEANING		:=	$(addprefix $(CLEANING_PATH), $(CLEANING_NAME))

# RT
RT_NAME			:=	hit_plane.c hit_sphere.c hit_cylin.c hit_cylin_utils.c viewport.c transform_scene.c make_norm_vec.c \
					lighting.c color.c blur.c set_texture.c set_bump.c
RT_PATH			:=	rt/
RT				:=	$(addprefix $(RT_PATH), $(RT_NAME))

# LIN_ALG
LIN_ALG_NAME	:=	vec_fun.c vec_utils.c rotation_xyz.c dot_cross.c
LIN_ALG_PATH	:=	lin_alg/
LIN_ALG			:=	$(addprefix $(LIN_ALG_PATH), $(LIN_ALG_NAME))

# SOURCE_FILES
SRCS			:=	main.c $(PARSING) $(CLEANING) $(RT) $(LIN_ALG)
SRCS_PATH		:=	srcs/

# OBJECT_FILES
OBJS_PATH		:=	objs/
OBJS			:=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

# LIBFT_LIBRARY
LIBFT_PATH		:=	$(LIBFT_PATH)
LIBFT_SOURSES	:=	$(addprefix $(LIBFT_PATH), $(LIBFT_SOURSES))
LIBFT			:=	libft/libft.a

# HEADERS AND EXTERNAL LIBRARIES
MINIRT_H		:=	includes/
HEADERS			:=	$(LIBFT_PATH)libft.h $(MINIRT_H)defines.h $(MINIRT_H)minirt.h $(MINIRT_H)structs.h
INCLUDES		:=	$(addprefix -I , $(HEADERS))
LIBMLX			:=	./lib/MLX42
MLX				:=	./lib/MLX42/build/libmlx42.a
LIBMLX_DIR		:=	$(LIBMLX)/include

HEAD_DIR		:=	-I./includes -I$(LIBMLX)/include  -I./libft 

# MLX FOR MacOS (M1 and later)
# LIBS			:=	-lft -L $(LIBFT_PATH) -L$(LIBMLX)/build -lmlx42 -L"/opt/homebrew/opt/glfw/lib/" \
# 					-lglfw -framework OpenGL -framework AppKit

# MLX FOR THE SCHOOL MACs 
LIBS			:=	-lft -L $(LIBFT_PATH) -L$(LIBMLX)/build -lmlx42 -L"/Users/$(USER)/.brew/opt/glfw/lib" \
					-lglfw -framework OpenGL -framework AppKit

# LINUX
# GLFW_DIR		:=	~/.brew/opt/glfw/lib
# LIBS			:=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -L$(GLFW_DIR) -pthread -lm

# LOADING PROGRESS BAR INIT
TOTAL_OBJS		:=	$(words $(OBJS))
COMPILED_OBJS	:=	0
MSG_PRINTED 	:=	false

# RULES
all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS_PATH) $(OBJS) $(HEADERS)
	@cc $(CFLAGS) $(OBJS) $(LIBS) $(HEAD_DIR) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)\n\n$(NAME) created successfully!$(EC)"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)$(PARSING_PATH)
	@mkdir -p $(OBJS_PATH)$(PARSING_I_PATH)
	@mkdir -p $(OBJS_PATH)$(CLEANING_PATH)
	@mkdir -p $(OBJS_PATH)$(LIN_ALG_PATH)
	@mkdir -p $(OBJS_PATH)$(RT_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(HEAD_DIR) -c $< -o $@ 
	@$(call progress,"miniRT")

$(LIBFT): $(LIBFT_SOURSES)
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@echo "$(CYAN)\nMLX compilation started\n$(EC)"
	@git submodule init
	@git submodule update
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(CYAN)\nMLX compilation completed$(EC)"
	@echo "$(GREEN)Library 'libmlx42.a' created successfully$(EC)"

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@rm -rf $(OBJS_PATH)
	@rm -rf $(LIBMLX)/build	
	@echo "$(RED)Object files successfully removed!$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(RED)\nFull clean up completed successfully!$(EC)"

re: fclean all

.PHONY: all clean fclean re
