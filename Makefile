default: hello

hello:  functions.o linkedList.o
	gcc -o hello hello.c functions.o linkedList.o

linkedList.o:  linkedList.c linkedList.h
	gcc -c linkedList.c 

functions.o:  functions.c functions.h 
	gcc -c functions.c

clean:
	rm -f hello *.o
