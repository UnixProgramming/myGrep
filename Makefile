mygrep: main.o myMemory.o myMatch.o myError.o
	gcc -o mygrep main.o myMemory.o myMatch.o myError.o

myMatch.o: myMatch.c
	gcc -c myMatch.c

myMemory.o: myMemory.c
	gcc -c myMemory.c

myError.o: myError.c
	gcc -c myError.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o
