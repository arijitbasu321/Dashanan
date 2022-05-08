CC=g++
EXECS=dashanan dsninput dsnutilities dsnsearch

all: ${EXECS} 

dashanan: dsninput dsnutilities dsnsearch
	${CC} -Llib/ -o bin/dashanan src/main.cpp -ldsninput -ldsnutilities -ldsnsearch

dsninput:
	${CC} -fPIC -c src/dsninput.cpp -o lib/dsninput.o
	${CC} -fPIC -shared -o lib/libdsninput.so lib/dsninput.o

dsnutilities:
	${CC} -fPIC -c src/dsnutilities.cpp -o lib/dsnutilities.o
	${CC} -fPIC -shared -o lib/libdsnutilities.so lib/dsnutilities.o

dsnsearch:
	${CC} -fPIC -c src/dsnsearch.cpp -o lib/dsnsearch.o
	${CC} -fPIC -shared -o lib/libdsnsearch.so lib/dsnsearch.o

clean:
	rm -rf ${EXECS}