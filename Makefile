RED		=	\033[31m
GRE		=	\033[32m
BLU		=	\033[36m
YEL		=	\033[33m
EOC		=	\033[0m
BEI		=	\033[38;5;223m

DEF		=	\033[0m
BOLD	=	\033[1m
CUR		=	\033[3m
UL		=	\033[4m
UP		=	\033[A

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
# ---------------------------------------------------------------------------- #

SRCS_COUNT = 0
SRCS_TOT = ${shell find ./sources/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR =  ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

${OBJECTS}/%.o: ${SOURCES}/%.c
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}
	@echo ""
	@echo "\r\033[K -> Compilation de ""$(YEL)${notdir $<}$(EOC). ⏳"
	@printf "   ${BEI}[%-23.${BAR}s] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}${UP}"

all: start ${NAME}

start:
	@if [ ! -e "bin" ]; then \
		echo "🚀 Début de la compilation de $(BLU)${NAME} 🚀$(EOC)"; \
	else \
		echo "make: Nothing to be done for \`all'."; \
	fi

${NAME}: ${OBJS}
	@clear
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@echo "$(GRE)✅ Compilation terminée.$(EOC)"

clean:
	@echo "🗑  $(RED)Supression des fichiers binaires (.o).$(EOC) 🗑"
	@rm -rf ${OBJECTS}

fclean: clean
	@echo "🗑  $(RED)Supression des executables et librairies.$(EOC) 🗑"
	@rm -f ${NAME}
	@clear

re: fclean all

.PHONY:	all clean fclean re
