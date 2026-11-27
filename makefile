OBJECTS = main.o loader.o
CFLAGS = -Wall -g -c -Iinclude
CC = gcc
EXE = build/TIBasicM0
TEST_BUILDS = tests/test_loader.out

#Compile all
default: all
all: $(OBJECTS) 
	$(CC) -o $(EXE) $(OBJECTS)

main.o: src/main.c
	$(CC) $(CFLAGS) -o main.o src/main.c


loader.o: src/loader.c
	$(CC) $(CFLAGS) -o loader.o src/loader.c

clean:
	rm *.o $(OBJECTS) $(EXE) $(TEST_BUILDS)

# test cases
# Test Parser src
test_loader: loader.o test_loader.o
	$(CC) loader.o test_loader.o -o tests/test_loader.out

loader.o: src/loader.c
	$(CC) $(CFLAGS) -o loader.o src/loader.c

test_loader.o: tests/test_loader.c
	$(CC) $(CFLAGS) -o test_loader.o tests/test_loader.c
