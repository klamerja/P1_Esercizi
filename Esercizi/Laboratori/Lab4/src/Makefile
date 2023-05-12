LIBS_DIR = ../lib
CC = gcc
FLAGS = -O0 -L${LIBS_DIR} -I${LIBS_DIR} -lbasic #-g per debug

ARCHIVES = ${LIBS_DIR}/libbasic.a

%.o: %.c
	${CC} -g -O0 -o $@ -c $< -Wall

HEADERS = ${shell find ${LIBS_DIR}/basic/ -name '*.h'}
SOURCES = ${shell find ${LIBS_DIR}/basic/ -name '*.c'}
OBJS = ${SOURCES:.c=.o}

${LIBS_DIR}/libbasic.a: ${HEADERS} ${OBJS}
	ar rcs ${LIBS_DIR}/libbasic.a ${OBJS}

EX_LIST = ${wildcard */}
COMMANDS = ${EX_LIST:%/=%}
EXECS = ${EX_LIST:%/=%.out}

.PHONY: ${COMMANDS}
${COMMANDS}: % : %.out

.SECONDEXPANSION:
$(EXECS): %.out : ${ARCHIVES} $$(wildcard %/*.c)
	${CC} -o $@ $*/*.c ${FLAGS}

clean:
	find ../ -name '*.o' -delete
	find ../ -name '*.a' -delete
	rm ${EXECS}
