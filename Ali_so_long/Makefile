SO_LONG_NAME	=	so_long

CC			=	cc
FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	.libft
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

SO_LONG_SRC	=	srcs/so_long.c

SO_LONG_OBJ	=	$(CLIENT_SRC:.c=.o)


.c.o:
	@printf "\r\033[K[so_long] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(FLAG) -c $< -o $@

all:	$(SO_LONG_NAME)

# bonus:

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(SO_LONG_NAME): $(LIBFT_LIB) $(SO_LONG_OBJ)
	@printf "\r\033[K[so_long] \033[0;32mLinking...\033[0m"
	@$(CC) $(SO_LONG_OBJ) $(LIBFT_LIB) -o $(SO_LONG_NAME) -lm 
	@printf "\r\033[K[so_long] \033[0;32mDone!\033[0m\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(SO_LONG_OBJ)
	@printf "[So_long] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(SO_LONG_NAME)
	@make fclean -C $(LIBFT_PATH)
	@printf "[So_long] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re