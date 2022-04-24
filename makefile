CC=g++
EXECS=bin/dashanan

all: dashanan

dashanan:
	${CC} -o bin/dashanan src/main.cpp

clean:
	rm -rf ${EXECS}