
.PHONY: clean run

all: main.o test.o
	gcc -o ./bin/ctest  main.o src/test.o 

main.o: main.c
	gcc -c main.c -I./include

test.o: include/mytest/test.h src/test.c
	gcc -c src/test.c  -o src/test.o -I./include

run: all
	./bin/ctest

clean:
	rm -rf  *.o src/*o


