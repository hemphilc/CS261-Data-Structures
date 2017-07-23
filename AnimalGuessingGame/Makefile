all: prog

prog: animalbst.o compare.o
	gcc -g -Wall -std=c99 -o prog animalbst.o compare.o

compare.o: compare.c
	gcc -g -Wall -std=c99 -c compare1.c
		
animalbst.o: animalbst.c animalbst.h
	gcc -g -Wall -std=c99 -c animalbst.c

clean:	
	rm animalbst.o
	rm compare.o
	rm prog