default: hello

hello:  functions.o linkedList.o doublyLinkedList.o
	gcc -g -o hello hello.c functions.o linkedList.o doublyLinkedList.o

linkedList.o:  linkedList.c linkedList.h
	gcc -g -c linkedList.c 

doublyLinkedList.o: doublyLinkedList.c doublyLinkedList.h
	gcc -g -c doublyLinkedList.c

functions.o:  functions.c functions.h 
	gcc -g -c functions.c

clean:
	rm -f hello *.o
