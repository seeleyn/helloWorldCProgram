default: hello

hello:  functions.o
	gcc -o hello hello.c functions.o

functions.o:  functions.c functions.h 
	gcc -c functions.c


clean:
	rm -f hello *.o
