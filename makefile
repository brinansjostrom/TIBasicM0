OBJECTS = main.o
CFLAGS = -Wall -g -c
CC = gcc
EXE = TIBasicM0

#Compile
default: all
all: $(OBJECTS) 
	$(CC) -o $(EXE) $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -o main.o main.c

clean:
	rm *.o TIBasicM0
