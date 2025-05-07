CC = gcc

all: main.exe child.exe

main.exe: main.c factorial.c factorial.h
	$(CC) main.c factorial.c -o main.exe

child.exe: child.c factorial.c factorial.h
	$(CC) child.c factorial.c -o child.exe

clean:
	del *.exe *.o