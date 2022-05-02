CC=g++
EXECS=dashanan dsninput

all: ${EXECS} 

dashanan: dsninput
	${CC} -Llib/ -o bin/dashanan src/main.cpp -ldsninput

dsninput:
	${CC} -fPIC -c src/dsninput.cpp -o lib/dsninput.o
	${CC} -fPIC -shared -o lib/libdsninput.so lib/dsninput.o

clean:
	rm -rf ${EXECS}