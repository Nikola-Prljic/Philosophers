NAME	= philo
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

SRC		= main.c create_philos.c argv_to_int.c ft_atoi.c philo_ultis.c is_dead.c init_philos.c join_thread.c
OBJ		= $(SRC:.c=.o)
CC		= cc

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -lpthread $(OBJ) -o $(NAME)

debug: CFLAGS += -g
debug: re

clean:
			@$(RM) $(OBJ)
			@echo // objekt files removed //

fclean:		clean
			@$(RM) $(NAME)
			@echo // all files removed //

re:			fclean all
			@echo // Clenad and rebuild everything! //

.PHONY:		all clean fclean re debug