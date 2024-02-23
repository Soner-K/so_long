NAME				=		so_long

LIBRARY_LIBFT		=		libft.a
LIBFT_DIR			=		libft
LIBFT				=		$(addprefix $(LIBFT_DIR)/, $(LIBRARY_LIBFT))

LIBRARY_MINILIBX	=		libmlx.a
MINILIBX_DIR		=		mlx
MINILIBX			=		$(addprefix $(MINILIBX_DIR)/, $(LIBRARY_MINILIBX))

FILES				=		test.c \

SRC_DIR				=		src
SRC					=		$(addprefix $(DIRECTORY)/, $(FILES))

OBJ_DIR				= 		obj
OBJ					=		$(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

CC					=		cc
CFLAGS				=		-Wall -Wextra -Werror -g3 -I includes

all					:		$(NAME)


$(NAME)				:		$(OBJ_DIR) $(OBJ)
							@echo "\n"
							@echo "$(LYELLOW)Compiling libft...$(COLOR_END)"
							make -s -C $(LIBFT_DIR)
							@echo "$(LYELLOW)Compiling minilibx...$(COLOR_END)"
							make -s -C $(MINILIBX_DIR)
							@echo "$(GREEN)libft compiled !\n$(COLOR_END)"
							@echo "$(LYELLOW)Compiling so_long$(COLOR_END)"
							$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -L $(MINILIBX)  -o $(NAME)
							@echo "$(LGREEN)so_long compiled ! Have fun\n$(COLOR_END)"

$(OBJ_DIR)			:		
							mkdir -p $@

$(OBJ_DIR)/%.o		:		$(SRC_DIR)/%.c
							$(CC) $(CFLAGS) -c $< -o $@
							@printf "$(YELLOW)%s created $(FACE_ESCUZME)$(COLOR_END)\n" $@

clean				:	
							@rm -rf $(OBJ_DIR)
							@echo "$(BLUE)Removing object files... $(COLOR_END)"
							@make -s -C libft clean
							@rm -rf mlx/obj
							@sleep 0.2
							@echo "$(LBLUE)Object files removed $(COLOR_END)$(BYE)"

fclean				:		clean
							@echo "$(YELLOW) *******************************$(COLOR_END)"
							@echo "$(BLUE)Removing so_long's executable $(COLOR_END) $(FACE_SHAKING)"
							@rm -f $(NAME)
							@make -s -C libft fclean
							@make -s -C mlx clean
							@echo "$(LBLUE)So_long's executable removed $(COLOR_END) $(BYE)"

re					:		fclean all

.PHONY				: 		all clean fclean re




LGREEN				=	\033[1;32m
GREEN				=	\033[32m

LBLUE				=	\033[1;34m
BLUE				=	\033[34m

RED					=	\033[31m

LYELLOW				=	\033[1;33m
YELLOW				=	\033[33m

COLOR_END			=	\033[0m

FACE_ESCUZME		=	🤓
BYE					=	🙋