default: hello

hello:  functions.o linkedList.o doublyLinkedList.o
	gcc -o hello hello.c functions.o linkedList.o doublyLinkedList.o

linkedList.o:  linkedList.c linkedList.h
	gcc -c linkedList.c 

doublyLinkedList.o: doublyLinkedList.c doublyLinkedList.h
	gcc -c doublyLinkedList.c

functions.o:  functions.c functions.h 
	gcc -c functions.c

clean:
	rm -f hello *.o
