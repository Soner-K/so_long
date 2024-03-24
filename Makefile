NAME				=		so_long

LIBRARY_LIBFT		=		libft.a
LIBFT_DIR			=		libft
LIBFT				=		$(addprefix $(LIBFT_DIR)/, $(LIBRARY_LIBFT))

LIBRARY_MINILIBX	=		libmlx.a
MINILIBX_DIR		=		mlx
MINILIBX			=		$(addprefix $(MINILIBX_DIR)/, $(LIBRARY_MINILIBX))

LIBS				=		libs.h \
							macros.h \
							so_long.h \
							structs.h \
LIBS_DIR			=		includes
HEADERS				=		$(addprefix $(LIBS_DIR)/, $(LIBS))

FILES				=		test.c \
							create_map.c \
							parse_map.c \
							utils.c \
							flood_fill.c \
							set_map.c \
							utils2.c \
							events.c \

MAPS				:=		maps/bad_extension.txt \
							maps/empty.ber\
							maps/no_collectible.ber\
							maps/no_entry.ber\
							maps/no_exit.ber\
							maps/no_extension\
							maps/not_closed.ber\
							maps/one_line.ber\
							maps/only_wall.ber\
							maps/parsable.ber\
							maps/two_maps.ber\
							maps/uneven.ber\
							maps/wrong_characters.ber\
							maps/closed_entry.ber\
							maps/closed_exit.ber\


SRC_DIR				=		src
SRC					=		$(addprefix $(DIRECTORY)/, $(FILES))

OBJ_DIR				= 		obj
OBJ					=		$(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

CC					=		cc
CFLAGS				=		-Wall -Wextra -Werror -g3 -I includes

LENGTH				:=		$(shell xdpyinfo | grep dim | awk '{print $$2}' | awk -F x '{print $$1}')		
WIDTH				:=		$(shell xdpyinfo | grep dim | awk '{print $$2}' | awk -F x '{print $$2}')
IS_BONUS			:=		0
ifeq (bonus, $(filter bonus, $(MAKECMDGOALS)))
	IS_BONUS		=		1
endif
N_ASSETS			:=		9


FILES_SPRITES		:=		"$(shell find assets/xpm -type f)"

MACROS 				:=		-DLENGTH=$(LENGTH) -DWIDTH=$(WIDTH) -DASSETS="\$(FILES_SPRITES)\" -DBONUS=$(IS_BONUS)

all					:		$(NAME)


$(NAME)				:		$(OBJ_DIR) $(OBJ)
							@echo "\n"
							@echo "$(LYELLOW)Compiling libft...$(COLOR_END)"
							make -s -C $(LIBFT_DIR)
							@echo "$(LYELLOW)Compiling minilibx...$(COLOR_END)"
							make -s -C $(MINILIBX_DIR)
							@echo "$(GREEN)libft compiled !\n$(COLOR_END)"
							@echo "$(LYELLOW)Compiling so_long$(COLOR_END)"
							$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) -Lmlx -lX11 -lXext -lm -o $(NAME)
							@echo "$(LGREEN)so_long compiled ! Have fun\n$(COLOR_END)"

bonus				:		$(NAME)

$(OBJ_DIR)			:		
							mkdir -p $@

$(OBJ_DIR)/%.o		:		$(SRC_DIR)/%.c
							$(CC) $(CFLAGS) -c $< -o $@ $(MACROS) 
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
							@rm -f out.txt

re					:		fclean all

files_mem			:		$(NAME) $(MAPS)
							@rm -f out.txt
							@echo "MAPS = $(MAPS)"
							@echo "$(BLUE)Running valgrind on each map...$(COLOR_END)"
							@for map in $(MAPS); do \
								valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./so_long $$map > /dev/null 2>> out.txt; \
							done
							@echo "$(LBLUE)Done ! Output can be found in out.txt$(COLOR_END)"

files_out			:		$(NAME) $(MAPS)
							@echo "MAPS = $(MAPS)"
							@echo "$(BLUE)Running the program on each map...$(COLOR_END)"
							@for map in $(MAPS); do \
								./so_long $$map; \
							done
							@echo "$(LBLUE)Done !$(COLOR_END)"

.PHONY				: 		all clean fclean re files_mem files_out


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