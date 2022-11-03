NAME = philo

SOURCES			=	./sources
INCLUDES		=	./includes
OBJECTS			=	./bin

SRCS = main.c \
       philo_error.c philo_parse.c\
	   philo_start.c philo_init.c philo_routine.c\
	   philo_utils.c philo_time.c

OBJS			=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CFLAGS			=	-Wall -Wextra -Werror #-g #-fsanitize=address
CC				=	clang
CINCLUDES		=	-I ${INCLUDES}
CDEPENDENCIES	=	-pthread -lpthread

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@echo "⏳ Compilation de ${notdir $<}. ⏳"
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME}

${NAME}: ${OBJS}
	@echo "⏳ Compilation de ${NAME}... ⏳"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${CDEPENDENCIES}

clean:
	@echo "🗑 Supression des fichiers binaires (.o)... 🗑"
	@rm -rf ${OBJECTS}

fclean: clean
	@echo "🗑 Supression des executables et librairies... 🗑"
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
